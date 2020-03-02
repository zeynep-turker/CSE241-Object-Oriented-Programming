#ifndef POLYGONVECT_H
#define POLYGONVECT_H
#include "Polygon.h"
#include "myExceptionClass.h"
#include <iostream>
#include <vector>
using PolygonNameSpace::Polygon;

using namespace std;
using PolygonNameSpace::Polygon;
namespace polyVect{
    class PolygonVect : public Polygon {
    public:
        PolygonVect();
        PolygonVect(double x,double y);
        inline vector<Point2D> getVect()const { return v; }
        Point2D &operator[](int index);
        vector<Point2D> convert(Shape* shape);
        virtual double area()const{return 0;}
        virtual double perimeter()const{return 0;}
        virtual void print(ostream& out,int a)const{}
        virtual void printPolygon(ostream& out,vector<Shape*> v);
    private:
        vector<Point2D> v;
    };
}
#endif /* POLYGONVECT_H */

