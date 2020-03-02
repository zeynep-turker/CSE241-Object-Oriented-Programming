#include "Triangle.h"
#include <cmath>

double Triangle::totalArea = 0.0;
double Triangle::totalPerimeter =0.0;

Triangle::Triangle(int Line) {
    line=Line;
    area = ((double)(line*line)*sqrt(3.0))/4.0;
    perimeter = 3.0 * (double)(line); 
    totalArea += area;
    totalPerimeter +=perimeter;
}
Triangle::Triangle(int Line, Coords t1, Coords t2, Coords t3) {    
    line=Line;
    T1.x = t1.x; T1.y = t1.y;
    T2.x = t2.x; T2.y = t2.y;
    T3.x = t3.x; T3.y = t3.y;
    area = ((double)(line*line)*sqrt(3.0))/4.0;
    perimeter = 3.0 * (double)(line);
    totalArea += area;
    totalPerimeter +=perimeter;
}
Triangle::Triangle(Coords t1, Coords t2, Coords t3) {
    T1.x = t1.x;
    T1.y = t1.y;
    T2.x = t2.x;
    T2.y = t2.y;
    T3.x = t3.x;
    T3.y = t3.y;
}    
Triangle::Triangle(int Line, double t1X, double t1Y, double t2X, double t2Y, double t3X, double t3Y) {
    line=Line;
    T1.x = t1X; T1.y = t1Y;
    T2.x = t2X; T2.y = t2Y;
    T3.x = t3X; T3.y = t3Y;
    area = ((double)(line*line)*sqrt(3.0))/4.0;
    perimeter = 3.0 * (double)(line);
    totalArea += area;
    totalPerimeter +=perimeter;
}
void Triangle::setSize(int num){
    line=num;
    area = ((double)(line*line)*sqrt(3.0))/4.0;
    perimeter = 3.0 * (double)(line);
    totalArea += area;
    totalPerimeter +=perimeter;
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
ostream& operator<<(ostream &out, const Triangle &tri) {
    out<<"<polygon points=\""<<tri.getPositionT1().x<<","<<tri.getPositionT1().y<<" "
        <<tri.getPositionT2().x<<","<<tri.getPositionT2().y<<" "<<tri.getPositionT3().x
	<<","<<tri.getPositionT3().y<<"\" "<<"fill=\"green\"/>";
    return out;
}
Triangle Triangle::operator++(){
    T1.x = T1.x + 1.0; T1.y = T1.y + 1.0;
    T2.x = T2.x + 1.0; T2.y = T2.y + 1.0;
    T3.x = T3.x + 1.0; T3.y = T3.y + 1.0;
    return Triangle(line,T1,T2,T3);
}
Triangle Triangle::operator++(int temp){
    Coords t1,t2,t3;
    t1.x = T1.x; t1.y = T1.y;
    t2.x = T2.x; t2.y = T2.y;
    t3.x = T3.x; t3.y = T2.y;
    T1.x = T1.x + 1.0; T1.y = T1.y + 1.0;
    T2.x = T2.x + 1.0; T2.y = T2.y + 1.0;
    T3.x = T3.x + 1.0; T3.y = T3.y + 1.0;
    return Triangle(line,t1,t2,t3);
}
Triangle Triangle::operator--(){
    T1.x = T1.x - 1.0; T1.y = T1.y - 1.0;
    T2.x = T2.x - 1.0; T2.y = T2.y - 1.0;
    T3.x = T3.x - 1.0; T3.y = T3.y - 1.0;
    return Triangle(line,T1,T2,T3);
}
Triangle Triangle::operator--(int temp){
    Coords t1,t2,t3;
    t1.x = T1.x; t1.y = T1.y;
    t2.x = T2.x; t2.y = T2.y;
    t3.x = T3.x; t3.y = T2.y;
    T1.x = T1.x - 1.0; T1.y = T1.y - 1.0;
    T2.x = T2.x - 1.0; T2.y = T2.y - 1.0;
    T3.x = T3.x - 1.0; T3.y = T3.y - 1.0;
    return Triangle(line,t1,t2,t3);
}
Triangle Triangle::operator+(double size)const{
    Triangle tri;
    tri.setSize(this->line + size);
}
Triangle Triangle::operator-(double size)const{
    if(this->line - size < 0)
        cout<<"New circle's radius is smaller than zero.Please try again..\n";
    else {
        Triangle tri;
        tri.setSize(this->line - size);
        return tri;
    }  
}
bool Triangle::operator==(const Circle &circ) const{
    return (this->getArea() == circ.getArea()); 
}
bool Triangle::operator==(const Rectangle &rect) const{
    return (this->getArea() == rect.getArea()); 
}
bool Triangle::operator==(const Triangle &tri) const{
    return (this->getArea() == tri.getArea()); 
}
bool Triangle::operator!= (const Circle &circ) const{
    return (this->getArea() != circ.getArea());
}
bool Triangle::operator!= (const Rectangle &rect) const{
    return (this->getArea() != rect.getArea());
}
bool Triangle::operator!= (const Triangle &tri) const{
    return (this->getArea() != tri.getArea());
}
bool Triangle::operator<(const Circle &circ) const{
    return (this->getArea() < circ.getArea());
}
bool Triangle::operator<(const Rectangle &rect) const{
    return (this->getArea() < rect.getArea());
}
bool Triangle::operator<(const Triangle &tri) const{
    return (this->getArea() < tri.getArea());
}
bool Triangle::operator>(const Circle &circ) const{
    return (this->getArea() > circ.getArea());
}
bool Triangle::operator>(const Rectangle &rect) const{
    return (this->getArea() > rect.getArea());
}
bool Triangle::operator>(const Triangle &tri) const{
    return (this->getArea() > tri.getArea());
}
bool Triangle::operator<=(const Circle &circ) const{
    return (this->getArea() <= circ.getArea());
}
bool Triangle::operator<=(const Rectangle &rect) const{
    return (this->getArea() <= rect.getArea());
}
bool Triangle::operator<=(const Triangle &tri) const{
    return (this->getArea() <= tri.getArea());
}
bool Triangle::operator>=(const Circle &circ) const{
    return (this->getArea() >= circ.getArea());
}
bool Triangle::operator>=(const Rectangle &rect) const{
    return(this->getArea() >= rect.getArea());
}
bool Triangle::operator>=(const Triangle &tri) const{
    return (this->getArea() >= tri.getArea());
}
//void Triangle::drawTri(ofstream &file,bool isSingle) {
//     if(isSingle == true){ /*isSingle değişkeni true olursa svg bu if te başlar ve burda biter tek bir üçgen çizilir.*/
//        file<<"<svg version=\"1.1\" baseProfile=\"full\" ";
//        file<<"width=\""<<line<<"\" height=\""<<(int)((line/2)*sqrt(3))<<"\"";
//        file<<" xmlns=\"http://wwww.w3.org/2000/svg\">"; 
//        file<<"<polygon points=\""<<(double)(line/2)<<","<<0<<" "<<0<<","<<(double)((line/2)*sqrt(3))
//            <<" "<<line<<","<<(double)((line/2)*sqrt(3))<<"\" "<<"fill=\"red\" />";
//        file<<"</svg>";
//        file.close();
//    }
//    else{ /*isSingle değişkeni false olduğunda main containerin içine çizilebilecek üçgenlerden biri için svg kodu yazılır.*/
//    file<<"<polygon points=\""<<T1.x<<","<<T1.y<<" "
//        <<T2.x<<","<<T2.y<<" "<<T3.x
//	<<","<<T3.y<<"\" "<<"fill=\"green\"/>";
//    }
//}
