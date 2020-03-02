#include "ComposedShape.h"
#include <fstream>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <cmath>
#include <vector>

using namespace std;

ComposedShape::ComposedShape(Rectangle *outer, Rectangle *inner){
    rOuter = outer;
    rInner = inner;
    optimalFit();
    
}
ComposedShape::ComposedShape(Rectangle *outer, Circle *inner){
    rOuter = outer;
    cInner = inner;
    optimalFit();
}
ComposedShape::ComposedShape(Rectangle *outer, Triangle *inner){
    rOuter = outer;
    tInner = inner;
    optimalFit();
}
ComposedShape::ComposedShape(Circle *outer, Rectangle *inner){
    cOuter = outer;
    rInner = inner;
    optimalFit();
}
ComposedShape::ComposedShape(Circle *outer, Circle *inner){
    cOuter = outer;
    cInner = inner;
    optimalFit();
}
ComposedShape::ComposedShape(Circle *outer, Triangle *inner){
    cOuter = outer;
    tInner = inner;
    optimalFit();
}

ComposedShape::ComposedShape(Triangle *outer, Rectangle *inner){
    tOuter = outer;
    rInner = inner; 
    optimalFit();
}
ComposedShape::ComposedShape(Triangle *outer, Circle *inner){
    tOuter = outer;
    cInner = inner;
    optimalFit();
}
ComposedShape::ComposedShape(Triangle *outer, Triangle *inner){
    tOuter = outer;
    tInner = inner;
    optimalFit();
}

