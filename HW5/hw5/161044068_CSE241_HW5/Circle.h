#ifndef CIRCLE_H
#define CIRCLE_H

#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include <iostream>
#include <fstream>
#define PI 3.141818

using namespace std;
class Triangle;
class Rectangle;
class Circle : public Shape{
public:
    //Constructor
    Circle();
    Circle(int num);
    Circle(int num,double coordX,double coordY);
    //Virtual function
    virtual double area()const override {return PI *(double)(this->getSize() * this->getSize());}
    virtual double perimeter()const override { return 2 * PI * this->getSize();}
    virtual void print(ostream& out, int a)const;
        
private:
    
};

#endif /* CIRCLE_H */