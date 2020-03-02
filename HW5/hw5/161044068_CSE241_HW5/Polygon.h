#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"
using std::ostream;

namespace PolygonNameSpace{
    class Polygon : public Shape{
    public:
        Polygon(){}
        class Point2D {
        public:
            Point2D():x(0),y(0){}
            inline double getCoordX()const{ return x; }
            inline double getCoordY()const{ return y; }
            void setCoordX(double CoordX){
                x=CoordX;
            }
            void setCoordY(double CoordY){
                y=CoordY;
            }
            void setCoord(double CoordX,double CoordY){
                x=CoordX;
                y=CoordY;
            }
            
        private:
            double x,y;
        };
        void setCoord2(double coordX, double coordY){
                x2=coordX;y2=coordY;
        }
        void setCoord3(double coordX, double coordY){
                x3=coordX;y3=coordY;
        }
        void setHeight(int height){ h=height;}
        inline double getHeight()const { return h; }
        inline double getCoordX2()const { return x2; }
        inline double getCoordY2()const { return y2; }
        inline double getCoordX3()const { return x3; }
        inline double getCoordY3()const { return y3; }
        virtual void printPolygon(ostream& out,vector<Shape*> v)=0;
    private:
        int h;
        double x2,x3,y2,y3;
    };
}

#endif /* POLYGON_H */
