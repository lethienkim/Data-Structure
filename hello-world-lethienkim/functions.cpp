/************
 *Name: Thienkim Le
 *Assignment2-Hello World
 *File: functions.cpp
 *Purpose of the file: Create the functions.cpp
 *************/

// Including the header file "functions.h" that likely contains declarations needed for this source file.
#include "functions.h"

int strlength(const char* str) {
	/***********************************************************
	Function to calculate the length of a C-style string.
	Takes a pointer to a character array (C-style string) as input.
	Returns the length of the string.
	***********************************************************/
    int count = 0;

    // Looping through the characters of the string until the null terminator '\0' is encountered.
    while (str[count] != '\0') {
        count++; // Incrementing the count for each character in the string.
    }	

    return count;
}

