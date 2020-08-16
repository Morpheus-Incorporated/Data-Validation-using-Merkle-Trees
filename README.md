# Data-Validation-using-Merkle-Trees

[![CodeFactor](https://www.codefactor.io/repository/github/alien-inc/data-validation-using-merkle-trees/badge)](https://www.codefactor.io/repository/github/alien-inc/data-validation-using-merkle-trees)
![Forks](https://img.shields.io/github/forks/Alien-Inc/Data-Validation-using-Merkle-Trees)
![Stars](https://img.shields.io/github/stars/Alien-Inc/Data-Validation-using-Merkle-Trees)
![Issues](https://img.shields.io/github/issues/Alien-Inc/Data-Validation-using-Merkle-Trees)
![License](https://img.shields.io/github/license/Alien-Inc/Data-Validation-using-Merkle-Trees)


## Intro

A Menu Driven Program used to validate strings of messages(Data) for its Integrity with the help of implementation of a specific Hash-Tree(Merkle-Trees).

## Concept 

### Understanding Merkle Tree

Merkle tree allows us to mutliplex a number of transactions in a single block of the ledger. Every leaf node of the tree is representative of a single transaction. Whereas all other nodes are hashes of their children.

### What is the benefit of this ?

The transaction block will need to store only the root of a Merkle Tree. The purpose that SPV states is that any client who is transacting on the chain can just store the path of hashes from the root to their transaction instead of storing the whole ledger, which can be very large in size.

### We do not trust the block ?

Once your transaction is processed, you can verify that it has been added to the ledger by tracing the path from root provided in the block to the leaf node that is your transaction. So you verify to ensure if your transaction was actually processed or not.

### Can it be faked ?

No. Once a block is accepted onto the main chain, which is usually the addition of about 5 or 6 more blocks in bitcoin, your transaction is irreversible. The very concept of blockchain is that the ledger is immutable. This means that the root of merkle trees are also permanently stored in the ledger and cannot be modified. Now to keep track of your transaction, you can just store the headers and the path from root to your transactions.

## Function/File Use-Cases

### main.cpp
Menu Driven Program for Data Validation.

### msgPackets.txt
This file contains the splitted msg packets which is usually sent over peer-peer network from any source.

### masterHash.txt
This file contains the hash-tree structure which is sent from a Trusted Source.


## Authors

* **Ebenezer Jesuraj** - [@EbenezerJesuraj](https://github.com/EbenezerJesuraj)
* **Dinesh Kumar** - [@dinx6](https://github.com/dinx6)
