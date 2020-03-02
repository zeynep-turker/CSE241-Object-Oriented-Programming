#include "Triangle.h"
#include <cmath>

Triangle::Triangle(int Line) {
    line=Line;
}
Triangle::Triangle(int Line, Coords t1, Coords t2, Coords t3) {    
    line=Line;
    T1.x = t1.x;
    T1.y = t1.y;
    T2.x = t2.x;
    T2.y = t2.y;
    T3.x = t3.x;
    T3.y = t3.y;
}
Triangle::Triangle(int Line, double t1X, double t1Y, double t2X, double t2Y, double t3X, double t3Y) {
    line=Line;
    T1.x = t1X;
    T1.y = t1Y;
    T2.x = t2X;
    T2.y = t2Y;
    T3.x = t3X;
    T3.y = t3Y;
}
void Triangle::setSize(int num){
    line=num;
}
void Triangle::setPositionT1(double coordX, double coordY) {
    T1.x = coordX;
    T1.y = coordY;
}
void Triangle::setPositionT2(double coordX, double coordY) {
    T2.x = coordX;
    T2.y = coordY;
}
void Triangle::setPositionT3(double coordX, double coordY) {
    T3.x = coordX;
    T3.y = coordY;
}
void Triangle::drawTri(ofstream &file,bool isSingle) {
     if(isSingle == true){ /*isSingle değişkeni true olursa svg bu if te başlar ve burda biter tek bir üçgen çizilir.*/
        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
        file<<"width=\""<<line<<"\" height=\""<<(int)((line/2)*sqrt(3))<<"\"";
        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
        file<<"<polygon points=\""<<(double)(line/2)<<","<<0<<" "<<0<<","<<(double)((line/2)*sqrt(3))
            <<" "<<line<<","<<(double)((line/2)*sqrt(3))<<"\" "<<"fill=\"red\" />";
        file<<"</svg>";
        file.close();
    }
    else{ /*isSingle değişkeni false olduğunda main containerin içine çizilebilecek üçgenlerden biri için svg kodu yazılır.*/
    file<<"<polygon points=\""<<T1.x<<","<<T1.y<<" "
        <<T2.x<<","<<T2.y<<" "<<T3.x
	<<","<<T3.y<<"\" "<<"fill=\"green\"/>";
    }
}
