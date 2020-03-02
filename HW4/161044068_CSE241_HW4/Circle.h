#ifndef CIRCLE_H
#define CIRCLE_H
#include "structs.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <fstream>

using namespace std;
class Triangle;
class Rectangle;
class Circle {
public:
    Circle(){};
    Circle(int num);
    Circle(int num,double coordX,double coordY);
    void setSize(int num);
    void setPositionX(double coordX);
    void setPositionY(double coordY);
    inline int getSize() const { return radius; }
    inline Coords getPosition() const { return coords; }
    
    //GET AREA AND GET PERIMETER FUNCTIONS
    
    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }
    
    //OPERATOR OVERLOADING
    
    friend ostream& operator<<(ostream &out, const Circle &circ);
    Circle operator++();
    Circle operator++(int temp);
    Circle operator--();
    Circle operator--(int temp);
    Circle operator+(double size)const;
    Circle operator-(double size)const;
    bool operator==(const Circle &circ)const;
    bool operator==(const Rectangle &rect) const;
    bool operator==(const Triangle &tri) const;
    bool operator!= (const Circle &circ) const;
    bool operator!= (const Rectangle &rect) const;
    bool operator!= (const Triangle &tri) const;
    bool operator<(const Circle &circ) const;
    bool operator<(const Rectangle &rect) const;
    bool operator<(const Triangle &tri) const;
    bool operator>(const Circle &circ) const; 
    bool operator>(const Rectangle &rect) const;
    bool operator>(const Triangle &tri) const;
    bool operator<=(const Circle &circ) const;
    bool operator<=(const Rectangle &rect) const;
    bool operator<=(const Triangle &tri) const;
    bool operator>=(const Circle &circ) const;
    bool operator>=(const Rectangle &rect) const;
    bool operator>=(const Triangle &tri) const;
    
    //STATIC FUNCTION
    
    inline static double getAreas(){ return totalArea; }
    inline static double getPerimeters(){ return totalPerimeter; }
    
private:
    int radius;
    Coords coords;
    double area,perimeter;
    static double  totalArea;
    static double totalPerimeter;

};

#endif /* CIRCLE_H */