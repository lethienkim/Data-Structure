/* ******************************************
 * File:   hashtable.h
 * Author: Thienkim Le
 * This file defines the HashTable class, which implements a hash table data structure.
 * Hash tables are used to store key-value pairs, where each key is unique. The keys are
 * hashed to generate an index, which is used to store and retrieve the corresponding value.
 * This implementation uses separate chaining to handle collisions. Each bucket in the hash
 * table is a linked list, allowing multiple key-value pairs with the same hash to be stored
 * and retrieved efficiently.
 ********************************************/


#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <string>
#include "linkedlist.h"

using std::cout;
using std::endl;

#define HASHTABLESIZE 15

class HashTable {
private:
    LinkedList buckets[HASHTABLESIZE]; // Array of linked lists representing hash table buckets
    int count; 
        
    int hash(int);
    
public:
    /**********************
     * Constructors/Destructor
     **********************/
    HashTable();  
    ~HashTable(); 
        
    /**********************
     * Getters/Accessors
     **********************/
    string getData(int);            // Get data associated with a given ID from the hash table
    int getCount();                 // Get the total count of elements in the hash table
    void printTable();              // Print the hash table
    /**********************
     * Setters/Mutators
    **********************/
    bool insertEntry(int, string*); // Insert an entry into the hash table
    bool removeEntry(int);          // Remove an entry from the hash table
    
};
   

#endif // HASHTABLE_H
