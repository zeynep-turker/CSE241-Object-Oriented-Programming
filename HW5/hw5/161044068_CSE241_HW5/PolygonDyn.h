#ifndef POLYGONDYN_H
#define POLYGONDYN_H
#include "Polygon.h"
#include "Shape.h"
#include "myExceptionClass.h"
using namespace PolygonNameSpace;
namespace polyDyn{
    class PolygonDyn : public Polygon{
    public:
        PolygonDyn();
        PolygonDyn(int num);
        PolygonDyn(double x,double y);
        inline int getUsed()const{ return used; }
        inline int getCapacity()const{ return capacity; }
        inline Point2D *getArray()const{ return p; }
        //Big Three
        PolygonDyn(const PolygonDyn& other);
        PolygonDyn& operator=(const PolygonDyn& other);
        ~PolygonDyn();
        //Virtual functions
        Point2D* convert(Shape* shape);
        Point2D &operator[](int index);
        virtual double area()const{return 0;}
        virtual double perimeter()const{return 0;}     
        virtual void print(ostream& out,int a)const{};
        virtual void printPolygon(ostream& out,vector<Shape*> v);
    private:
        Point2D *p;
        int used;
        int capacity;
    };
}
#endif /* POLYGONDYN_H */

