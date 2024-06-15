/* ******************************************
 * File:   queue.cpp
 * Author: Thienkim Le
 * 
 * Implementation file for the Queue class,
 * which represents a queue data structure
 * storing integer IDs and associated information strings
********************************************/

#include "queue.h"

Queue::Queue(bool fifo) : head(nullptr), tail(nullptr), isFIFO(fifo) {
	/*****************************************
	 * Constructor for the Queue class.
	 * Initializes the head and tail pointers to nullptr, indicating an empty queue.
	 * @Parameters:
	 * @return fifo: A boolean value indicating whether the queue is FIFO (true) or LIFO (false).
	*********************************************/
}

Queue::~Queue() {
	/*****************************************
	 * Destructor for the Queue class.
	 * Calls the clear() function to deallocate memory and delete all elements in the queue.
	*********************************************/
    clear();
}

void Queue::pushBack(const Data& data) {
	/*********************************************
	* @brief Pushes data to the back of the queue.
	* This function creates a new node with the provided data and appends it to the
	* back of the queue. If the queue is empty, the new node becomes both the head
	* and the tail of the queue. If the queue is not empty, the new node is linked
	* to the current tail node, and then becomes the new tail node.
	* @param data The data to be pushed to the back of the queue.
	*********************************************/
    Node* newNode = new Node(data.id, data.information);
    if (!tail) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::pushFront(const Data& data) {
	/*********************************************
	* Pushes data to the front of the queue.
	* This function creates a new node with the provided data and inserts it at the
	* front of the queue. If the queue is empty, the new node becomes both the head
	* and the tail of the queue. If the queue is not empty, the new node is linked
	* to the current head node, and then becomes the new head node.
	* @param data The data to be pushed to the front of the queue.
	*********************************************/
    Node* newNode = new Node(data.id, data.information);
    newNode->next = head;
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
}

bool Queue::popFront(Data& data) {
    /*********************************************
    * Removes and returns the data from the front of the queue.
    * @param data Reference to a Data structure to store the popped data.
    * @return True if data was successfully popped, false if the queue was empty.
    *********************************************/

    bool success = false; // Flag to track successful pop operation

    if (head) {
        Node* temp = head;
        data = temp->data;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        success = true; // Set success flag to true after successful pop
    }

    return success; // Return the success flag indicating if the pop was successful
}


bool Queue::popBack(Data& data) {
	/*********************************************
	* Removes and returns the data from the back of the queue.
	* @param data Reference to a Data structure to store the popped data.
	* @return True if data was successfully popped, false if the queue was empty.
	*********************************************/
	bool success = false;

	if (!tail) {
        success = false;
    } else {
        Node* temp = head;
        if (temp == tail) {
            data = temp->data;
            delete temp;
            head = tail = nullptr;
            success = true;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            data = tail->data;
            delete tail;
            tail = temp;
            tail->next = nullptr;
            success = true;
        }
    }

    return success;
}

bool Queue::push(int id, const std::string& information) {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
	 
    bool success = true;
    if (id <= 0 || information.empty()) {
        success = false;
    } else {
        Data data{id, information};
        if (isFIFO) {
            pushBack(data);
        } else {
            pushFront(data);
        }
    }
    return success;
}

bool Queue::pull(Data& data) {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    bool result;

    // Perform the appropriate pull operation based on the queue type
    if (isFIFO) {
        result = popFront(data);
    } else {
        result = popBack(data);
    }

    // Return the result of the pull operation
    return result;
}

bool Queue::peek(Data& data) const {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    bool success = false;
    if (isFIFO) {
        if (head) {
            data = head->data;
            success = true;
        }
    } else {
        if (tail) {
            data = tail->data;
            success = true;
        }
    }
    return success;
}

int Queue::count() const {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void Queue::clear() {
	/*********************************************
	 * Removes all elements from the queue and deallocates memory.
	 *********************************************/
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
}

bool Queue::exists(int id) const {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    bool found = false;
    Node* current = head;
    while (current && !found) {
        if (current->data.id == id) {
            found = true;
        }
        current = current->next;
    }
    return found;
}

int Queue::find(int id) const {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    int position = 0;
    Node* current = head;
    while (current) {
        if (current->data.id == id) {
            return isFIFO ? position : count() - position - 1;
        }
        current = current->next;
        position++;
    }
    return -1;
}

void generateRandomString(std::string& str) {
	/*********************************************
	 * Removes and returns the data from the front of the queue.
	 * @param data Reference to a Data structure to store the popped data.
	 * @return True if data was successfully popped, false if the queue was empty.
	 *********************************************/
    int size = rand() % MAXSTRSIZE;
    str.clear();
    for (int i = 0; i < size; ++i) {
        char randomChar = 'a' + rand() % 26; // Generating random lowercase character
        str.push_back(randomChar);
    }
}

void printQueueContents(Queue& queue, const std::string& queueType) {
	/*********************************************
	 * Prints the contents of the specified queue.
	 * @param queue Reference to a Queue to print.
	 * @param queueType Type of the queue (e.g., "FIFO" or "LIFO").
	 *********************************************/
    std::cout << "Contents of Queue:\n";
    Data data;                
    while (queue.pull(data)) {
        std::cout << "ID: " << data.id << ", Info: " << data.information << "\n";
    }
    std::cout << std::endl;
}



