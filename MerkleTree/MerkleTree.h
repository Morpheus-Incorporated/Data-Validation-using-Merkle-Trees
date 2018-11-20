#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include "../Binary_Tree/Binary_Tree.h"

class Merkle_Tree : public Binary_Tree
{
    public:
        Merkle_Tree();
        Merkle_Tree(int);
        unsigned long long int getMasterRoot() const;
        unsigned long long int* createMerkleTree(char**,int);             // Constructs the Tree from Leaf to the root and also generates the Master Hash iteratively.
        unsigned long long int hashGenerator(char *str);                  // Hash Generator function to generate Hashes for the Data Nodes.
        void generateMasterHash(struct Node*);
        virtual ~Merkle_Tree();

    protected:

    private:

};

#endif // MERKLE_TREE_H
