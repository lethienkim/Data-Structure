/* ******************************************
 * File:   queue.h
 * Author: Thienkim Le
 * 
 * The interface for a queue data structure
 * storing integer IDs and associated information strings
********************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> 
#include <string>
const int MAXSTRSIZE = 20; // Maximum size of the generated string

struct Data {
    int id;
    std::string information;
};

class Queue {
private:
    struct Node {
        Data data;
        Node* next;
        Node(int id = 0, const std::string& info = "") : data{id, info}, next(nullptr) {}
    };

    Node* head;
    Node* tail;
    bool isFIFO;

    void pushBack(const Data& data);
    void pushFront(const Data& data);
    bool popFront(Data& data);
    bool popBack(Data& data);

public:
	/**********************
    Constructors/Destructor
    **********************/
    Queue(bool fifo = true);
    ~Queue();
    
    
    /**********************
     * Setters/Mutators
    **********************/
    bool push(int id, const std::string& information);
    bool pull(Data& data);
    void clear();

	/**********************
     * Getters/Accessors
    **********************/
    bool peek(Data& data) const;
    int count() const;
    bool exists(int id) const;
    int find(int id) const;
    
    void generateRandomString(std::string& str);
    void printQueueContents(Queue& queue, const std::string& queueType);
    
    
};

#endif // QUEUE_H


