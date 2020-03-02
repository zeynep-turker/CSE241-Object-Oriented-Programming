#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "myExceptionClass.h"
#include <fstream>
#include <sstream>

using std::ofstream;
using std::vector;
using std::cout;
using std::string;
using std::endl;
using PolygonNameSpace::Polygon;
using polyDyn::PolygonDyn;
using polyVect::PolygonVect;
namespace {
    ostream& operator<<(ostream& out, const Shape& shape){
       shape.print(out,1);
        return out;
    }
}

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
vector<Polygon*> convertAll(vector<Shape*> shape){
    vector<Polygon*> v;
    for(int i=0; i<shape.size(); ++i){
        Polygon *a = new PolygonVect;
        if(dynamic_cast<Rectangle*>(shape[i])){
            a->setSize(dynamic_cast<Rectangle*>(shape[i])->getSize());
            a->setHeight(dynamic_cast<Rectangle*>(shape[i])->getHeight());
            a->setCoord1(dynamic_cast<Rectangle*>(shape[i])->getCoordX(),dynamic_cast<Rectangle*>(shape[i])->getCoordY());     
        }
        else if(dynamic_cast<Circle*>(shape[i])){
            a->setSize(dynamic_cast<Circle*>(shape[i])->getSize());
            a->setCoord1(dynamic_cast<Circle*>(shape[i])->getCoordX(),dynamic_cast<Circle*>(shape[i])->getCoordY());
        }
        else if(dynamic_cast<Triangle*>(shape[i])){
            a->setSize(dynamic_cast<Triangle*>(shape[i])->getSize());
            a->setCoord1(dynamic_cast<Triangle*>(shape[i])->getCoordX(),dynamic_cast<Triangle*>(shape[i])->getCoordY());
            a->setCoord2(dynamic_cast<Triangle*>(shape[i])->getCoordX2(),dynamic_cast<Triangle*>(shape[i])->getCoordY2());
            a->setCoord3(dynamic_cast<Triangle*>(shape[i])->getCoordX3(),dynamic_cast<Triangle*>(shape[i])->getCoordY3());
        }
        v.push_back(a);
    }
    return v;
}
void printPoly(vector<Shape*> shape, ostream& out,bool isDyn){ // isDyn true olursa PolygonDyn classı kullanılarak polygonlar print edilecek ,
    if(isDyn == true){                                          //false olursa PolygonVect classı kullanılarak polygonlar print edilecek.
        PolygonDyn a;
        a.printPolygon(out,shape);
    }
    else{
        PolygonVect a;
        a.printPolygon(out,shape);
    }
}
void sortAll(vector<Shape*> *shape){
    Shape* temp;
    for(int i=0; i<shape->size(); ++i){
        for(int j=i+1; j<shape->size(); ++j){
            if((*shape)[i]->area() > (*shape)[j]->area()){
                temp=(*shape)[i];
                (*shape)[i]=(*shape)[j];
                (*shape)[j]=temp;
            }
        }
    }
}
int main(int argc, char** argv) {
    try{
    ofstream file;   
    Rectangle *rect=new Rectangle(857,685);
    Rectangle *rect2=new Rectangle(43,25); 
    Triangle *tri=new Triangle(526);
    Triangle *tri2=new Triangle(21);
    Circle *circ=new Circle(475);
    Circle *circ2=new Circle(18);
   
    cout<<endl<<endl;
    //Pre Incrementing Overloading Test
    cout<<"********* Using Pre Incrementing Operator Overloading *********"<<endl;
    cout<<"for rect :"<<endl;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    ++(*rect);
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    cout<<"for circ :"<<endl;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    ++(*circ);
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    cout<<"for tri :"<<endl;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    ++(*tri);
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    cout<<endl<<endl;
    
    //Post Incrementing Overloading Test
    cout<<"********* Using Post Incrementing Operator Overloading *********"<<endl;
    cout<<"for rect :"<<endl;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    (*rect)++;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    cout<<"for circ :"<<endl;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    (*circ)++;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    cout<<"for tri :"<<endl;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    (*tri)++;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;   
    cout<<endl<<endl;
    
    //Pre Decrementing Overloading Test--(*rect);
    cout<<"********* Using Pre Decrementing Operator Overloading *********"<<endl;
    cout<<"for rect :"<<endl;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    --(*rect);
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    cout<<"for circ :"<<endl;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    --(*circ);
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    cout<<"for tri :"<<endl;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    --(*tri);
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    cout<<endl<<endl;
    
    //Post Decrementing Overloading Test
    cout<<"********* Using Post Decrementing Operator Overloading *********"<<endl;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    (*rect)--;
    cout<<"x = "<<rect->getCoordX()<<" y = "<<rect->getCoordY()<<endl;
    cout<<"for circ :"<<endl;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    (*circ)--;
    cout<<"x = "<<circ->getCoordX()<<" y = "<<circ->getCoordY()<<endl;
    cout<<"for tri :"<<endl;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    (*tri)--;
    cout<<"x1 = "<<tri->getCoordX()<<" y1 = "<<tri->getCoordY()<<" x2 = "<<tri->getCoordX2()<<" y2 "<<tri->getCoordY2()<<" x3 = "<<tri->getCoordX3()<<" y3 = "<<tri->getCoordY3()<<endl;
    cout<<endl<<endl;
    
    //Area() and Perimeter() Function Test
    cout<<"********* Using area() and perimeter() Function *********"<<endl;
    cout<<"rect's area => "<<rect->area()<<endl;
    cout<<"circ's area => "<<circ->area()<<endl;
    cout<<"tri's area => "<<tri->area()<<endl;
    
    cout<<"rect's perimeter => "<<rect->perimeter()<<endl;
    cout<<"circ's perimeter => "<<circ->perimeter()<<endl;
    cout<<"tri's perimeter => "<<tri->perimeter()<<endl;
    cout<<endl<<endl;
    
    //== and != Operator Overloading Test
    cout<<"********* Using == and != Operator Overloading *********"<<endl;
    if(rect->area() == circ->area())
        cout<<"Rect and Circ's areas are same.."<<endl;
    if(rect->area() != circ->area())
        cout<<"Rect and Circ's areas are not same.."<<endl;
    if(rect->perimeter() == circ->perimeter())
        cout<<"Rect and Circ's perimeters are same.."<<endl;
    if(rect->perimeter() != circ->perimeter())
        cout<<"Rect and Circ's perimeters are not same.."<<endl;    
    cout<<endl<<endl;
    //<< Operator Overloading Test with ComposedShape  
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
  
   for(int j=0; j<9; j++){
       file.open(FileName("ComposedShape ").c_str());
       file<<*cArr[j];
       file.close();
   }
    cout<<endl<<endl;
    //convertAll Function Testing
    cout<<"********* Using convertAll Function *********"<<endl;
    Rectangle * shape1 = new Rectangle(13,5);
    Triangle * shape2 = new Triangle(50);
    ComposedShape *c = new ComposedShape(shape2,shape1);
    cout<<"vector<Shape*>'s coordXs and coordYs : "<<endl;
    for(int i=0; i<c->getShapesVect().size(); ++i)
        cout<<"v["<<i<<"]'s coordX= "<<c->getShapesVect()[i]->getCoordX()<<" v["<<i<<"]'s coordY= "<<c->getShapesVect()[i]->getCoordY()<<endl;
    vector<Polygon*> p = convertAll(c->getShapesVect());
    cout<<endl;
    cout<<"After convert from vector<Shape*> to vector<Polygon*>"<<endl<<endl;
    cout<<"vector<Polygon*>'s coordXs and coordYs : "<<endl;
    for(int i=0; i<p.size(); ++i)
        cout<<"p["<<i<<"]'s coordX= "<<p[i]->getCoordX()<<" p["<<i<<"]'s coordY= "<<p[i]->getCoordY()<<endl;
    cout<<endl<<endl;
    
    //printPoly Function Testing
    Circle * s1 = new Circle(25);
    Rectangle * s2 = new Rectangle(250,100);
    Rectangle * s3 = new Rectangle(13,5);
    Triangle * s4 = new Triangle(500);
    ComposedShape *c1 = new ComposedShape(s2,s1);
    ComposedShape *c2 = new ComposedShape(s4,s3);
    file.open(FileName("printPolyTesting with PolygonDyn ").c_str());
    printPoly((c1->getShapesVect()),file,true);
    file.close();
    file.open(FileName("printPolyTesting with PolygonVect ").c_str());
    printPoly((c2->getShapesVect()),file,false);
    file.close();
    
    
    //SortAll Function Testing
    cout<<"********* Using sortAll Function *********"<<endl<<endl;
    Shape * ss1 = new Rectangle(10,5);
    Shape * ss2 = new Rectangle(9,5);
    Shape * ss3 = new Rectangle(8,5);
    Shape * ss4 = new Rectangle(7,5);
    vector<Shape*> s;
    s.push_back(ss1); 
    s.push_back(ss2);
    s.push_back(ss3); 
    s.push_back(ss4);
    
    for(int i=0; i<s.size(); ++i)
    cout<<"s["<<i<<"]'s Area = "<<s[i]->area()<<" ";
    sortAll(&s);
    cout<<endl<<"After sort.."<<endl;
    for(int i=0; i<s.size(); ++i)
        cout<<"s["<<i<<"]'s Area = "<<s[i]->area()<<" ";
    cout<<endl<<endl;
    
    //Exception Testing
    PolygonDyn test(1,2);
    test[-2];
    PolygonVect test2(1,2);
    test[-3];
    }
    catch(IndexOutOfRangeException& a){ 
        cerr<<"Exception Test : "<<a.what()<<endl;
    }
    return 0;
}

