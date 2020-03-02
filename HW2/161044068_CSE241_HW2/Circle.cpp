#include "Circle.h"
Circle::Circle(int num) {
    radius=num;
}
Circle::Circle(double coordX,double coordY) {
    coords.x=coordX;
    coords.y=coordY;
}
void Circle::setSize(int num){
    radius=num;
}
void Circle::setPositionX(double coordX){
    coords.x=coordX;
}

void Circle::setPositionY(double coordY){
    coords.y=coordY; 
}

void Circle::drawCirc(ofstream &file,bool isSingle){
    if(isSingle == true){/*isSingle değişkeni true olursa svg bu if te başlar ve burda biter tek bir daire çizilir.*/
        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
        file<<"width=\""<<radius*2<<"\" height=\""<<radius*2<<"\"";
        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
        file<<"<circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\"" <<radius<<"\" "<<"fill=\"red\" />";
        file<<"</svg>";
        file.close();
    }
    else{/*isSingle değişkeni false olduğunda main containerin içine çizilebilecek dairelerden biri için svg kodu yazılır.*/
        file<<"<circle cx=\""<<coords.x<<"\" cy=\""<<coords.y<<"\" r=\""
        <<radius<<"\" "<<"fill=\"green\" />";
    }    
        
}
