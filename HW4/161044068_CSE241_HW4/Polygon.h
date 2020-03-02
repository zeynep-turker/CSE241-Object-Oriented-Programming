#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using std::ostream;

namespace PolygonNameSpace{
    class Polygon {
    public:
        class Point2D {
        public:
            Point2D():x(0),y(0){}
            inline int getCoordX()const{ return x; }
            inline int getCoordY()const{ return y; }
            void setCoordX(int CoordX){
                x=CoordX;
            }
            void setCoordY(int CoordY){
                y=CoordY;
            }
            void setCoord(int CoordX,int CoordY){
                x=CoordX;
                y=CoordY;
            }
        private:
            int x,y;
        };
        Polygon();
        Polygon(int num);
        Polygon(vector<Point2D> vect);
        Polygon(Point2D coord);
        Polygon(const Rectangle &rect);
        Polygon(const Triangle &tri);
        Polygon(const Circle &circ);
        Polygon (const Polygon & other);
        const Polygon & operator= (const Polygon & other);
        ~Polygon();
        Point2D &operator[](int index);
        inline int getSize()const{ return size; }
        inline int getCapacity()const{ return capacity; }
        inline Point2D *getArray()const{ return v; }
        bool operator==(const Polygon &otherPolygon) const;
        bool operator!=(const Polygon &otherPolygon) const;
        Polygon operator+(const Polygon& otherPolygon )const;
        friend ostream& operator<<(ostream &out, const Polygon& polygon);
        friend ostream& operator<<(ostream &out, const vector<Polygon> vect);
        void setMaxCoords();
        inline int getMaxX()const{ return maxX; }
        inline int getMaxY()const{ return maxY; }
    private:
        Point2D *v;
        int size;
        int capacity;
        int maxX,maxY;
    };
}

#endif /* POLYGON_H */

