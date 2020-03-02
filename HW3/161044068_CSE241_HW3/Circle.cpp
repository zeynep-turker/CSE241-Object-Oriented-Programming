#include "Circle.h"
#define PI 3.141818

using namespace std;

double Circle::totalArea = 0.0;
double Circle::totalPerimeter =0.0;

Circle::Circle(int num) {
    radius=num;
    area=PI *(double)(radius * radius);
    perimeter = 2 * PI * radius;
    totalArea += area;
    totalPerimeter +=perimeter;
}
Circle::Circle(int num,double coordX,double coordY) {
    radius=num;
    coords.x=coordX;
    coords.y=coordY;
}
void Circle::setSize(int num){
    radius=num;
    area=PI *(double)(radius * radius);
    perimeter = 2.0 * PI * (double)(radius);
    totalArea = totalArea + area;
    totalPerimeter = totalPerimeter + perimeter;
}
void Circle::setPositionX(double coordX){
    coords.x=coordX;
}

void Circle::setPositionY(double coordY){
    coords.y=coordY; 
}
ostream& operator<<(ostream &out, const Circle &circ) {
    out<<"<circle cx=\""<<circ.getPosition().x<<"\" cy=\""<<circ.getPosition().y<<"\" r=\""
        <<circ.getSize()<<"\" "<<"fill=\"green\" />";
    return out;
}
Circle Circle::operator++(){
    coords.x = coords.x + 1.0;
    coords.y = coords.y + 1.0;
    return Circle(radius,coords.x,coords.y);
}
Circle Circle::operator++(int temp){
    double x = coords.x;
    double y = coords.y;
    coords.x = coords.x + 1.0;
    coords.y = coords.y + 1.0;
    return Circle(radius,x,y);
}
Circle Circle::operator--(){
    coords.x = coords.x - 1.0;
    coords.y = coords.y - 1.0;
    return Circle(radius,coords.x,coords.y);
}
Circle Circle::operator--(int temp){
    double x = coords.x;
    double y = coords.y;
    coords.x = coords.x - 1.0;
    coords.y = coords.y - 1.0;
    return Circle(radius,x,y);
}
Circle Circle::operator+(double size)const{
    Circle circ;
    circ.setSize(this->radius + size);
    return circ;
}
Circle Circle::operator-(double size)const{
    if(this->radius - size < 0)
        cout<<"New circle's radius is smaller than zero.Please try again..\n";
    else {
        Circle circ;
        circ.setSize(this->radius - size);
        return circ;
    }  
}
bool Circle::operator==(const Circle &circ) const{
    return (this->getArea() == circ.getArea()); 
}
bool Circle::operator==(const Rectangle &rect) const{
    return (this->getArea() == rect.getArea()); 
}
bool Circle::operator==(const Triangle &tri) const{
    return (this->getArea() == tri.getArea()); 
}
bool Circle::operator!= (const Circle &circ) const{
    return (this->getArea() != circ.getArea());
}
bool Circle::operator!= (const Rectangle &rect) const{
    return (this->getArea() != rect.getArea());
}
bool Circle::operator!= (const Triangle &tri) const{
    return (this->getArea() != tri.getArea());
}
bool Circle::operator<(const Circle &circ) const{
    return (this->getArea() < circ.getArea());
}
bool Circle::operator<(const Rectangle &rect) const{
    return (this->getArea() < rect.getArea());
}
bool Circle::operator<(const Triangle &tri) const{
    return (this->getArea() < tri.getArea());
}
bool Circle::operator>(const Circle &circ) const{
    return (this->getArea() > circ.getArea());
}
bool Circle::operator>(const Rectangle &rect) const{
    return (this->getArea() > rect.getArea());
}
bool Circle::operator>(const Triangle &tri) const{
    return (this->getArea() > tri.getArea());
}
bool Circle::operator<=(const Circle &circ) const{
    return (this->getArea() <= circ.getArea());
}
bool Circle::operator<=(const Rectangle &rect) const{
    return (this->getArea() <= rect.getArea());
}
bool Circle::operator<=(const Triangle &tri) const{
    return (this->getArea() <= tri.getArea());
}
bool Circle::operator>=(const Circle &circ) const{
    return (this->getArea() >= circ.getArea());
}
bool Circle::operator>=(const Rectangle &rect) const{
    return(this->getArea() >= rect.getArea());
}
bool Circle::operator>=(const Triangle &tri) const{
    return (this->getArea() >= tri.getArea());
}
//void Circle::drawCirc(ofstream &file,bool isSingle){
//    if(isSingle == true){/*isSingle değişkeni true olursa svg bu if te başlar ve burda biter tek bir daire çizilir.*/
//        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
//        file<<"width=\""<<radius*2<<"\" height=\""<<radius*2<<"\"";
//        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
//        file<<"<circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\"" <<radius<<"\" "<<"fill=\"red\" />";
//        file<<"</svg>";
//        file.close();
//    }
//    else{/*isSingle değişkeni false olduğunda main containerin içine çizilebilecek dairelerden biri için svg kodu yazılır.*/
//        file<<"<circle cx=\""<<coords.x<<"\" cy=\""<<coords.y<<"\" r=\""
//        <<radius<<"\" "<<"fill=\"green\" />";
//    }    
//        
//}
