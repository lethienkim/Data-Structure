/**************************
Name: Thienkim Le
Assignment: 4
Purpose of the file: This file contains the main function which serves as a driver program to test the functionality of the Stack class. 
It demonstrates the usage of try-catch blocks to handle exceptions thrown by stack operations.
***************************/

#include "main.h"

int main() {
    int choice = 0;
    int value;
    
    // Create a Stack object
    Stack stack;
    
    // Test popping from an empty stack
    try {
        stack.pop();
    } catch (std::exception &e) {
        std::cout << "Cannot pop: stack is empty!" << std::endl;
    }
	
	// Check if the stack is empty
    bool empty = stack.isEmpty();
    if (empty) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Error: stack is not empty";
    }

	// Fill the stack with random values
    for (int i = 0; i < STACKSIZE; i++) {
        stack.push(rand() % 15);
    }
	
	// Attempt to push onto a full stack
    if (stack.push(10)) {
        std::cout << "Error: push on a full stack" << std::endl;
    }

    // Peek at the top value of the stack
    try {
        value = stack.peek(); 
        std::cout << "peek: " << value << std::endl;
    } catch (std::exception &e) {
    std::cout << "Stack is empty: peek failed" << std::endl;
    }
        
    // Test stack operations randomly
    for (int i = 0; i < STACKSIZE * MULTIPLIER; i++) {
        choice = rand() % 4 + 1; // Generate random operation
    
        switch (choice) {
            case 1: 
                // Push random value onto the stack
                value = rand() % 15; 
                try {
                    stack.push(value); 
                    std::cout << "pushed: " << value << std::endl;
                } catch (std::exception &e) {
                    std::cout << "Overflow error: not pushed" << std::endl;
                }
                break;
            case 2: 
                // Pop value from the stack
                try {
                    value = stack.pop(); 
                    std::cout << "pop: " << value << std::endl;
                } catch (std::exception &e) {
                    std::cout << "Underflow error: not popped" << std::endl;
                }
                break;
            case 3: 
                // Peek at the top value of the stack
                try {
                    value = stack.peek(); 
                    std::cout << "peek: " << value << std::endl;
                } catch (std::exception &e) {
                    std::cout << "Stack is empty: peek failed" << std::endl;
                }
                break;
            case 4: 
                // Check if the stack is empty
                bool empty = stack.isEmpty(); 
                if (empty) {
                    std::cout << "Stack is empty" << std::endl;
                } else {
                    std::cout << "Stack is not empty" << std::endl;
                }
                break;
        }
    }
    
    return 0;
}
