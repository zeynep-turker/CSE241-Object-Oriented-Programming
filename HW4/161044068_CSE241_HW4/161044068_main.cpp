#include <iostream>
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include <fstream>
#include <sstream>

using std::ofstream;
using std::vector;
using std::cout;
using std::string;
using std::endl;
using PolygonNameSpace::Polygon;

namespace {
    string FileName(string str) { /*art arta oluşacak svg dosyalarının silinmesini istemediğim için her dosya kapandığında açılan dosyanın ismini değiştirmek için statik bir int değişkeni tutarak bu int i */
        static int i=1; /*her fonksiyona girildiğinde artırıp string yapıp "result" stringi ile birleştirerek yeni bir dosya ismi elde ettim.*/
        stringstream s;
        s << i;
        ++i;
        string text ="result" + s.str() + "(" + str + ")" + ".svg";   
        return text;
    }
}
int main(int argc, char** argv) {

    ofstream file;
    //Vector Definitons..
    vector<Polygon::Point2D> *v1,*v2,*v3,*v4,*v5;
    v1 = new vector<Polygon::Point2D>(8);
    v2 = new vector<Polygon::Point2D>(4);
    v3 = new vector<Polygon::Point2D>(5);
    v4 = new vector<Polygon::Point2D>(4);
    v5 = new vector<Polygon::Point2D>(4);
    //Vector Definitions 
    (*v1)[0].setCoord(50,5);
    (*v1)[1].setCoord(100,5);
    (*v1)[2].setCoord(125,30);
    (*v1)[3].setCoord(125,80);
    (*v1)[4].setCoord(100,105);
    (*v1)[5].setCoord(50,105);
    (*v1)[6].setCoord(25,80);
    (*v1)[7].setCoord(25,30);
    Polygon p1(*v1);
    //---*---*---*---*---*---*---
    (*v2)[0].setCoord(0,100);
    (*v2)[1].setCoord(50,25);
    (*v2)[2].setCoord(50,75);
    (*v2)[3].setCoord(100,0);
    Polygon p2(*v2);
    //---*---*---*---*---*---*---
    (*v3)[0].setCoord(100,10);
    (*v3)[1].setCoord(40,198);
    (*v3)[2].setCoord(190,78);
    (*v3)[3].setCoord(10,78);
    (*v3)[4].setCoord(160,198);
    Polygon p3(*v3);
    //---*---*---*---*---*---*---
    (*v4)[0].setCoord(20,10);
    (*v4)[1].setCoord(50,20);
    (*v4)[2].setCoord(130,100);
    (*v4)[3].setCoord(70,140);
    Polygon p4(*v4);
    //---*---*---*---*---*---*---
    (*v5)[0].setCoord(0,0);
    (*v5)[1].setCoord(120,0);
    (*v5)[2].setCoord(120,80);
    (*v5)[3].setCoord(0,80);
    Polygon p5(*v5);
    
    //Array Definition
    Polygon pArr[5]={p1,p2,p3,p4,p5};
    
    //Rectangle-Triangle-Circle Shapes
    Rectangle *rect=new Rectangle(857,685);
    Rectangle *rect2=new Rectangle(43,25);
    Triangle *tri=new Triangle(526);
    Triangle *tri2=new Triangle(21);
    Circle *circ=new Circle(475);
    Circle *circ2=new Circle(18);
    
    //ComposedShape Array Definition
    ComposedShape *(cArr[9]);
    cArr[0] = new ComposedShape(rect,rect2);
    cArr[1] = new ComposedShape(rect,tri2);
    cArr[2] = new ComposedShape(rect,circ2);
    cArr[3] = new ComposedShape(tri,rect2);
    cArr[4] = new ComposedShape(tri,tri2);
    cArr[5] = new ComposedShape(tri,circ2);
    cArr[6] = new ComposedShape(circ,tri2);
    cArr[7] = new ComposedShape(circ,rect2);
    cArr[8] = new ComposedShape(circ,circ2);
    
    //<< Operator Testing
    for(int i=0; i<5; i++){
        file.open(FileName("polygon ").c_str());
        file<<pArr[i];
        file.close();
    }
    for(int j=0; j<9; j++){
       file.open(FileName("composedShape ").c_str());
       file<<*cArr[j];
       file.close();
    }
    
    //Rectangle Conversion Constructor Testing
    Rectangle r(300,250);
    Polygon obj=r;
    file.open(FileName("rectConversionConstructor ").c_str());
    file<<obj;
    file.close();
    
    //Triangle Conversion Constructor Testing
    Triangle t(100);
    Polygon obj2=t;
    file.open(FileName("triConversionConstructor ").c_str());
    file<<obj2;
    file.close();
    
    //Circle Conversion Constructor Testing
    Circle c(250);
    Polygon obj3=c;
    file.open(FileName("circConversionConstructor ").c_str());
    file<<obj3;
    file.close();
    
    //Point2D Conversion Constructor Testing
    Polygon::Point2D point;
    point.setCoord(100,85);
    Polygon obj4 = point;
    file.open(FileName("point2dConversionConstructor ").c_str());
    file<<obj4;
    file.close();
    
    //[] OPERATOR TESTING
    cout<<"---[] OPERATOR TESTING---\n";
    for(int k=0; k<8; k++){
        cout<<"pArr[0]'s v1["<<k<<"] 's x coord = "<<pArr[0].getArray()[k].getCoordX()<<" y coord = "<<pArr[0].getArray()[k].getCoordY()<<endl;
    }
 
    cout<<endl;
    //== OPERATOR TESTING
    Rectangle temp(120,80);
    Polygon tempPoly=temp;
    cout<<"--- == And != OPERATOR TESTING---\n";
    if( pArr[0] == pArr[1])
        cout<<"pArr[0] and pArr[1] are equal!"<<endl;
    else
        cout<<"pArr[0] and pArr[1] are not equal!"<<endl;
    if(pArr[4] != tempPoly)
        cout<<"pArr[4] and tempPoly are not equal!"<<endl;
    else
        cout<<"pArr[4] and tempPoly are equal!"<<endl;
    
    // + OPERATOR TESTING
    Polygon newPolygon=pArr[0]+pArr[4];
    file.open(FileName("newPolygon ").c_str());
    file<<newPolygon;
    file.close();
    
    //Polyline Definition
    vector<Polygon::Point2D> *k;
    k= new vector<Polygon::Point2D>(7);
    (*k)[0].setCoord(0,40);
    (*k)[1].setCoord(40,40);
    (*k)[2].setCoord(40,80);
    (*k)[3].setCoord(80,80);
    (*k)[4].setCoord(80,120);
    (*k)[5].setCoord(120,120);
    (*k)[6].setCoord(120,160);
    Polygon poly(*k);
    Polyline obj5=poly;
    file.open(FileName("polyline ").c_str());
    file<<obj5;
    file.close();
    
    //Polyline Examples
    for(int n=0; n<5; n++){
        Polyline obj6=pArr[n];
        file.open(FileName("polyline ").c_str());
        file<<obj6;
        file.close();
    }
 
    return 0;
}

