/* ******************************************
 * File:   stack.cpp
 * Author: Thienkim Le
 * Implementation of a stack data structure
 * capable of storing integer IDs and associated information strings.
 ********************************************/

#include "stack.h"


Stack::Stack(int stackSize) : top(-1) {
		/*****************************************
 	Constructor
 
 	Constructs a stack with the specified size.
  
 	@param stackSize The size of the stack.
 	*****************************************/
 	
    // Set the size of the stack using ternary operator
    size = (stackSize >= STACKMIN) ? stackSize : STACKMAX;

    // Dynamically allocate the stack array
    stack = new Data*[size];
}

Stack::~Stack() {
	/*****************************************
 	Destructor
  
  	Destroys the stack and deallocates memory.
 	*****************************************/
	
    // Deallocate any remaining elements on the stack
    for (int i = 0; i <= top; ++i) {
        delete stack[i];
    }

    // Deallocate the stack array
    delete[] stack;
}

bool Stack::push(int id, std::string& information) {
	/*********************************************
	@brief Pushes data onto the stack.
 
 	This function attempts to push the provided data onto the stack. 
 	It validates the data, checks if there is room in the stack, and 
 	then dynamically creates a struct to hold the data and pushes the 
  	pointer for the struct onto the stack.
  
 	@param id An integer representing the ID of the data.
  	@param information A reference to a string containing the information to be stored.
  	
  	@return true if the data was successfully pushed onto the stack, false otherwise.
 	*********************************************/
 	
    // Variable to indicate whether the push was successful
    bool pushed = false;

    // Test the validity of the data
    if (id <= 0 || information.empty()) {
        // Invalid data, cannot proceed to push
        pushed = false;
    }
    // Check if there is room in the stack
    else if (top < size - 1) {
        // Dynamically create a struct Data to hold the data
        Data* newData = new Data;

        // Put the id and string in the struct Data
        newData->id = id;
        newData->information = information;

        // Increment the stack counter
        top++;

        // Push the pointer for the struct onto the stack
        stack[top] = newData;

        // Mark push as successful
        pushed = true;
    } else {
        // No room in the stack
        pushed = false;
    }

    // Return the success status
    return pushed;
}

bool Stack::pop(Data& poppedData) {
	/*********************************************
 	@brief Pops data from the stack.
  
 	This function attempts to pop data from the top of the stack. If the stack is not empty,
 	it retrieves the data from the top of the stack, deletes the allocated memory, decrements
 	the stack counter, and fills the passed struct Data with the popped data. If the stack is
 	empty, it fills the passed struct with default values and returns false.
 
 	@param poppedData An empty struct Data passed by reference to store the popped data.
 
 	@return true if data was successfully popped from the stack, false if the stack was empty.
 	*********************************************/
	
    // Variable to indicate whether a pop operation was successful
    bool popped = false;

    // Check if the stack is not empty
    if (!isEmpty()) {
        // Get the data from the top of the stack and put it in the struct Data passed from the caller
        poppedData = *(stack[top]);

        // Delete the allocated memory from the top of the stack
        delete stack[top];

        // Decrement the stack counter
        top--;

        // Set popped to true indicating successful pop
        popped = true;
    } else {
        // Stack is empty, fill the passed struct with -1 and empty string
        poppedData.id = -1;
        poppedData.information = "";
    }

    // Return the status of the pop operation
    return popped;
}

bool Stack::peek(Data& peekedData) {
	/*********************************************
 	@brief Peeks at the data on the top of the stack.
  
  	This function peeks at the data on the top of the stack. If the stack is not empty, it retrieves the data
  	from the top of the stack and assigns it to the provided struct Data without removing it from the stack.
  	If the stack is empty, it fills the passed struct with default values.
  
  	@param peekedData A struct Data passed by reference to store the peeked data.
  
  	@return true if data was successfully peeked from the stack, false if the stack was empty.
 	*********************************************/
 
    // Variable to indicate whether a peek operation was successful
    bool peeked = false;

    // Check if the stack is not empty
    if (!isEmpty()) {
        // Get the data from the top of the stack and put it in the struct Data passed from the caller
        peekedData = *(stack[top]);

        // Set peeked to true indicating successful peek
        peeked = true;
    } else {
        // Stack is empty, fill the passed struct with -1 and empty string
        peekedData.id = -1;
        peekedData.information = "";
    }

    // Return the status of the peek operation
    return peeked;
}

bool Stack::isEmpty() {
	/*********************************************
 	@brief Checks if the stack is empty.
  
 	This function checks if the stack is empty by comparing the top index with -1.
  
  	@return true if the stack is empty, false otherwise.
 	*********************************************/
	
    return top == -1;
}

int Stack::getSize() const {
	/*********************************************
 	@brief Gets the current size of the stack.
  
 	This method returns the current number of elements in the stack.
  
  	@return The current size of the stack.
 	*********************************************/
 	
    return top + 1;
}



