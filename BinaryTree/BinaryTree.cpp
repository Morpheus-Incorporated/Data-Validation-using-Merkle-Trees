#include "BinaryTree.hpp"
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
    struct Node *ptr =  new struct Node;
    ptr->key = item;
    ptr->lchild = ptr->rchild = NULL;
    return ptr;
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
    struct Node *ptr = root;
    int nodeCount = 1;
    while(ptr)
    {
        std::cout<<endl;
        std::cout<<nodeCount++<<" "<<ptr->key<<' ';
        if(ptr->lchild != NULL)
        {
            nodeQueue.push(ptr->lchild);
        }
        if(ptr->rchild != NULL)
        {
            nodeQueue.push(ptr->rchild);
        }
        ptr=nodeQueue.front();
        nodeQueue.pop();
    }
}

Binary_Tree::~Binary_Tree()
{
    //dtor
}
