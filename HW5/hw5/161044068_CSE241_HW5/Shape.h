#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape {
public:
    //Constructor
    Shape();
    Shape(int size);
    Shape(int size, double coordX, double coordY);
    //Setter and Getter
    void setSize(int size);
    void setCoordX(double coordX);
    void setCoordY(double coordY);
    void setCoord1(double coordX, double coordY);
    inline int getSize()const { return line; }
    inline double getCoordX()const { return coordx; }
    inline double getCoordY()const { return coordy; }
    //Pure virtual function
    virtual double area()const=0;
    virtual double perimeter()const=0;
    //Virtual function
    virtual Shape& operator++();
    virtual Shape& operator++(int temp);
    virtual Shape& operator--();
    virtual Shape& operator--(int temp);
 
    bool operator==(const Shape &otherShape) const;
    bool operator!= (const Shape &otherShape) const;
    virtual void print(ostream& out,int a)const=0;
    
private:
    int line;
    double coordx,coordy;
};

#endif /* SHAPE_H */

