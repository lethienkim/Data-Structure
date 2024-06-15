/**************************
    Name: Thienkim Le
    Assignment: 3
    File:   circle.h
    Purpose of the file: This is a header file for the Circle class, containing declarations for its members.
***************************/

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#include <cmath>
#define MIN 0

class Circle {
 	/*********************************************
    This class defines a Cirlce. It has two constructors
    and can be instantiated with a default radius or with
    a caller assigned radius.

    @attrib radius : the radius of the circle
    *********************************************/
    public:
    /*
     * constructors
     * one with no params, one with params (overloading)
     */
    Circle();
    Circle(double r);

    /*
	destructor (not used in this example)
	*/
    ~Circle();

    /*
     * Getters
     */
    double getArea() const;
    double getRadius() const;
      
    /*
     * Setters
     */
    void setRadius(double r);
   

protected:
    //private variables that define a circle
    double radius;

};

#endif //CLASSES_CIRCLE_H
