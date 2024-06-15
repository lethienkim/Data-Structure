/**************************
    Name: Thienkim Le
    Assignment: 3
    File: sphere.h
    Purpose of the file: This is a header file for the Sphere class, derived from the Circle class.
    It contains declarations for Sphere's members.
***************************/
#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"
#include <cmath>

class Sphere : public Circle {
	/*******************************
 	Sphere class, derived from the Circle class, represents a three-dimensional sphere in space.
 	It inherits the properties of a Circle and extends functionality to calculate volume. 
 	********************************/
public:
	/*
    *Constructors/Destructor
 	*/
    Sphere();
    Sphere(double);
    ~Sphere();

    /*
     * Getters
     */
    double getRadius();
    double getVolume();
    double getArea();
    

    /*
     * Setters
     */
    void setRadius(double);
    void setVolume(double);

private:
    //private variables that define a sphere (from a circle)
    double radius;


};

#endif //CLASSES_SPHERE_H