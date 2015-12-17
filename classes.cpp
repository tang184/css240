#include <iostream>
#include "problem_classes.h"

#define PI 3.14159265

// DO NOT CHANGE OR MODIFY ANYTHING HERE

Triangle::Triangle( int base, int height )
{
    this->base = base;
    this->height = height;
}

double Triangle::getArea()
{
    return ( 0.5 * base * height );
}

Square::Square( int sideLength )
{
    this->sideLength = sideLength;
}

double Square::getArea()
{
    return sideLength * sideLength;
}

Circle::Circle( int radius )
{
    this->radius = radius; 
}

double Circle::getArea()
{
    return PI * radius * radius; 
}
