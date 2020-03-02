#include "Polygon.h"
#include "Rectangle.h"
#include <cstdlib>
#include <cmath>
#define PI  3,1416 
using std::ostream;
using std::string;
using std::vector;

namespace PolygonNameSpace{
    Polygon::Polygon():size(0),capacity(50){
        v=new Point2D[capacity];
    }
    Polygon::Polygon(int num):size(0),capacity(num){
        v=new Point2D[capacity];
    }
    Polygon::Polygon(vector<Point2D> vect){
        size = vect.size();
        capacity = vect.capacity();
        v=new Point2D[capacity];
        for(int i=0; i<size; i++){
            v[i].setCoordX(vect[i].getCoordX());
            v[i].setCoordY(vect[i].getCoordY());
        }
        this->setMaxCoords();
    }
    Polygon::Polygon(Point2D coord){
        capacity = 100;
        v=new Point2D[capacity];
        v[0].setCoordX(coord.getCoordX());
        v[0].setCoordY(coord.getCoordY());
        size=1;
        this->setMaxCoords();
    }
    Polygon::Polygon(const Rectangle &rect){
        capacity = 100;
        v=new Point2D[capacity];
        v[0].setCoord(rect.getPosition().x,rect.getPosition().y);
        v[1].setCoord(rect.getPosition().x+rect.getWidth(),rect.getPosition().y);
        v[2].setCoord(rect.getPosition().x+rect.getWidth(),rect.getPosition().y+rect.getHeight());
        v[3].setCoord(rect.getPosition().x,rect.getPosition().y+rect.getHeight());
        size=4;  
        this->setMaxCoords();
    }
    Polygon::Polygon(const Triangle &tri){
        capacity = 100;
        v=new Point2D[capacity];
        v[0].setCoord(tri.getPositionT1().x,tri.getPositionT1().y);
        v[1].setCoord(tri.getPositionT2().x,tri.getPositionT2().y);
        v[2].setCoord(tri.getPositionT3().x,tri.getPositionT3().y);
        size=3;
        this->setMaxCoords();
    }
    Polygon::Polygon(const Circle& circ){
        capacity = 200;
        v=new Point2D[capacity];
        for(int i=0; i<100; i++){
            double angle=3.6*i*(PI/180);
            v[i].setCoord(circ.getPosition().x+circ.getSize()*cos(angle),circ.getPosition().y+circ.getSize()*sin(angle));
        } 
        size=100;
        this->setMaxCoords();
    }
    Polygon::Polygon(const Polygon& other){
        capacity=other.getCapacity();
        size = other.getSize();
        v = new Point2D[capacity];
        for (int i = 0; i < size; ++i)
            v[i] = other.getArray()[i];
        this->setMaxCoords();
    }
    const Polygon & Polygon::operator= (const Polygon & other){
        if (capacity != other.getCapacity()){
            delete [] v;
            v = new Point2D[other.getCapacity()];
        }
        capacity = other.getCapacity();
        size = other.getSize();
        for (int i = 0; i < size; i++)
            v[i] = other.getArray()[i];
        this->setMaxCoords();
        return *this;
    }
    Polygon::~Polygon( ){
        delete [] v;
        v=NULL;
    }

    Polygon::Point2D& Polygon::operator [](int index){
        if(index<0 || index>=size)
            exit(1);
        else
            return v[index];
    }
    bool Polygon::operator==(const Polygon& otherPolygon) const{
        if(this->size != otherPolygon.size)
            return false;

        for(int i=0; i<this->size; ++i){
            if(this->getArray()[i].getCoordX() != otherPolygon.getArray()[i].getCoordX() ||
               this->getArray()[i].getCoordY() != otherPolygon.getArray()[i].getCoordY())
                return false;
        }
        return true;
    }
    bool Polygon::operator!=(const Polygon& otherPolygon) const{
        if(this->size != otherPolygon.size)
            return true;

        for(int i=0; i<this->size; ++i){
            if(this->getArray()[i].getCoordX() != otherPolygon.getArray()[i].getCoordX() ||
               this->getArray()[i].getCoordY() != otherPolygon.getArray()[i].getCoordY())
                return true;
        }
        return false;
    }
    Polygon Polygon::operator +(const Polygon& otherPolygon) const{
        int i,j,k=0;
        Polygon newPolygon;
        newPolygon.capacity = this->getCapacity() + otherPolygon.getCapacity();
        newPolygon.size = this->getSize() + otherPolygon.getSize();
        for(i=0; i<this->getSize(); i++){
            (newPolygon.v)[i].setCoordX(this->getArray()[i].getCoordX());
            (newPolygon.v)[i].setCoordY(this->getArray()[i].getCoordY());
        }
        for(j=i; j<this->getSize()+newPolygon.getSize(); j++,k++){
            (newPolygon.v)[j].setCoordX(otherPolygon.getArray()[k].getCoordX());
            (newPolygon.v)[j].setCoordY(otherPolygon.getArray()[k].getCoordY());
        }
        newPolygon.setMaxCoords();
        return newPolygon;
    }
    ostream& operator<<(ostream &out, const Polygon& polygon){
        string str="xmlns=\"http://wwww.w3.org/2000/svg\">";
        out<<"<svg version=\"1.1\" "<<"baseProfile=\"full\"";
        out<<" width=\""<<polygon.getMaxX()*2<<"\" height=\""<<polygon.getMaxY()*2<<"\" ";
        out<<str;
        out<<"<polygon points=\"";
        for(int i=0; i<polygon.getSize(); ++i){
            out<<polygon.getArray()[i].getCoordX()<<",";
            out<<polygon.getArray()[i].getCoordY()<<" ";
        }
        out<<"\" fill=\"red\" />";
        out<<"</svg>";
        return out;
    }
    ostream& operator<<(ostream &out, const vector<Polygon> vect){
        for(int i=0; i<vect.size(); ++i){
            out<<"<polygon points=\"";
            for(int j=0; j<vect[i].getSize(); ++j){
                out<<vect[i].getArray()[j].getCoordX()<<",";
                out<<vect[i].getArray()[j].getCoordY()<<" ";
            }
            out<<"\" fill=\"green\" />";
        }
    }
    void Polygon::setMaxCoords(){
        this->maxX = this->getArray()[0].getCoordX();
        this->maxY = this->getArray()[0].getCoordY();
        for(int i=1; i<this->getSize(); ++i){
            if(maxX < this->getArray()[i].getCoordX())
                maxX = this->getArray()[i].getCoordX();     
            if(maxY < this->getArray()[i].getCoordY())
                maxY = this->getArray()[i].getCoordY();
        }
    }
}
