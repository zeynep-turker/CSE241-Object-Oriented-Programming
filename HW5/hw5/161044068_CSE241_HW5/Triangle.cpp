#include "Triangle.h"
#include "Shape.h"


Triangle::Triangle():Shape(){}
Triangle::Triangle(int line):Shape(line){}
Triangle::Triangle(int line,double x1,double y1,double x2,double y2,double x3,double y3):Shape(line,x1,y1){
    coordx2=x2;
    coordy2=y2;
    coordx3=x3;
    coordy3=y3;
}
void Triangle::setCoord2(double coordX, double coordY){
    coordx2=coordX;
    coordy2=coordY;
}
void Triangle::setCoord3(double coordX, double coordY){
    coordx3=coordX;
    coordy3=coordY;
}
Shape& Triangle::operator ++(){
    this->setCoord1(this->getCoordX()+1,this->getCoordY()+1);
    this->setCoord2(coordx2+1,coordy2+1);
    this->setCoord3(coordx3+1,coordy3+1); 
    return *this;
}
Shape& Triangle::operator ++(int temp){
    Shape &newShape = *this;
    this->setCoord1(this->getCoordX()+1,this->getCoordY()+1);
    this->setCoord2(coordx2+1,coordy2+1);
    this->setCoord3(coordx3+1,coordy3+1); 
    return newShape;
}
Shape& Triangle::operator --(){
    this->setCoord1(this->getCoordX()-1,this->getCoordY()-1);
    this->setCoord2(coordx2-1,coordy2-1);
    this->setCoord3(coordx3-1,coordy3-1);
    return *this;
}
Shape& Triangle::operator --(int temp){
    Shape &newShape = *this;
    this->setCoord1(this->getCoordX()-1,this->getCoordY()-1);
    this->setCoord2(coordx2-1,coordy2-1);
    this->setCoord3(coordx3-1,coordy3-1);
    return newShape;
}

void Triangle::print(ostream& out, int a)const{
    if(a == 1){
    out<<"<polygon points=\""<<this->getCoordX()<<","<<this->getCoordY()<<" "
        <<this->getCoordX2()<<","<<this->getCoordY2()<<" "<<this->getCoordX3()
	<<","<<this->getCoordY3()<<"\" "<<"fill=\"green\"/>";
    }
    else{
        out<<"<polygon points=\""<<this->getCoordX()<<","<<this->getCoordY()<<" "
        <<this->getCoordX2()<<","<<this->getCoordY2()<<" "<<this->getCoordX3()
	<<","<<this->getCoordY3()<<"\" "<<"fill=\"red\"/>";
    }
}