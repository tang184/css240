#ifndef PROBLEM_CLASSES_H
#define PROBLEM_CLASSES_H

// Problem (1/4)
/******************************************************************************
 * TODO: Create a parent class called Shape. Shape should have a pure virtual
 * function called getArea that returns a double. The shape function should be
 * purely virtual because what is the area of a shape?
 *****************************************************************************/
 class Shape {
 	public :
 	//enum FigureType {Triangle, Square, Circle};
 	virtual double getArea() {};

 };

// Problem (2/4)
/******************************************************************************
 * TODO: Create a Triangle class which inherits Shape. The Triangle class
 * should have two instance variables of base and height (both are integers). 
 * Declare a constructor and getArea() function which returns a double. 
 *****************************************************************************/
class Triangle : public Shape{
	public :
	Triangle (int base, int height);
	int base;
	int height;
	double getArea();

};
// Problem (3/4)
/******************************************************************************
 * TODO: Create a Square class which inherits Shape. The Sqaure class
 * should have one instance variable of sideLength. sideLength is an integer.
 * Declare a constructor and getArea() function which returns a double. 
 *****************************************************************************/
class Square : public Shape{
	public :
	Square( int sideLength );
	int sideLength;
	double getArea();
	
};
// Problem (4/4)
/******************************************************************************
 * TODO: Create a Circle class which inherits Shape. The Circle class
 * should have one instance variable of radius. radius is an integer.
 * Declare a constructor and getArea() function which returns a double. 
 *****************************************************************************/
 class Circle : public Shape{
	public :
	Circle( int radius );
	int radius;
	double getArea();
};

#endif
