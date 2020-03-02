#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "structs.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>
#include <fstream>

using namespace std;
class Triangle;
class Circle;
class Rectangle {
public: 
    Rectangle(){};
    Rectangle(int Width, int Height);
    Rectangle(int Width, int Height, double coordX, double coordY);
    void setSize(int Width, int Height);
    void setPositionX(double coordX);
    void setPositionY(double coordY);
    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }
    inline Coords getPosition() const { return coords; }
    
    //GET AREA AND GET PERIMETER FUNCTIONS

    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }
    
    //OPERATOR OVERLOADING
    
    friend ostream& operator<<(ostream &out, const Rectangle &rect);
    Rectangle operator++();
    Rectangle operator++(int temp);
    Rectangle operator--();
    Rectangle operator--(int temp);
    Rectangle operator+(double size)const;
    Rectangle operator-(double size)const;
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
    inline static double getAreas(){ return totalArea; }
    inline static double getPerimeters(){ return totalPerimeter; }
private:
    int width,height;
    Coords coords;
    double area,perimeter;
    static double totalArea;
    static double totalPerimeter;
};

#endif /* RECTANGLE_H */
