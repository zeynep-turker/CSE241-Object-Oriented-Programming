#include "Circle.h"
#include "Shape.h"

using namespace std;

Circle::Circle():Shape(){}
Circle::Circle(int num):Shape(num){}
Circle::Circle(int num,double coordX,double coordY):Shape(num,coordX,coordY){}
void Circle::print(ostream& out, int a)const {
    if(a == 1){
    out<<"<circle cx=\""<<this->getCoordX()<<"\" cy=\""<<this->getCoordY()<<"\" r=\""
       <<this->getSize()<<"\" "<<"fill=\"green\" />";
    }
    else{
        out<<"<circle cx=\""<<this->getCoordX()<<"\" cy=\""<<this->getCoordY()<<"\" r=\""
            <<this->getSize()<<"\" "<<"fill=\"red\" />";   
    }
}
