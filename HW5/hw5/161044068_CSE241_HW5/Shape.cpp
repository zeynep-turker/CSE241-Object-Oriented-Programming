#include "Shape.h"

Shape::Shape():line(100){}
Shape::Shape(int size):line(size){}
Shape::Shape(int size, double coordX, double coordY):line(size),coordx(coordX),coordy(coordY){}
void Shape::setSize(int size){
    line=size;
}
void Shape::setCoordX(double coordX){
    coordx=coordX;
}
void Shape::setCoordY(double coordY){
    coordy=coordY;
}
void Shape::setCoord1(double coordX, double coordY){
    coordx=coordX;
    coordy=coordY;
}
bool Shape::operator ==(const Shape& otherShape) const{
    return (this->area() == otherShape.area());
}
bool Shape::operator !=(const Shape& otherShape) const{
    return (this->area() != otherShape.area());
}
Shape& Shape::operator ++(){
    this->setCoord1(this->getCoordX()+1,this->getCoordY()+1);
    return *this;
}
Shape& Shape::operator ++(int temp){
    Shape &newShape = *this;
    this->setCoord1(this->getCoordX()+1,this->getCoordY()+1); 
    return newShape;
}
Shape& Shape::operator --(){
    this->setCoord1(this->getCoordX()-1,this->getCoordY()-1); 
    return *this;
}
Shape& Shape::operator --(int temp){
    Shape &newShape = *this;
    this->setCoord1(this->getCoordX()-1,this->getCoordY()-1);  
    return newShape;
}
void Shape::print(ostream& out,int a)const{
}
