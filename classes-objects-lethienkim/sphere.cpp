
/**************************
    Name: Thienkim Le
    Assignment: 3
    File: sphere.cpp
    Purpose of the file: This file defines the member functions of the Sphere class, derived from the Circle class.
***************************/


#include "sphere.h"

Sphere::Sphere() {
	/**
 	* Constructor: Initializes a Sphere object with a default radius.
 	* Use your own setters!
 	*/
    setRadius(MIN);
}

Sphere::Sphere(double r) {
	/**
 	* Constructor: Initializes a Sphere object with the given radius.
	 * Use your own setters!
	 * 
	 * @param (double) r : radius of the sphere
 	*/
    setRadius(r);
}

Sphere::~Sphere() {
	/**
 	* Destructor: Destroys the Sphere object.
 	*/
}

double Sphere::getRadius() {
	/*********************************************
 	Calculates and returns the radius of the Sphere,
 	which is inherited from the Circle base class.

 	@return double : Radius of the Sphere
	*********************************************/
	
    return Circle::getRadius();
}

double Sphere::getVolume() {
	/*********************************************
 	Sets the radius of the Sphere, utilizing the setter in the base class Circle.
 	The function accepts a double value representing the new radius and ensures it is non-negative.
 	It then sets the radius using the inherited setRadius function from the Circle class.
 
 	@param r : new radius value to be set
 
 	@note If the provided radius (r) is negative, it is set to the minimum value (0).
 	*********************************************/
    return ((4.0 / 3.0) * 3.14159 * pow(getRadius(), 3));
}

void Sphere::setRadius(double r) {
	/*********************************************
 	Sets the radius of the Sphere, ensuring it meets a minimum value.
 	This function is responsible for updating the radius attribute of the Sphere,
 	invoking the corresponding setter in the base class Circle.
 
 	@param r : New radius value to be set

 	@return void
 
 	@note This function enforces a minimum value for the radius.
 	*********************************************/
    Circle::setRadius(r);
}


void Sphere::setVolume(double r) {
	/*********************************************
 	Sets the volume of the Sphere by adjusting its radius.
 	It internally calls the setRadius function from the base Circle class.
 
	@param r : New radius to be set for the Sphere
 
 	@return void
 
 	@note The volume is indirectly affected by modifying the radius,
 	as the volume is calculated based on the Sphere's radius.
 	********************************************/
    Circle::setRadius(r);
}