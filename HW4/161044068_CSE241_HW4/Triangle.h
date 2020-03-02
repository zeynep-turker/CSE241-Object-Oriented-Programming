#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Circle.h"
#include <iostream>
#include <fstream>
#include "structs.h"
#include "Rectangle.h"
#include <cmath>

using namespace std;
class Circle;
class Rectangle;
class Triangle {
public:
    Triangle(){};
    Triangle(int Line);
    Triangle(int Line,Coords t1, Coords t2, Coords t3);
    Triangle(Coords t1, Coords t2, Coords t3);
    Triangle(int Line,double t1X, double t1Y, double t2X, double t2Y, double t3X, double t3Y);
    void setSize(int num);
    void setPositionT1(double coordX, double coordY);
    void setPositionT2(double coordX, double coordY);
    void setPositionT3(double coordX, double coordY);
    inline int getSize() const { return line; }
    inline Coords getPositionT1() const { return T1; }
    inline Coords getPositionT2() const { return T2; }
    inline Coords getPositionT3() const { return T3; }
    
    //GET AREA AND GET PERIMETER FUNCTIONS
    
    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }
    
    //OPERATOR OVERLOADING
    
    friend ostream& operator<<(ostream &out, const Triangle &tri);
    Triangle operator++();
    Triangle operator++(int temp);
    Triangle operator--();
    Triangle operator--(int temp);
    Triangle operator+(double size)const;
    Triangle operator-(double size)const;
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
    int line;
    Coords T1,T2,T3; /*üçgenin her köşesinin koordinatlarını Coords structının tipinde yaptım.Coords structının içinde x ve y değişkenleri vardır.*/
    double area,perimeter;
    static double totalArea;
    static double totalPerimeter;
   
};

#endif /* TRIANGLE_H */