#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>


class ComposedShape {
public:
    ComposedShape(Rectangle *outer, Rectangle *inner);
    ComposedShape(Rectangle *outer, Circle *inner);
    ComposedShape(Rectangle *outer, Triangle *inner);
    ComposedShape(Circle *outer, Rectangle *inner);
    ComposedShape(Circle *outer, Circle *inner);
    ComposedShape(Circle *outer, Triangle *inner);
    ComposedShape(Triangle *outer, Rectangle *sinner);
    ComposedShape(Triangle *outer, Circle *inner);
    ComposedShape(Triangle *outer, Triangle *inner);
    void drawShape(ofstream &File);
    inline vector<Rectangle> getRectSmallShapesVector() const { return *vRect;}
    inline vector<Circle> getCircSmallShapesVector() const { return *vCirc;}
    inline vector<Triangle> getTriSmallShapesVector() const { return *vTri;}
     
private:
    void optimalFit();/*optimal fit fonksiyonu drawShape fonksiyonunun içinde çağırılır bu yüzden de kullanıcının optimal fit fonksiyonunu çağırmaya ihtiyacı olmadığı için private yaptım.*/
    Rectangle *rOuter=nullptr,*rInner=nullptr; /*mainden gelecek iç ve dış şeklin atanacaği private değişkenler.*/
    Circle *cOuter=nullptr,*cInner=nullptr;
    Triangle *tOuter=nullptr,*tInner=nullptr;
    vector<Rectangle> *vRect; /*main container in içine gelecek şekilleri tutması için vektör pointeri tanımladım.vektörleri,rOuter,rInner,cOuter gibi değişkenleri pointer olarak tanımladım çünkü */	
    vector<Circle> *vCirc;	/*secilmemiş diğer şekiller için bos yere  hafızada yer alınmasını istemedim.*/
    vector<Triangle> *vTri;

};

#endif /* COMPOSEDSHAPE_H */
