#include "Binary_Tree.h"
#include <iostream>
#include <queue>

using namespace std;

//Default Constructor to initialize Master hash with '1'.
Binary_Tree::Binary_Tree()
{
    this->root = newNode(1);
    this->count = 1;
    //ctor
}

//Overloaded Constructor to temporarily initialize the Master Hash before calculating.
Binary_Tree::Binary_Tree(int value)
{
    this->root = newNode(value);
    this->count = 1;
    nodeQueue.push(root);
    currentRoot = nodeQueue.front();
}

//Function to create a new node in the Merkle Tree.
struct Node* Binary_Tree::newNode(unsigned long long  int item)
{
    struct Node *temp =  new struct Node;
    temp->key = item;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

//Getter function to return the root pointer of the Current Binary Tree.
struct Node* Binary_Tree::getRoot() const
{
    return this->root;
}

void Binary_Tree::insert(unsigned long long  int key)
{
    insertKey(key);
}

//Inserts key(Calculated Hash) into the Merkle Tree.
void Binary_Tree::insertKey(unsigned long long  int key)
{
   if(count%2)
    {
        currentRoot->lchild = newNode(key);
        nodeQueue.push(currentRoot->lchild);
    }
    else
    {
        currentRoot->rchild = newNode(key);
        nodeQueue.push(currentRoot->rchild);
        nodeQueue.pop();
        currentRoot=nodeQueue.front();
    }
    count++;
}

//Standard levelOrderTraversal implementation using queue.
void Binary_Tree::levelOrderTraversal(struct Node* root) const
{
    std::queue <struct Node*> nodeQueue;
    struct Node *temp = root;
    int nodeCount = 1;
    while(temp)
    {
        std::cout<<endl;
        std::cout<<nodeCount++<<" "<<temp->key<<' ';
        if(temp->lchild != NULL)
        {
            nodeQueue.push(temp->lchild);
        }
        if(temp->rchild != NULL)
        {
            nodeQueue.push(temp->rchild);
        }
        temp=nodeQueue.front();
        nodeQueue.pop();
    }
}

Binary_Tree::~Binary_Tree()
{
    //dtor
}
