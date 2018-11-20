#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>

//Node Structure for the Binary Tree.
struct Node
{
    unsigned long long int key;
    struct Node* lchild;
    struct Node* rchild;
};

//Class Structure for Binary Tree using Struture Node.
class Binary_Tree
{
    public:

        Binary_Tree();
        Binary_Tree(int);
        struct Node* getRoot() const;
        int getHeight(struct Node* node);                            //To return the height of the Binary Tree.

        struct Node* newNode(unsigned long long int);
        void insert(unsigned long long  int key);

        void levelOrderTraversal(struct Node* root) const;

        virtual ~Binary_Tree();

    protected:

    private:
        struct Node* root;
        struct Node* currentRoot;
        std::queue <struct Node*> nodeQueue;
        int count;
        void insertKey(unsigned long long int);                       //Actual insert function to insert Hash values into the tree.
};

#endif // BINARY_TREE_H
