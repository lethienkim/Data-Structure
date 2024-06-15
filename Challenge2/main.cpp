/******************************************
 * File:   main.cpp
 * Author: Thienkim Le
 * 
 * Main program to test FIFO and LIFO queues
 ******************************************/

#include "main.h"

int main() {
	/******************************************
	 * This program demonstrates the usage of a FIFO (First-In-First-Out) and a LIFO (Last-In-First-Out) queue.
	 * It creates two queues, pushes data into them, pulls data from them, and prints the queue contents.
	 ******************************************/
    
	// Seed for random number generation
    srand(time(nullptr));

    // Creating FIFO Queue
    Queue fifoQueue(true);

    // Creating LIFO Queue
    Queue lifoQueue(false);

    // Test FIFO Queue
    std::cout << "\nTesting FIFO Queue:\n";
    std::cout << "-.-.-.-.-.-.-.-.-.-.-.-\n";
    
    for (int i = 0; i <=MAXSTRSIZE; ++i) {
        std::string info;
        generateRandomString(info);
        std::cout << "Pushing data to FIFO Queue: ID-" << i << ", Info-" << info << "\n";
        fifoQueue.push(i, info);
    }
    std::cout << "\nFIFO Queue Count: " << fifoQueue.count() << "\n";
    
	std::string info;
    generateRandomString(info);
    printQueueContents(fifoQueue, "FIFO");

    Data data;
    while (fifoQueue.pull(data)) {
        std::cout << "Pulled data from FIFO Queue: ID-" << data.id << ", Info-" << data.information << "\n";
    }
    std::cout << "FIFO Queue Count after pulling all data: " << fifoQueue.count() << "\n";
    
    std::cout << "FIFO Queue is empty\n\n";

    // Test LIFO Queue
    std::cout << "Testing LIFO Queue:\n";
    std::cout << "-.-.-.-.-.-.-.-.-.-.-.-\n";
    for (int i =1; i <= MAXSTRSIZE; ++i) {
        std::string info;
        generateRandomString(info);
        std::cout << "Pushing data to LIFO Queue: ID-" << i << ", Info-" << info << "\n";
        lifoQueue.push(i, info);
    }
    std::cout << "\nLIFO Queue Count: " << lifoQueue.count() << "\n";
    
    generateRandomString(info);
    printQueueContents(lifoQueue, "LIFO");

    while (lifoQueue.pull(data)) {
        std::cout << "Pulled data from LIFO Queue: ID-" << data.id << ", Info-" << data.information << "\n\n";
    }
    std::cout << "\nLIFO Queue Count after pulling all data: " << lifoQueue.count() << "\n";
    std::cout << "LIFO Queue is empty\n\n";


    fifoQueue.clear(); // Corrected line
    

    return 0;
}