void ComposedShape::optimalFit(){ /*bu fonksiyonda main container ın içine gelebilecek şekil objesinin koordinatları bulunur ve küçük şeklin tipine göre belirlenecek vektöre eklenir.*/
     
    if(rOuter != nullptr){  
        if(rInner != nullptr){
            int i,j,coloumnNum,lineNum;
            coloumnNum=rOuter->getWidth()/rInner->getWidth();
            lineNum=rOuter->getHeight()/rInner->getHeight();
            rInner->setPositionY(0);
            for(i=0; i<lineNum; ++i)
            {
                rInner->setPositionX(0);
                for(j=0; j<coloumnNum; ++j)
                {     
                    vShape.push_back(ShapeElem(*rInner));
                    rInner->setPositionX(rInner->getPosition().x + (double)rInner->getWidth());
                }
                rInner->setPositionY(rInner->getPosition().y + (double)rInner->getHeight());
             }
        }
        else if(cInner != nullptr){
            int i,j,lineNum,coloumnNum;
            lineNum=rOuter->getHeight()/(2*cInner->getSize());
            coloumnNum=rOuter->getWidth()/(2*cInner->getSize());
            cInner->setPositionY(cInner->getSize());
            for(i=0;i<lineNum;++i){
                cInner->setPositionX(cInner->getSize());
                for(j=0;j<coloumnNum;++j){
                    vShape.push_back(*cInner);                   
                    cInner->setPositionX(cInner->getPosition().x + 2*cInner->getSize());
                }
                cInner->setPositionY(cInner->getPosition().y + 2*cInner->getSize());
            }
        }
        else{
            int i,j,lineNum,coloumnNum;
            double h=(double)(tInner->getSize()/2.0)*sqrt(3.0);
            auto temp=0,temp2=0;
            double y1=h,y2=0.0;
            double r1=0.0,r2=h;

            coloumnNum = (double)(rOuter->getWidth()/tInner->getSize());
            lineNum = (double)rOuter->getHeight()/h;
            
            for (i=0; i < lineNum; ++i){ 
                temp=0;
                for (j=0; j < coloumnNum; ++j)
                {
                    tInner->setPositionT1(temp + tInner->getSize()/2, y1);
                    tInner->setPositionT2(temp, y2);
                    tInner->setPositionT3(temp +tInner->getSize(),y2);
                    vShape.push_back(ShapeElem(*tInner));
                    tInner->setPositionT1(tInner->getPositionT1().x+tInner->getSize(), tInner->getPositionT1().y);
                    temp += tInner->getSize();
                }
                y1 +=h;
                y2 +=h;
                for(j=0; j < coloumnNum-1; ++j){
                    tInner->setPositionT1(temp2 + tInner->getSize(), r1);
                    tInner->setPositionT2(temp2 + tInner->getSize()/2,r2);
                    tInner->setPositionT3(temp2 + tInner->getSize() + tInner->getSize()/2 , r2);
                    vShape.push_back(ShapeElem(*tInner));
                    temp2 += tInner->getSize();
                }
                temp2=0;
                r1 += h;
                r2 += h;
            }         
        }
    }
    else if(cOuter != nullptr){
        if(rInner != nullptr){
            int x=2,y=1;
            decltype (x-y) i;
            int j,a,b,c,d,h,lineNum,coloumnNum;
            lineNum = 2*cOuter->getSize() / rInner->getHeight();
            for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() - (i+1)*rInner->getHeight();
                rInner->setPositionX(cOuter->getSize());
                rInner->setPositionY(a);
                vShape.push_back(ShapeElem(*rInner));
            }
           for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() + (i)*rInner->getHeight();
                rInner->setPositionX(cOuter->getSize());
                rInner->setPositionY(a);
                vShape.push_back(ShapeElem(*rInner));
            }
        }
        else if(cInner != nullptr){
            int i,j,a,b,c,d,h,lineNum,coloumnNum;
            coloumnNum = cOuter->getSize() / cInner->getSize();
            cInner->setPositionX(cOuter->getSize());
            cInner->setPositionY(cOuter->getSize());
            vShape.push_back(ShapeElem(*cInner));
            for(i=0; i<(coloumnNum-1)/2; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                cInner->setPositionX(a);
                cInner->setPositionY(cOuter->getSize());
                vShape.push_back(ShapeElem(*cInner));
                b=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setPositionX(b);
                cInner->setPositionY(cOuter->getSize());
                vShape.push_back(ShapeElem(*cInner));
            }
            lineNum=(cOuter->getSize()-cInner->getSize())/(cInner->getSize()*2);         
            for(i=0; i<lineNum; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                h=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setPositionX(cOuter->getSize());
                cInner->setPositionY(a);
                vShape.push_back(ShapeElem(*cInner));
                cInner->setPositionX(cOuter->getSize());
                cInner->setPositionY(h);
                vShape.push_back(ShapeElem(*cInner));
                coloumnNum = (cOuter->getSize()-2*(i+1)) / cInner->getSize();
                for(j=0; j<(int)(coloumnNum-1)/2; ++j){
                    c=cOuter->getSize()-(j+1)*2*cInner->getSize();
                    d=cOuter->getSize()+(j+1)*2*cInner->getSize();
                    cInner->setPositionX(c);
                    cInner->setPositionY(a);
                    vShape.push_back(ShapeElem(*cInner));
                    cInner->setPositionX(d);
                    cInner->setPositionY(a);
                    vShape.push_back(ShapeElem(*cInner));
                    cInner->setPositionX(c);
                    cInner->setPositionY(h);
                    vShape.push_back(ShapeElem(*cInner));
                    cInner->setPositionX(d);
                    cInner->setPositionY(h);
                    vShape.push_back(ShapeElem(*cInner));
                }
            }           
        }
        else{
            
        }
    }
    else  {
        if(rInner != nullptr){
            int i,j,lineNum,coloumnNum,th,temp;
            double a,ta,h;
            temp=0;
            a = rInner->getHeight()/sqrt(3);
            h = (double)(tOuter->getSize()/2)*sqrt(3);
            lineNum = h / rInner->getHeight();

            for(i=0; i<lineNum; ++i){
                    ta = (double)(i+1)*a;
                    th = ((int)(h-temp*rInner->getHeight())/sqrt(3))*2;
                    coloumnNum = (th-2*a)/rInner->getWidth();
                    for(j=0; j<coloumnNum; ++j){
                        rInner->setPositionX(ta);
                        rInner->setPositionY(h-(double)((i+1)*rInner->getHeight()));
                        vShape.push_back(ShapeElem(*rInner));
                        ta += rInner->getWidth();
                    }
                    temp++;
            }

        }
        else if(cInner != nullptr){
            double b,ch,c,h;
            int i,j,lineNum,coloumnNum,temp;
            h = (double)(tOuter->getSize()/2)*sqrt(3);
            b = (double)((cInner->getSize()/(sqrt(3)+2))+cInner->getSize())/sqrt(3);
            c = b*sqrt(3);
            lineNum = h/(2*cInner->getSize());
            for(i=0; i<lineNum; ++i){
                ch = tOuter->getSize() - (double)(2*(((i*2*cInner->getSize())+ c))/sqrt(3));
                coloumnNum = ch/(2*cInner->getSize());
                temp=0;
                for(j=0; j<coloumnNum; ++j){
                    cInner->setPositionX((i*2*cInner->getSize()+c)/sqrt(3)+cInner->getSize()+temp*2*cInner->getSize());
                    cInner->setPositionY(h-cInner->getSize() -i*2*cInner->getSize());
                    vShape.push_back(ShapeElem(*cInner));
                    temp++;
                }
            }
            
            
        }
        else{
            double H,h;
            int i,j,lineNum,coloumnNum,coloumnNum2;
            int t,temp,temp2,a;
            t=1;
            H=(double)(tOuter->getSize()/2)*sqrt(3);
            h=(double)(tInner->getSize()/2)*sqrt(3);
            lineNum=H/h;
            temp=0;
            temp2=0;
            for(i=0;i<lineNum;++i){
                    coloumnNum=(int)((H-temp*h)/sqrt(3))*2 / tInner->getSize();
                    coloumnNum2=(int)((H-t*h)/sqrt(3))*2 / tInner->getSize();
                    a=temp2;
                    for(j=0;j<coloumnNum;++j){
                            tInner->setPositionT1(tInner->getSize()/2 + a, H-(temp+1)*h);                     
                            tInner->setPositionT2(a, H-temp*h);
                            tInner->setPositionT3(tInner->getSize() + a, H-temp*h) ; 
                            vShape.push_back(ShapeElem(*tInner));                           
                            a += tInner->getSize();
                    }
                    a=temp2;
                    for(j=0;j<coloumnNum2;++j){
                            tInner->setPositionT1(tInner->getSize() + a, H-temp*h);                           
                            tInner->setPositionT2(tInner->getSize()/2 + a, H-(temp+1)*h);                            
                            tInner->setPositionT3(tInner->getSize()/2 + tInner->getSize() + a, H-(temp+1)*h);  
                            vShape.push_back(ShapeElem(*tInner));                                               
                            a += tInner->getSize();
                    }
                    t++;
                    temp++;
                    temp2 += tInner->getSize()/2;
            }      
        }
    }      
 }

