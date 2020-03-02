#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle():Shape(),height(50){}
Rectangle::Rectangle(int w, int h):Shape(w),height(h){}
Rectangle::Rectangle(int w, int h, double coordX, double coordY):Shape(w,coordX,coordY),height(h){}
void Rectangle::setHeight(int h){
    height=h;
}
void Rectangle::print(ostream& out, int a)const{
    if(a == 1){
        out<<"<rect x=\""<<this->getCoordX()<<"\" "<<"y=\""<<this->getCoordY()<<"\" width=\""
            <<this->getSize()<<"\" height=\""<<this->getHeight()<<"\" "<<"fill=\"green\" />"; 
    }
    else{
        out<<"<rect x=\""<<this->getCoordX()<<"\" "<<"y=\""<<this->getCoordY()<<"\" width=\""
            <<this->getSize()<<"\" height=\""<<this->getHeight()<<"\" "<<"fill=\"red\" />"; 
    }
}