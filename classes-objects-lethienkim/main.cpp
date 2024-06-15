/**************************
    Name: Thienkim Le
    Assignment: 3
    File:   main.cpp
    Purpose of the file: This is a simple application to demonstrate classes and objects in C++.
 	Note the header structure and files for all cpp and h files.
 	The only thing included in main.cpp is it's main.h file.
 	This file, main.cpp, includes only main.h.
***************************/

#include "main.h"


int main(int argc, char** argv) {
	/**
 	Main Function: Creates Circle and Sphere objects with different parameters,
 	displays their respective areas and volumes.
  
 	@param (int) argc : Number of command-line arguments
 	@param (char**) argv : Array of command-line arguments
 	@return (int) : Status code indicating the termination status of the program
 	**/
	
	//Creates a Circle object with no parameters
    Circle myCircle1;
    // Creates a Circle object with radius 5.0
    Circle myCircle2(5.0);
	 
	//creates a Sphere object with no parameters
    Sphere mySphere1;
     //creates a Sphere object with radius is 5.0
    Sphere mySphere2(5.0);

	// Displays the area of myCircle1
    displayArea(&myCircle1);
    // Displays the area of myCircle2
    displayArea(&myCircle2);
    displayArea(&myCircle2);

	// Displays the volume of mySphere1
    displayVolume(&mySphere1);
    // Displays the volume of mySphere1
    displayVolume(&mySphere2);

    return 0;
}
