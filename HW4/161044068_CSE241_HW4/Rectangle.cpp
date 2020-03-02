#include "Rectangle.h"

double Rectangle::totalArea = 0.0;
double Rectangle::totalPerimeter =0.0;

Rectangle::Rectangle(int Width, int Height) {
    width = Width;
    height = Height;
    area = (double)(width * height);
    perimeter = (double)((2.0*width) + (2.0*height));
    totalArea += area;
    totalPerimeter +=perimeter;
    setPositionX(0);
    setPositionY(0);
}
Rectangle::Rectangle(int Width, int Height, double coordX, double coordY) {
    width = Width;
    height = Height;
    coords.x = coordX;
    coords.y = coordY;
    area = (double)(width * height);
    perimeter = (double)((2.0*width) + (2.0*height));
    totalArea += area;
    totalPerimeter +=perimeter;
}
void Rectangle::setSize(int num, int num2) {
    width=num;
    height=num2;
    area = (double)(width * height);
    perimeter = (double)((2.0*width) + (2.0*height));
    totalArea += area;
    totalPerimeter +=perimeter;
    setPositionX(0);
    setPositionY(0);
}
void Rectangle::setPositionX(double coordX) {
    coords.x=coordX;
}
void Rectangle::setPositionY(double coordY) {
    coords.y=coordY;
}
ostream& operator<<(ostream &out, const Rectangle &rect) {
    out<<"<rect x=\""<<rect.getPosition().x<<"\" "<<"y=\""<<rect.getPosition().y<<"\" width=\""
            <<rect.getWidth()<<"\" height=\""<<rect.getHeight()<<"\" "<<"fill=\"green\" />";
    return out;
}
Rectangle Rectangle::operator++(){
    coords.x = coords.x + 1.0;
    coords.y = coords.y + 1.0;
    return Rectangle(width,height,coords.x,coords.y);
}
Rectangle Rectangle::operator++(int temp){
    double x = coords.x;
    double y = coords.y;
    coords.x = coords.x + 1.0;
    coords.y = coords.y + 1.0;
    return Rectangle(width,height,x,y);
}
Rectangle Rectangle::operator--(){
    coords.x = coords.x - 1.0;
    coords.y = coords.y - 1.0;
    return Rectangle(width,height,coords.x,coords.y);
}
Rectangle Rectangle::operator--(int temp){
    double x = coords.x;
    double y = coords.y;
    coords.x = coords.x - 1.0;
    coords.y = coords.y - 1.0;
    return Rectangle(width,height,x,y);
}
Rectangle Rectangle::operator+(double size)const{
    Rectangle rect;
    rect.setSize(this->width + size, this->height + size);
    return rect;
}
Rectangle Rectangle::operator-(double size)const{
    if(this->width - size < 0 || this->height - size < 0 )
        cout<<"New circle's radius is smaller than zero.Please try again..\n";
    else {
        Rectangle rect;
        rect.setSize(this->width - size, this->height - size);
        return rect;
    }  
}
bool Rectangle::operator==(const Circle &circ) const{
    return (this->getArea() == circ.getArea()); 
}
bool Rectangle::operator==(const Rectangle &rect) const{
    return (this->getArea() == rect.getArea()); 
}
bool Rectangle::operator==(const Triangle &tri) const{
    return (this->getArea() == tri.getArea()); 
}
bool Rectangle::operator!=(const Circle &circ) const{
    return (this->getArea() != circ.getArea());
}
bool Rectangle::operator!=(const Rectangle &rect) const{
    return (this->getArea() != rect.getArea());
}
bool Rectangle::operator!=(const Triangle &tri) const{
    return (this->getArea() != tri.getArea());
}
bool Rectangle::operator<(const Circle &circ) const{
    return (this->getArea() < circ.getArea());
}
bool Rectangle::operator<(const Rectangle &rect) const{
    return (this->getArea() < rect.getArea());
}
bool Rectangle::operator<(const Triangle &tri) const{
    return (this->getArea() < tri.getArea());
}
bool Rectangle::operator>(const Circle &circ) const{
    return (this->getArea() > circ.getArea());
}
bool Rectangle::operator>(const Rectangle &rect) const{
    return (this->getArea() > rect.getArea());
}
bool Rectangle::operator>(const Triangle &tri) const{
    return (this->getArea() > tri.getArea());
}
bool Rectangle::operator<=(const Circle &circ) const{
    return (this->getArea() <= circ.getArea());
}
bool Rectangle::operator<=(const Rectangle &rect) const{
    return (this->getArea() <= rect.getArea());
}
bool Rectangle::operator<=(const Triangle &tri) const{
    return (this->getArea() <= tri.getArea());
}
bool Rectangle::operator>=(const Circle &circ) const{
    return (this->getArea() >= circ.getArea());
}
bool Rectangle::operator>=(const Rectangle &rect) const{
    return(this->getArea() >= rect.getArea());
}
bool Rectangle::operator>=(const Triangle &tri) const{
    return (this->getArea() >= tri.getArea());
}
//void Rectangle::drawRect(ofstream& file,bool isSingle){
//    if(isSingle == true){/*isSingle degiskeni true olursa svg bu if te başlar ve burda biter tek bir dikdörtgen çizilir.*/
//        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
//        file<<"width=\""<<width<<"\" height=\""<<height<<"\"";
//        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
//        file<<"<rect x=\"0\" y=\"0\" "<<"width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\" />";
//        file<<"</svg>";
//        file.close();
//    }    
//    else{    /*isSingle değişkeni false olduğunda main containerin içine çizilebilecek dikdörtgenlerden biri için svg kodu yazılır.*/
//        file<<"<rect x=\""<<coords.x<<"\" "<<"y=\""<<coords.y<<"\" width=\""
//            <<width<<"\" height=\""<<height<<"\" "<<"fill=\"green\" />";
//    }    
//}
