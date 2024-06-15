
/* ****************************************** 
 * File:   hashtable.cpp
 * Author: Thienkim Le
 * Implementation of the HashTable class member functions.
********************************************/


#include "hashtable.h"

HashTable::HashTable() {
    /**********************
     * Constructor for the HashTable class.
    **********************/
    count = 0;
    }

HashTable::~HashTable() {
    /**********************
     * Destructor for the HashTable class.
	**********************/
    }

int HashTable::hash(int id) {
	/**********************
     * Calculate hash value for the given ID.
     * The hash value is computed by taking the modulo of the ID with the size of the hash table.
     * @param id: The ID for which the hash value needs to be calculated.
     * @return The hash value computed for the given ID.
     **********************/
    return id % HASHTABLESIZE;
}

bool HashTable::insertEntry(int id, std::string* data) {
	/*******************************
 	* This function inserts an entry into the hash table with the given ID and associated data.
 	* @param id: The ID of the entry to be inserted.
 	* @param data: A pointer to the string data associated with the entry.
 	* @return True if the insertion was successful, false otherwise.
 	*******************************/
    bool ret = true; // Initialize return value as true
    // Check if data is valid
    if (data == nullptr || data->empty()) {
        ret = false; // Set return value to false if data is invalid
    }

    // Calculate hash index
    int index = hash(id);
	
    // If the index is out of bounds, set return value to false
    if (index < 0 || index >= HASHTABLESIZE) {
        ret = false;
    }

    // Insert the data directly into the linked list at the calculated index
    bool inserted = buckets[index].addNode(id, data);
    if (inserted) {
        count++; // Increment count if insertion successful
    }
    return ret;
}

string HashTable::getData(int id) {
	/**********************
     * Retrieves data associated with the given ID from the hash table.
     * @param id: The ID for which data is to be retrieved.
     * @return The data associated with the given ID, or an empty string if not found.
     **********************/
    int index = hash(id);
    Data returnData;
    string result = ""; // Initialize result as an empty string
    
    // Attempt to retrieve data associated with the given ID
    if (buckets[index].getNode(id, &returnData)) {
        result = returnData.data;
    }
    return result; // Return the retrieved data or an empty string if not found
}

bool HashTable::removeEntry(int id) {
	/**********************
     * Remove an entry from the hash table with the given ID.
     * Calculates the index in the hash table based on the ID,
     * then calls the deleteNode() method of the appropriate bucket.
     * Decrements the count if removal is successful.
     * @param id: The ID of the entry to remove.
     * @return True if the entry is successfu
     **********************/
    int index = hash(id);
    bool removed = buckets[index].deleteNode(id);
    if (removed) {
        count--; // Decrement count if removal successfulSS
    }
    return removed;
}

int HashTable::getCount() {
	/**********************
     * Get the count of elements in the hash table.
     * @return The total number of elements currently stored in the hash table.
     **********************/
    return count;
}

void HashTable::printTable() {
    /*****************************************
     * Prints the contents of the hash table.
     * For each bucket, prints the index and the list of entries in that bucket.
    *****************************************/
     
    for (int i = 0; i < HASHTABLESIZE; ++i) {
        cout << "Entry " << i << ": ";
        if (buckets[i].getCount() == 0) {
            cout << "Empty" << endl;
        } else {
           buckets[i].printList();
        }
    }
}