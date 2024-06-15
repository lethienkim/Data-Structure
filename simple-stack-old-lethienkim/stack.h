/****************************************************
 * File: stack.h
 * Name: Thienkim Le
 * The interface for a simple integer Stack class.
 * 
 ****************************************************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdexcept> 
#define STACKSIZE 10

class Stack {
    
public:
    /***********************
    Constructors/Destructor
     **********************/
    Stack(); // Constructor
    ~Stack(); // Destructor

    
    bool push(int); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 

private:
    int top; 
    int stack[STACKSIZE]; 
};
#endif // STACK_STACH_H
