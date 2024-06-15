/**************************
    Name: Thienkim Le
    Assignment: 3
    File:   circle.cpp
    Purpose of the file: Implementation file for the Circle class
 	Defines the member functions for creating, manipulating, and accessing properties of Circle objects.
***************************/
    
#include "circle.h"

Circle::Circle() {
	 /**
 	* Constructor: Initializes a Circle object with a default radius.
 	* Use your own setters!
 	*/
    setRadius(MIN);
}

Circle::Circle(double r) {
	/**
 	* Constructor: Initializes a Circle object with the given radius.
	 * Use your own setters!
	 * 
	 * @param (double) r : radius of the circle
 	*/
    setRadius(r);
}

Circle::~Circle() {
	/**
 	* Destructor: Destroys the Circle object.
 	*/
}

double Circle::getRadius() const {
	/*************************************
	Retrieves and returns the radius of the Circle.
 	This function provides direct access to the private member radius.
 
 	@return radius : The radius of the Circle
 	**************************************/
    return radius;
}
double Circle::getArea() const {
	/****************************
 	Calculates and returns the area of the Circle using the formula:
 
 	@return double : Area of the Circle
 	
 	@note The formula used assumes the radius is a valid non-negative value.
 	*****************************/
    return (3.14159 * pow(radius, 2));
}

void Circle::setRadius(double r) {
	/**************************
 	Setter function for the Circle class, responsible for setting the radius attribute.
 	Ensures that the provided radius is greater than the predefined minimum value (MIN).
	If the given radius is less than or equal to MIN, sets the radius to MIN for protection.

 	@param r : The value to be set as the radius.

	@return : None

 	@note : Setters are crucial for maintaining data integrity and protecting class attributes.
 	In this case, the radius is constrained to be at least MIN.
 	****************************/
    if (r > MIN) {
        radius = r;
    } else {
        radius = MIN;
    }
}
