/* ******************************************
 * File:   main.h
 * Author: Thienkim Le
 * 
 * This header file defines constants and includes necessary libraries for the main program.
 * It includes the custom "graph.h" header file, which contains the definition of the Graph class.
 * Constants such as BUFFERSIZE, MAXID, and BASE are defined here for use throughout the program.
 ********************************************/


#ifndef MAIN_H
#define MAIN_H

#include "graph.h"  

#include <iostream>   // Input/output stream for console output
#include <cstdlib>    // Standard library for general utilities (e.g., memory management, random number generation)
#include <ctime>      // Time functions for seeding the random number generator

#define MINID 10
#define MAXID 20      // Maximum ID for vertices in the graph

#endif // MAIN_H