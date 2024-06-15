 /******************************************
 * File:   bintree.h
 * Author: Thienkim Le
 * 
 * Description:
 *   This file contains the declaration of the BinTree class, which represents a binary tree
 *   data structure. The class provides methods for managing and manipulating the binary tree,
 *   including adding and removing nodes, searching for nodes, and traversing the tree in
 *   pre-order, in-order, and post-order. 
 *
 ******************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;

class BinTree {
	/*********************************************
	This class defines a Binary Tree (BinTree). It allows the creation, manipulation, and traversal of a binary search tree.
	The tree can store nodes containing integer IDs and associated string information.

	@attrib root : Pointer to the root node of the binary tree
	@attrib count : Number of nodes in the binary tree
	*********************************************/
private:
	// Private member variables
    DataNode* root;
    int count;

	// Private member methods
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int id, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

public:
	/**********************
      Constructors/Destructor
    **********************/
    BinTree();
    ~BinTree();
    
    /**********************
      Getters/Accessors
    **********************/
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
           
    /**********************
      Setters/Mutators
    **********************/
	void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    
    // Display methods
    void displayTree();
    
    // Traversal methods
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
};

#endif // BINTREE_H