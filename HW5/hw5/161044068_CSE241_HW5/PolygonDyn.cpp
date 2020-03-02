#include "PolygonDyn.h"
#include <iostream>
namespace polyDyn{
    PolygonDyn::PolygonDyn():used(0),capacity(50){
        p = new Point2D[capacity];
    }
    PolygonDyn::PolygonDyn(int num):used(0),capacity(num){
        p = new Point2D[capacity];
    }
    PolygonDyn::~PolygonDyn(){
        delete [] p;
        p=NULL;
    }
    PolygonDyn::PolygonDyn(double x, double y){
        used=1;
        capacity=10;
        p = new Point2D[capacity];
        p[0].setCoord(x,y);
    }
    PolygonDyn::PolygonDyn(const PolygonDyn& other){
        capacity=other.getCapacity();
        used = other.getSize();
        p = new Point2D[capacity];
        for(int i = 0; i < used; ++i)
            p[i] = other.getArray()[i];
    }
    PolygonDyn& PolygonDyn::operator=(const PolygonDyn& other){
        if (capacity != other.getCapacity()){
            delete [] p;
            p=new Point2D[other.getCapacity()];
        }
        capacity = other.getCapacity();
        used = other.getSize();
        for (int i = 0; i < used; i++)
            p[i] = other.getArray()[i];
        return *this;
    }
    Polygon::Point2D * PolygonDyn::convert(Shape* shape){ // Gelen shape'in köşe noktalarını arraye ekler.
        if(dynamic_cast<Rectangle*>(shape)){
            p = new Polygon::Point2D[50];
            p[0].setCoord(dynamic_cast<Rectangle*>(shape)->getCoordX(),dynamic_cast<Rectangle*>(shape)->getCoordY());
            p[1].setCoord(dynamic_cast<Rectangle*>(shape)->getCoordX()+dynamic_cast<Rectangle*>(shape)->getSize(),dynamic_cast<Rectangle*>(shape)->getCoordY());
            p[2].setCoord(dynamic_cast<Rectangle*>(shape)->getCoordX()+dynamic_cast<Rectangle*>(shape)->getSize(),dynamic_cast<Rectangle*>(shape)->getCoordY()+dynamic_cast<Rectangle*>(shape)->getHeight());
            p[3].setCoord(dynamic_cast<Rectangle*>(shape)->getCoordX(),dynamic_cast<Rectangle*>(shape)->getCoordY()+dynamic_cast<Rectangle*>(shape)->getHeight());
            used=4;
        }
        else if(dynamic_cast<Circle*>(shape)){
            p = new Point2D[150];
            used = 100;
            for(int i=0; i<100; i++){
                double angle=3.6*i*(PI/180);
                p[i].setCoord(dynamic_cast<Circle*>(shape)->getCoordX()+dynamic_cast<Circle*>(shape)->getSize()*cos(angle),dynamic_cast<Circle*>(shape)->getCoordY()+dynamic_cast<Circle*>(shape)->getSize()*sin(angle));
            }
        }
        else if(dynamic_cast<Triangle*>(shape)){
            p = new Point2D[50];
            p[0].setCoord(dynamic_cast<Triangle*>(shape)->getCoordX(),dynamic_cast<Triangle*>(shape)->getCoordY());
            p[1].setCoord(dynamic_cast<Triangle*>(shape)->getCoordX2(),dynamic_cast<Triangle*>(shape)->getCoordY2());
            p[2].setCoord(dynamic_cast<Triangle*>(shape)->getCoordX3(),dynamic_cast<Triangle*>(shape)->getCoordY3());   
            used=3;
        }
        return p;
    }
    Polygon::Point2D& PolygonDyn::operator[](int index){
        if(index<0 || index>used)         
            throw IndexOutOfRangeException();
        return p[index];
    }
    void PolygonDyn::printPolygon(ostream& out,vector<Shape*> v){
        string str="xmlns=\"http://wwww.w3.org/2000/svg\">";
        out<<"<svg version=\"1.1\" "<<"baseProfile=\"full\"";    
        out<<" width=\""<<v[0]->getSize()+50<<"\" height=\""<<v[0]->getSize()+50<<"\" ";
        out<<str;
        for(int i=0; i<v.size(); i++){      
            PolygonDyn a;     
            a.convert(v[i]);        
            out<<"<polygon points=\"";
            for(int j=0; j<a.getUsed(); ++j){        
                out<<a.getArray()[j].getCoordX()<<",";       
                out<<a.getArray()[j].getCoordY()<<" ";
            }
            if(i != 0){
                out<<"\" fill=\"green\" />"; 
            }          
            else{
                out<<"\" fill=\"red\" />"; 
            }   
        }
        out<<"</svg>";
    }
}