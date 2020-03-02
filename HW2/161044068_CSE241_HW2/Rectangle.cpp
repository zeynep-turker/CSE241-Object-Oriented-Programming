#include "Rectangle.h"
Rectangle::Rectangle(int Width, int Height) {
    width = Width;
    height = Height;
}
Rectangle::Rectangle(int Width, int Height, double coordX, double coordY) {
    width = Width;
    height = Height;
    coords.x = coordX;
    coords.y = coordY;
}
void Rectangle::setSize(int num, int num2) {
    width=num;
    height=num2;
}
void Rectangle::setPositionX(double coordX) {
    coords.x=coordX;
}
void Rectangle::setPositionY(double coordY) {
    coords.y=coordY;
}
void Rectangle::drawRect(ofstream& file,bool isSingle){
    if(isSingle == true){/*isSingle değişkeni true olursa svg bu if te başlar ve burda biter tek bir dikdörtgen çizilir.*/
        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
        file<<"width=\""<<width<<"\" height=\""<<height<<"\"";
        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
        file<<"<rect x=\"0\" y=\"0\" "<<"width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\" />";
        file<<"</svg>";
        file.close();
    }    
    else{    /*isSingle değişkeni false olduğunda main containerin içine çizilebilecek dikdörtgenlerden biri için svg kodu yazılır.*/
        file<<"<rect x=\""<<coords.x<<"\" "<<"y=\""<<coords.y<<"\" width=\""
            <<width<<"\" height=\""<<height<<"\" "<<"fill=\"green\" />";
    }    
}
