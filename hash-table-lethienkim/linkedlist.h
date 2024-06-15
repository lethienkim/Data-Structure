/* ******************************************
 * File:   linkedlist.h
 * Author: Thienkim Le
 * The interface for a linked list data structure 
 * storing integer IDs and associated information strings. 
********************************************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList {
private:
    Node* head;

public:
    /**********************
    Constructors/Destructor
    **********************/
    LinkedList();
    ~LinkedList();

    /**********************
     * Getters/Accessors
    **********************/
    void printList(bool = false);
    int getCount();
    bool getNode(int, Data*);
    /**********************
     * Setters/Mutators
    **********************/
    bool addNode(int, std::string*);
    bool deleteNode(int id);
    bool clearList();
        
};

#endif