/* ******************************************
 * File:   main.cpp
 * Author: Thienkim Le
 * This file contains the main function for the program.
 * It seeds the random number generator, generates test data,
 * creates a hash table object, inserts test data into the table,
 * and performs various operations to test the functionality of the hash table.
 * The test data includes both unique and non-unique IDs, as well as a known bad ID.
 * After inserting the test data, the program demonstrates the usage of the hash table
 * by retrieving data for an existing ID, removing an entry, and clearing the hash table.
 ********************************************/

#include "main.h"


int main() {
    // Seed the rand function
    srand(time(NULL));

   /* ******************************************
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non-unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
    ********************************************/
   	const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    
    /*
     * Show test data
     */
   cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
   cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // Create your hash table object
    HashTable hashTable;
    
    // Show that it is empty by calling getCount and printTable
   	cout << "Initial count: " << hashTable.getCount() << endl;
    cout << "Initial table:" << endl;
    hashTable.printTable();
    cout << endl;
    
    // Try to put ALL the test data into the table 
    for (int i = 0; i < testdatasize; ++i) {
        hashTable.insertEntry(ids[i], &strs[i]);
    }
    
    // Show the table after inserting all test data
    cout << "Count after insertion: " << hashTable.getCount() << endl;
    cout << "Table after insertion:" << endl;
    hashTable.printTable();
    cout << endl;

    // Continue using and testing your table, add and remove data,
    // do whatever it takes to fully test your object and prove it
    // is robust and can handle all use cases.

   	
	// Generate a random ID
	int randomId = std::rand() % testdatasize; // Generating a random number between 0 and 19 (inclusive)

	// Try to get data for the random ID
	string data = hashTable.getData(ids[randomId]);
   	
	// Retrive random data ID
    cout << "Retrive random data for ID  " << ids[randomId] << " : "<< data << endl;
    	
	int totalRemoved = 0;	 
    // Example of removing an entry
    cout << "\nRemoving entry ID "<<ids[randomId] << ": " << data << endl;
    if (hashTable.removeEntry(hashTable.removeEntry(ids[randomId])) == -1) {
        cout << "Failed: This ID is " << ids[randomId] << " known bad" << endl;
    } else {
        cout << "  Success removed" << endl;
        totalRemoved++;
    }
    hashTable.removeEntry(ids[randomId]);
    
    int firstId = ids[0];
	int middleId = ids[(testdatasize-3) / 2];
	int lastId = ids[testdatasize - 3];
    
    // Attempt to remove a random ID
	cout << "Attempting to remove random ID: " << randomId << endl;
	if (hashTable.removeEntry(randomId)) {
        cout << "  Success removed" << endl;
        totalRemoved++;
    } else {
        cout << "  Failed: This ID  is non-existent. It was not removed" << endl;
    }
	hashTable.removeEntry(randomId);
		
	// Remove the first ID
	cout << "\nRemoving first ID: " << firstId << endl;
	if (hashTable.removeEntry(firstId)) {
        cout << "  Success removed" << endl;
        totalRemoved++;
    } else {
        cout << "  Failed: ID " <<  firstId << " was not removed because it was already removed" << endl;
    }
	hashTable.removeEntry(firstId);

	// Remove the middle ID
	cout << "Removing middle ID: " << middleId  << endl;
	if (hashTable.removeEntry(middleId)) {
        cout << "  Success removed" << endl;
        totalRemoved++;
    } else {
        cout << "  Failed: ID " <<  middleId << " was not removed because it was already removed" << endl;
    }
	hashTable.removeEntry(middleId);

	// Remove the last ID
	cout << "Removing last ID: " << lastId << endl;
	if (hashTable.removeEntry(lastId)) {
        cout << "  Success removed" << endl;
        totalRemoved++;
    } else {
        cout << "  Failed: ID " <<  lastId << " was not removed because it was already removed"<< endl;
    }
	hashTable.removeEntry(lastId);

	// Show the table after removing the entries
	cout << "\nTotal entry IDs were removed: " << totalRemoved << endl;
	cout << "Count after removals: " << hashTable.getCount() << endl;
	cout << "Table after removals:" << endl;
	hashTable.printTable();
	cout << endl;
     
    return 0;
}
