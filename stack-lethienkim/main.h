/* ******************************************
 * File:   main.h
 * Author: Thienkim Le
 * This header file, main.h, defines constants and includes necessary libraries for the implementation of a stack data structure and associated functions. 
 * It also provides declarations for functions and variables used in the main program. 
 * Additionally, it sets up preprocessor directives to guard against multiple inclusion of the same file.
 ********************************************/

#ifndef STACKS_MAIN_H
#define STACKS_MAIN_H

#include <stdlib.h>   /* srand, rand */
#include <ctime>     /* time */
#include <iostream>   /* cout, endl */
#include <string>     /* string */
#include <cmath> // Add this header for the round function
#include <exception>
#include "functions.h"
#include "stack.h"


#define STACKSIZE 10000
#define MULTIPLIER 2
#define MAX_INT 10000
#define CHOICES 6
#define RANDOM_MULTIPLIER 10000

#endif /* STACKS_MAIN_H */
