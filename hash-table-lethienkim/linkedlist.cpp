/* ******************************************
 * File:   linkedlist.cpp
 * Author: Thienkim Le
 * Implementation of a simple linked list data structure.
********************************************/

#include "linkedlist.h"

LinkedList::LinkedList() {
	/*****************************************
 	Constructor for the LinkedList class.
 	Initializes the head pointer to nullptr, indicating an empty list.
  	*********************************************/
    head = nullptr;
}

LinkedList::~LinkedList() {
	/*****************************************
 	Destructor for the LinkedList class.
	Calls the clearList() method to deallocate all memory
	associated with the linked list before the object is destroyed.
	********************************************/
    clearList();
}

bool LinkedList::addNode(int id, std::string* data) {
	/*****************************************
 	Adds a new node to the linked list with the given id and data.
 	
 	@param id: The unique identifier for the new node.
 	@param data: A pointer to the string data associated with the new node.
 	@return True: if the node is successfully added, false otherwise.
 	********************************************/
 	
 	// Initialize the return value as true, indicating success.
    bool ret = true;

    // Check if id is positive and data is not empty
    if (id <= 0 || data == nullptr || data->empty()) {
        ret = false; // Invalid id or empty data string
    } else {    
        // Traverse the list to check if a node with the same id exists
        Node* current = head;
        bool idExists = false;
        while (current) {
            if (current->data.id == id) {
                idExists = true;
                break;
            }
            current = current->next;
        }

        // If a node with the same id exists, set return value to false
        if (idExists) {
            ret = false;
        } else {
            // Create a new node
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *data;

            // Insert the new node into the appropriate position in the list
            if (head == nullptr || id < head->data.id) {
                // Insert the new node as the new head
                newNode->next = head;
                newNode->prev = nullptr;
                if (head != nullptr) {
                    head->prev = newNode;
                }
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr && current->next->data.id < id) {
                    current = current->next;
                }
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
            ret = true;
        }
    }
    return ret; // Successfully added the node or failed due to existing ID
}

bool LinkedList::deleteNode(int id) {
	/****************************************
 	Deletes a node with the given ID from the linked list.
 	Adjusts pointers to maintain list integrity.
 	
 	@param id: The ID of the node to delete.
 	@return True: if the node with the given ID is found and deleted, false otherwise.
 	*****************************************/
 	
   Node* current = head;
   bool deleted = false;

    while (current) {
        if (current->data.id == id) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            delete current;
            deleted = true;
        }
        current = current->next;
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data* returnData) {
	/*****************************************
 	Retrieves the node with the specified ID and fills the provided Data structure.
 	If the node is found, true is returned, and the Data structure is populated with the node's data.
 	If the node is not found, false is returned, and default values are assigned to the Data structure.
 	
	@param id: The ID of the node to search for.
 	@param returnData: A pointer to the Data structure where the node's data will be stored.
	@return true: if the node with the specified ID is found, false otherwise.
 	*****************************************/
 	
    // Find the node with the given ID
    Node* current = head;
    bool found = false;
    // Search for the node with the given ID
    while (current) {
        if (current->data.id == id) {
            // Fill the empty struct Data with node data
            *returnData = current->data;
            found = true; // Return true as the node is found
     		break;
        }
        current = current->next;
    }

    // If node not found, set default values and return false
    if (!found){
    	returnData->id = -1;
    	returnData->data = "";
	}
        return found; // Return false as the node is not found
}

void LinkedList::printList(bool backward) {
	/*****************************************
 	Prints the linked list either in forward or backward order, based on the specified flag.
 	 
 	@param backward A boolean flag indicating whether to print the list in backward order.
 	                 If false (default), the list is printed in forward order.
 	*****************************************/
 	
    Node* current = backward ? nullptr : head;

    if (!backward) {
        // Print the list in forward order
        while (current) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    } else {
        // Print the list in backward order
        if (head) {
            current = head;
            while (current->next)
                current = current->next;
            while (current) {
                std::cout << current->data.id << ": " << current->data.data << std::endl;
                current = current->prev;
            }
        }
    }
}

int LinkedList::getCount() {
	/*****************************************
 	Counts the number of nodes in the linked list.
 	 
 	@return The number of nodes in the linked list.
 	*****************************************/
 	
    int count = 0;
    Node* current = head;

    // Traverse the list and count the nodes
    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

bool LinkedList::clearList() {
    /*****************************************
     * Clears the linked list by deleting all nodes and resetting the head pointer to nullptr.
     * 
     * @return true if the list is successfully cleared, false otherwise.
     *****************************************/
    Node* current = head;
    Node* nextNode = nullptr;

    // Traverse the list and delete each node
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    // Reset head to nullptr
    head = nullptr;
    return true;
}



