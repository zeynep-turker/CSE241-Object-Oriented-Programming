#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"
#include <iostream>
#include <fstream>

using namespace std;
class Triangle;
class Circle;
class Rectangle : public Shape {
public:
    //Constructor
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int w, int h, double coordX, double coordY);
    //Setter and Getter
    void setHeight(int h);
    inline int getHeight()const { return height; }
    //Virtual function
    virtual double area()const { return ((double)(this->getSize() * this->getHeight())); }
    virtual double perimeter()const { return ((double)((2.0*this->getSize()) + (2.0*getHeight()))); }
    virtual void print(ostream& out, int a)const;
    private:
    int height;
};

#endif /* RECTANGLE_H */
