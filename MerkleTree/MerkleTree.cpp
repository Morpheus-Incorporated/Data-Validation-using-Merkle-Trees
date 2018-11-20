#include "Merkle_Tree.h"
#include <iostream>
#include <cstring>
#include <string>

// String to unsigned int char array converter.
char* string_to_uschp (std::string s);

using namespace std;

Merkle_Tree::Merkle_Tree() : Binary_Tree()
{
    //ctor
}

Merkle_Tree::Merkle_Tree(int value) : Binary_Tree(value)
{
    //overloaded_ctor
}

/*
  Inserts the Hash values of the respective Data nodes and constructs the Tree from Leaf to
  the root and also generates the Master Hash iteratively.
*/
unsigned long long int* Merkle_Tree::createMerkleTree(char** msgPackets,int splitSize)
{
    int no_of_strings = splitSize;
    int no_of_nodes = (2 * no_of_strings) ;
    unsigned long long int *nodeArray = new unsigned long long int [no_of_nodes + 1];

    for(int i=1 ; i <= (no_of_nodes - (no_of_nodes/2) )- 1 ;i++ )
        nodeArray[i] = i+1;
    int indexCounter = 0;
    for(int i = (no_of_nodes - (no_of_nodes/2) )- 1 ; i < no_of_nodes - 1 ; i++ )
    {
        nodeArray[i] = hashGenerator( msgPackets[indexCounter++] );
    }
    for(int i = 1; i < no_of_nodes - 1; i++ )
    {
        insert(nodeArray[i]);
    }
    generateMasterHash( getRoot() );                            //Generates the Master Hash from leaves recursively.
    unsigned long long int *hashArray = new unsigned long long int [no_of_nodes + 1];
    struct Node *ptr = getRoot();
    std::queue <struct Node*> nodeQueue;                        // Used for inserting nodes into the Merkle Tree.
    indexCounter = 1;
    while(ptr)
    {
        hashArray[indexCounter++] = ptr->key;
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
    /*for(int i =1 ; i < no_of_nodes; i++)
        cout<<hashArray[i]<<endl;
    */
    return hashArray;
}

// A Getter function to retrieve the Master Hash from the Merkle Tree.
unsigned long long int Merkle_Tree::getMasterRoot() const
{
    return getRoot()->key;
}

// A simple Hash Generator which works on left shifting logic for basic unsigned integer values.
unsigned long long int Merkle_Tree::hashGenerator(char *str)
{
    unsigned long hash = 5381;
    unsigned long int c;

    while ( (c = *str++) )
        hash = ( (hash << 5) + hash ) + c; /* hash * 33 + c */

    return hash;
}

// Generates the Master hash from the leaf nodes which can be used to verify the blocks in the chain.
void Merkle_Tree::generateMasterHash(struct Node* ptr)
{
    if(ptr->key > 100)
        return;
    if(ptr->lchild != NULL)
        generateMasterHash(ptr->lchild);
    if(ptr->rchild != NULL)
        generateMasterHash(ptr->rchild);
    ptr->key = hashGenerator( string_to_uschp( to_string( (ptr->lchild->key) + (ptr->rchild->key) ) ) );

    // Terminating condition to check and stop once the root has been reached.
    if(ptr == getRoot() )
        return ;
}

Merkle_Tree::~Merkle_Tree()
{
    //dtor
}

// Simple helper function to convert string into unsigned int char array.
char* string_to_uschp (string s)
{
    int n = s.length();
    char*char_array = new char[n+1];
    strcpy(char_array, s.c_str());
    return char_array;
}
