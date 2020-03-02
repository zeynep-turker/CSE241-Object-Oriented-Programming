#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <fstream>
#include "structs.h"

using namespace std;

class Triangle {
public:
    Triangle(){};
    Triangle(int Line);
    Triangle(int Line,Coords t1, Coords t2, Coords t3);
    Triangle(int Line,double t1X, double t1Y, double t2X, double t2Y, double t3X, double t3Y);
    void setSize(int num);
    void setPositionT1(double coordX, double coordY);
    void setPositionT2(double coordX, double coordY);
    void setPositionT3(double coordX, double coordY);
    inline int getSize() const {
        return line;
    };
    inline Coords getPositionT1() const {
        return T1;
    }
    inline Coords getPositionT2() const {
        return T2;
    }
    inline Coords getPositionT3() const {
        return T3;
    }
    void drawTri(ofstream &file,bool isSingle); /*isSingle değişkeninin true oldupğu durumlarda tek bir üçgen bastırılır.*/
private:
    int line;
    Coords T1,T2,T3; /*üçgenin her köşesinin koordinatlarını Coords structının tipinde yaptım.Coords structının içinde x ve y değişkenleri vardır.*/
};

#endif /* TRIANGLE_H */

