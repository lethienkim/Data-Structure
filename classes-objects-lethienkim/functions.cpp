/**************************
    Name: Thienkim Le
    Assignment: 3
    File:   functions.cpp
    Purpose of the file: This file defines functions to display the area of a Circle and the volume of a Sphere.
***************************/
    
#include "functions.h"

void displayArea(Circle *myCircle){
	/*********************************************
 	Displays the area of a Circle object.
  	It calls the getRadius() method to obtain the radius of the Circle,
  	calculates the area using the formula
 	and prints the result to the console.
 
 	@param myCircle : Pointer to the Circle object
 
 	@return void
 
 	@note The function assumes that myCircle is a valid Circle object.
 	*********************************************/
	double area = myCircle->getRadius();
    std::cout << area << std::endl;
    std::cout << std::endl;

}


void displayVolume(Sphere *mySphere){
	/*********************************************
 	Calculates and displays the volume of a Sphere.
 	Accepts a Sphere object, retrieves its volume using getVolume(),
 	and prints the result to the standard output.

 	@param mySphere : Pointer to a Sphere object

 	@return void
 
  	@note If the Sphere object is not properly initialized, the result may not be accurate.
 	*********************************************/
	double volume = mySphere -> getVolume();
    std::cout << volume<< std::endl;
    std::cout << std::endl;

}