ostream& operator<<(ostream &out, const ComposedShape &shape){
    out<<"<svg version=\"1.1\" baseProfile=\"full\" ";
    if(shape.rOuter != nullptr)
        out<<"width=\""<<shape.rOuter->getWidth()<<"\" height=\""<<shape.rOuter->getHeight()<<"\"";   
    else if(shape.cOuter != nullptr)
        out<<"width=\""<<shape.cOuter->getSize()*2<<"\" height=\""<<shape.cOuter->getSize()*2<<"\"";
    else
        out<<"width=\""<<shape.tOuter->getSize()<<"\" height=\""<<shape.tOuter->getSize()<<"\"";
    out<<" xmlns=\"http://wwww.w3.org/2000/svg\">";  
    
    if(shape.rOuter != nullptr)
        out<<"<rect x=\"0\" y=\"0\" "<<"width=\""<<shape.rOuter->getWidth()<<"\" height=\""<<shape.rOuter->getHeight()<<"\" fill=\"red\" />";
    else if(shape.tOuter != nullptr)
        out<<"<polygon points=\""<<(double)(shape.tOuter->getSize()/2)<<","<<0<<" "<<0<<","<<(double)(shape.tOuter->getSize()/2)*sqrt(3)
        <<" "<<shape.tOuter->getSize()<<","<<(double)(shape.tOuter->getSize()/2)*sqrt(3)<<"\" "<<"fill=\"red\" />";
    else
        out<<"<circle cx=\""<<shape.cOuter->getSize()<<"\" cy=\""<<shape.cOuter->getSize()<<"\" r=\"" <<shape.cOuter->getSize()<<"\" "<<"fill=\"red\" />";
    int i;
    if(shape.rInner != nullptr){ 
        for(i=0; i<shape.getShapes().size(); ++i)
            out<<(shape.getShapes())[i];
    }
    else if(shape.cInner != nullptr){
        for(i=0; i<shape.getShapes().size(); ++i)
            out<<(shape.getShapes())[i];
    }
    else{
        for(i=0; i<shape.getShapes().size(); ++i)
            out<<(shape.getShapes())[i];
    }
         
out<<"</svg>";

}
double ComposedShape::ShapeElem::getArea()const{
    if(which == whichShape::Rect){
        return (static_cast<Rectangle*>(shape)->getArea());
    }
    else if(which == whichShape::Circ){
        return (static_cast<Circle*>(shape)->getArea());
    }
    else{
        return (static_cast<Triangle*>(shape)->getArea());
    }
}
double ComposedShape::ShapeElem::getPerimeter()const{
    if(which == whichShape::Rect){
        return (static_cast<Rectangle*>(shape)->getPerimeter());
    }
    else if(which == whichShape::Circ){
        return (static_cast<Circle*>(shape)->getPerimeter());
    }
    else{
        return (static_cast<Triangle*>(shape)->getPerimeter());
    }
}
ComposedShape::ShapeElem& ComposedShape::operator[](int i){
    if(i >-1)
        return ComposedShape::vShape[i];
}

    
    
    