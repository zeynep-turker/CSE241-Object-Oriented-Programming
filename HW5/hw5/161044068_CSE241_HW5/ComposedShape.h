#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"
#include <vector>

class Rectangle;
class Circle;
class Triangle;
class ComposedShape : public Shape{
public:
    //Constructors
    ComposedShape(Rectangle *outer, Rectangle *inner);
    ComposedShape(Rectangle *outer, Circle *inner);
    ComposedShape(Rectangle *outer, Triangle *inner);
    ComposedShape(Circle *outer, Rectangle *inner);
    ComposedShape(Circle *outer, Circle *inner);
    ComposedShape(Circle *outer, Triangle *inner);
    ComposedShape(Triangle *outer, Rectangle *sinner);
    ComposedShape(Triangle *outer, Circle *inner);
    ComposedShape(Triangle *outer, Triangle *inner);
    inline vector<Shape*> getShapesVect()const { return shapes; }
    
    //Virtual Function
    virtual double area()const override { return this->area(); }
    virtual double perimeter()const override { return this->perimeter(); }
    virtual void print(ostream& out, int a)const;
   
    void optimalFit();
  
private:
    Rectangle *rOuter=nullptr,*rInner=nullptr; /*mainden gelecek iç ve dış şeklin atanacaği private değişkenler.*/
    Circle *cOuter=nullptr,*cInner=nullptr;
    Triangle *tOuter=nullptr,*tInner=nullptr;   
    vector<Shape*> shapes,a;
};

#endif /* COMPOSEDSHAPE_H */