/* ******************************************
 * File:   stack.h
 * Author: Thienkim Le
 * This file contains the interface for a stack class that works with the struct Data type.
 ********************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <cstdlib> // Include <cstdlib> for rand() function
#include "main.h"
#include "data.h"

#define STACKMAX 10
#define STACKMIN 2

class Stack {

public:

    /**********************
     * Constructors/Destructor
     **********************/
	 Stack(int);
    ~Stack(); 
    
    /**********************
     * Getters/Accessors
     **********************/
    bool isEmpty();
    bool peek(Data&);
 	
 	/**********************
     * Setters/Mutators
     **********************/
    bool push(int, std::string&);
    bool pop(Data&);
    int getSize() const;
         
private:
	    int top;
    int size;
    Data **stack;
};

#endif //STACK_H