#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>

class Rectangle;
class Circle;
class Triangle;
class ComposedShape {
public:
    class ShapeElem;
    ComposedShape(Rectangle *outer, Rectangle *inner);
    ComposedShape(Rectangle *outer, Circle *inner);
    ComposedShape(Rectangle *outer, Triangle *inner);
    ComposedShape(Circle *outer, Rectangle *inner);
    ComposedShape(Circle *outer, Circle *inner);
    ComposedShape(Circle *outer, Triangle *inner);
    ComposedShape(Triangle *outer, Rectangle *sinner);
    ComposedShape(Triangle *outer, Circle *inner);
    ComposedShape(Triangle *outer, Triangle *inner);
    void optimalFit();
    friend ostream& operator<<(ostream &out, const ComposedShape &shape);
    ShapeElem &operator[](int i);
    inline vector<ShapeElem> getShapes()const {return vShape; }
    
    //Inner Public Class
    
    class ShapeElem {
    public:
        ShapeElem(){}
        ShapeElem(Rectangle r){ /*constructor ile gelen small shape i aldım ve << operatörü ile büyük şeklin içine çizdirdim.*/
            shape=&r;
            rect=r;
            which = whichShape::Rect;
        }    
        ShapeElem(Circle c){
            shape=&c;        
            circ=c;
            which = whichShape::Circ;
        }    
        ShapeElem(Triangle t){
            shape=&t;
            tri=t;
            which = whichShape::Tri;
        }
        friend ostream& operator<<(ostream &out, const ShapeElem &shapes){
            if(shapes.getType() == whichShape::Rect){
                out<<shapes.getRectangle();
            }
            else if(shapes.getType() == whichShape::Circ){   
                out<<shapes.getCircle();
            }
            else{
                out<<shapes.getTriangle();
            }
            return out;
        }
        double getArea()const;
        double getPerimeter()const;
        Circle getCircle()const { return circ; }
        Rectangle getRectangle()const { return rect; }
        Triangle getTriangle()const { return tri; }
        whichShape getType()const { return which; }
    private:
        void *shape;
        whichShape which;
        Circle circ;
        Rectangle rect;
        Triangle tri;
    };
     
private:
  
    Rectangle *rOuter=nullptr,*rInner=nullptr; /*mainden gelecek iç ve dış şeklin atanacaği private değişkenler.*/
    Circle *cOuter=nullptr,*cInner=nullptr;
    Triangle *tOuter=nullptr,*tInner=nullptr;   
    vector<ShapeElem> vShape;
};

#endif /* COMPOSEDSHAPE_H */