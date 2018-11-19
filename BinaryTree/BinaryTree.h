#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>

struct Node
{
    unsigned long long int key;
    struct Node* lchild;
    struct Node* rchild;
};

class Binary_Tree
{
    public:

        Binary_Tree();
        Binary_Tree(int);
        struct Node* get_Root() const;
        int getHeight(struct Node* node);

        struct Node* newNode(unsigned long long int);
        void insert(unsigned long long  int key);

        void levelOrderTraversal(struct Node* root) const;

        virtual ~Binary_Tree();

    protected:

    private:
        struct Node* root;
        struct Node* currentRoot;
        int count;
        std::queue<struct Node*> q;
        void insertKey(unsigned long long int);
};

#endif // BINARY_TREE_H
