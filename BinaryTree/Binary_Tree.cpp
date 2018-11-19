#include "Binary_Tree.h"
#include <iostream>
#include <queue>

using namespace std;

Binary_Tree::Binary_Tree()
{
    this->root = NULL;
    this->count = 1;
    //ctor
}

Binary_Tree::Binary_Tree(int value)
{
    root = newNode(value);
    count = 1;
    q.push(root);
    currentRoot = q.front();
}

struct Node* Binary_Tree::newNode(unsigned long long  int item)
{
    struct Node *temp =  new struct Node;
    temp->key = item;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

struct Node* Binary_Tree::get_Root() const
{
    return this->root;
}

void Binary_Tree::insert(unsigned long long  int key)
{
    insertKey(key);
}

void Binary_Tree::insertKey(unsigned long long  int key)
{
   if(count%2)
    {
        currentRoot->lchild = newNode(key);
        q.push(currentRoot->lchild);
    }
    else
    {
        currentRoot->rchild = newNode(key);
        q.push(currentRoot->rchild);
        q.pop();
        currentRoot=q.front();
    }
    count++;
}

void Binary_Tree::levelOrderTraversal(struct Node* root) const
{
    struct Node *temp = root;
    std::queue <struct Node*> q;
    int i = 1;
    while(temp)
    {
        std::cout<<endl;
        std::cout<<i++<<" "<<temp->key<<' ';
        if(temp->lchild != NULL)
        {
            q.push(temp->lchild);
        }
        if(temp->rchild != NULL)
        {
            q.push(temp->rchild);
        }
        temp=q.front();
        q.pop();
    }
}

Binary_Tree::~Binary_Tree()
{
    //dtor
}
