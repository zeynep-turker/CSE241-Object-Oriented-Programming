#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Circle.h"
#include "Shape.h"
#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include <cmath>

using namespace std;
class Circle;
class Rectangle;
class Triangle: public Shape{
public:
    //Constructor
    Triangle();
    Triangle(int line);
    Triangle(int line,double x1,double y1,double x2,double y2,double x3,double y3);
    //Setter and Getter
    void setCoord2(double coordX, double coordY);
    void setCoord3(double coordX, double coordY);
    inline double getCoordX2()const { return coordx2; }
    inline double getCoordY2()const { return coordy2; }
    inline double getCoordX3()const { return coordx3; }
    inline double getCoordY3()const { return coordy3; }
    //Virtual function
    virtual double area()const { return ((double)(this->getSize() *this->getSize())*sqrt(3.0)/4.0); }
    virtual double perimeter()const { return (3.0 * (double)(this->getSize()));}
    virtual void print(ostream& out, int a)const;
    Shape& operator++() override;
    Shape& operator++(int temp) override;
    Shape& operator--() override;
    Shape& operator--(int temp) override;
    

private:
    double coordx2,coordy2,coordx3,coordy3;
   
};

#endif /* TRIANGLE_H */
