#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "structs.h"
#include <iostream>
#include <fstream>

using namespace std;

class Rectangle {
public: 
    Rectangle(){};
    Rectangle(int Width, int Height);
    Rectangle(int Width, int Height, double coordX, double coordY);
    void setSize(int Width, int Height);
    void setPositionX(double coordX);
    void setPositionY(double coordY);
    inline int getWidth() const {
        return width;
    };
    inline int getHeight() const {
        return height;
    }
    inline Coords getPosition() const {
        return coords;
    }
    void drawRect(ofstream &file,bool isSingle);/*isSingle değişkeninin true oldupğu durumlarda tek bir dikdörtgen bastırılır.*/
private:
    int width,height;
    Coords coords;
};

#endif /* RECTANGLE_H */

