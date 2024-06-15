/****************************************************
 * File: stack.cpp
 * Name: Thienkim Le
 * The interface for a simple integer Stack class.
 * 
 ****************************************************/

#include "stack.h"

Stack::Stack() : top(-1) {
    /* ****************************************
    Constructor

    @param na : na

    @return na : na

    @exception na : na 

    @note the 'this' designation is optional. use it where
    there is ambiguity or just to be complete and precise.
    here it is shown for demonstration purposes.
    *********************************************/
}

Stack::~Stack() {
    /*********************************************
    Destructor for the Stack class.
    Currently has no implementation.
     *********************************************/
}

bool Stack::push(int value) {
    /* ****************************************
    Push an item to the top of the stack,
    if there is room

    @param (int) i : any integer

    @return (bool) : True/False
    *********************************************/
    bool ret;
    if (top < STACKSIZE - 1) {
        stack[++top] = value;
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

int Stack::pop() {
   /* ****************************************
    Pop an item from the top of the stack,
    if there is one

    @param na : na

    @return (int) : top item on the stack
    
    @exception (int) : if underflow
    *********************************************/
    if (top == -1) {
        throw std::out_of_range("Underflow: Stack is empty");
    }
    return stack[top--]; 
}

int Stack::peek() const {
    /* ****************************************
    Peek an item from the top of the stack
    if there is one

    @param (int*) : integer pointer for int provided by the caller

    @return (bool) : True/False for success/failure to peek
    *********************************************/
    if (top == -1) {
        throw std::out_of_range("Stack is empty");
    } 
    return stack[top];
}  

bool Stack::isEmpty() const {
     /* ****************************************
    Check stack for empty state

    @param na : na

    @return (bool) : True/False for emmty / not-empty
    *********************************************/
    bool ret;
    if (top < 0) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}  
