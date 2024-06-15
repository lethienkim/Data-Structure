/* ******************************************
 * File:   main.h
 * Author: Thienkim Le
 *  
 * Header file for the main program
********************************************/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "queue.h"

void generateRandomString(std::string& str);
void printQueueContents(Queue& queue, const std::string& queueType);

#endif // MAIN_H