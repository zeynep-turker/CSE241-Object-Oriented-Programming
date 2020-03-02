#ifndef CIRCLE_H
#define CIRCLE_H
#include "structs.h"
#include <iostream>
#include <fstream>

using namespace std;

class Circle {
public:
    Circle(){};
    Circle(int num);
    Circle(double coordX,double coordY);
    void setSize(int num);
    void setPositionX(double coordX);
    void setPositionY(double coordY);
    inline int getSize() const {
        return radius;
    };
    inline Coords getPosition() const {
        return coords;
    }
    void drawCirc(ofstream &file,bool isSingle);/*isSingle değişkeninin true oldupğu durumlarda tek bir daire bastırılır.*/
private:
    int radius;
    Coords coords;

};

#endif /* CIRCLE_H */

