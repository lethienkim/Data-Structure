/************
 *Name: Thienkim Le
 *Assignment2-Hello World
 *File: main.cpp
 *Purpose of the file: Create the main.cpp
 *************/

// Including necessary header files for the program.
#include "main.h"
#include "functions.h"

/*
 * Function: main
 * Parameters:
 * - argc: Number of command line parameters.
 * - argv: Array of command line parameter values.
 * Prints a greeting message, the program name, its length, and information about
 * command line parameters including their count and lengths.
 */
 
int main(int argc, char** argv) {
    
    printf("Hello World\n");
    printf("The program name is ' %s '\n", programName);
    printf("The length of the program name is %d\n", strlength(programName));
    printf("The number of command line parameters: %d\n", argc);
    
    // Looping through each command line parameter and displaying its length.
    for (int i = 1; i < argc; ++i) {
        printf("The length of parameter %d is: %d\n", i, strlength(argv[i]));
    }

    return 0;
}








