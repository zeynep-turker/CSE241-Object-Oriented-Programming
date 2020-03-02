#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include <vector>
using PolygonNameSpace::Polygon;

class ComposedShape {
public:
    ComposedShape(Rectangle *outer, Rectangle *inner);
    ComposedShape(Rectangle *outer, Circle *inner);
    ComposedShape(Rectangle *outer, Triangle *inner);
    ComposedShape(Circle *outer, Rectangle *inner);
    ComposedShape(Circle *outer, Circle *inner);
    ComposedShape(Circle *outer, Triangle *inner);
    ComposedShape(Triangle *outer, Rectangle *sinner);
    ComposedShape(Triangle *outer, Circle *inner);
    ComposedShape(Triangle *outer, Triangle *inner);
    inline vector<Polygon> getPolygonVector() const { return *polygon;}
    void optimalFit();
    friend ostream& operator<<(ostream &out, const ComposedShape &shape);

     
private:
    Rectangle *rOuter=nullptr,*rInner=nullptr;
    Circle *cOuter=nullptr,*cInner=nullptr;
    Triangle *tOuter=nullptr,*tInner=nullptr;
    vector<Polygon> *polygon;

};

#endif /* COMPOSEDSHAPE_H */