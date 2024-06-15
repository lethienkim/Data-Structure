/* ******************************************
 * File:   functions.cpp
 * Author: Thienkim Le
 * This file contains the implementation of 
 * various functions used for manipulating data.
 ********************************************/

#include "functions.h"

void rand_string(std::string *str){
    /*********************************************
    * This function generates a random string of characters
    * and assigns it to the provided string pointer. The size
    * of the generated string varies from 0 to MAXSTRSIZE-1.
    * @param str : pointer to string where the generated
    * @exception None
    * @note The function uses the rand() function to generate
    *********************************************/
	
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete[] buffer;
    return;
}

