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
        Rectangle *newRect = new Rectangle;
        newRect->setSize(rOuter->getSize());
        newRect->setHeight(rOuter->getHeight());
        newRect->setCoordX(0);
        newRect->setCoordY(0);
        shapes.push_back(newRect); 
        if(rInner != nullptr){
            int i,j,coloumnNum,lineNum;
            coloumnNum=rOuter->getSize()/rInner->getSize();
            lineNum=rOuter->getHeight()/rInner->getHeight();
            rInner->setCoordY(0);
            for(i=0; i<lineNum; ++i)
            {
                rInner->setCoordX(0);
                for(j=0; j<coloumnNum; ++j)
                {
                    Rectangle *newRect = new Rectangle;
                    newRect->setSize(rInner->getSize());
                    newRect->setHeight(rInner->getHeight());
                    newRect->setCoordX(rInner->getCoordX());
                    newRect->setCoordY(rInner->getCoordY());
                    shapes.push_back(newRect); 
                    rInner->setCoordX(rInner->getCoordX() + (double)rInner->getSize());
                }
                rInner->setCoordY(rInner->getCoordY() + (double)rInner->getHeight());
             }
        }
        else if(cInner != nullptr){
            int i,j,lineNum,coloumnNum;
            lineNum=rOuter->getHeight()/(2*cInner->getSize());
            coloumnNum=rOuter->getSize()/(2*cInner->getSize());
            cInner->setCoordY(cInner->getSize());
            for(i=0;i<lineNum;++i){
                cInner->setCoordX(cInner->getSize());
                for(j=0;j<coloumnNum;++j){                 
                    Circle *newCirc = new Circle;
                    newCirc->setSize(cInner->getSize());
                    newCirc->setCoordX(cInner->getCoordX());
                    newCirc->setCoordY(cInner->getCoordY());
                    shapes.push_back(newCirc);                 
                    cInner->setCoordX(cInner->getCoordX() + 2*cInner->getSize());
                }
                cInner->setCoordY(cInner->getCoordY() + 2*cInner->getSize());         
            }
        }
        else{
            int i,j,lineNum,coloumnNum;
            double h=(double)(tInner->getSize()/2.0)*sqrt(3.0);
            auto temp=0,temp2=0;
            double y1=h,y2=0.0;
            double r1=0.0,r2=h;

            coloumnNum = (double)(rOuter->getSize()/tInner->getSize());
            lineNum = (double)rOuter->getHeight()/h;
            
            for (i=0; i < lineNum; ++i){ 
                temp=0;
                for (j=0; j < coloumnNum; ++j)
                {
                    tInner->setCoord1(temp + tInner->getSize()/2, y1);
                    tInner->setCoord2(temp, y2);
                    tInner->setCoord3(temp +tInner->getSize(),y2);
                    Triangle *newTri = new Triangle;
                    newTri->setSize(tInner->getSize());
                    newTri->setCoord1(tInner->getCoordX(),tInner->getCoordY());
                    newTri->setCoord2(tInner->getCoordX2(),tInner->getCoordY2());
                    newTri->setCoord3(tInner->getCoordX3(),tInner->getCoordY3());
                    shapes.push_back(newTri);  
                    tInner->setCoord1(tInner->getCoordX() + tInner->getSize(), tInner->getCoordY());
                    temp += tInner->getSize();
                }
                y1 +=h;
                y2 +=h;
                for(j=0; j < coloumnNum-1; ++j){
                    tInner->setCoord1(temp2 + tInner->getSize(), r1);
                    tInner->setCoord2(temp2 + tInner->getSize()/2,r2);
                    tInner->setCoord3(temp2 + tInner->getSize() + tInner->getSize()/2 , r2);
                    Triangle *newTri = new Triangle;
                    newTri->setSize(tInner->getSize());
                    newTri->setCoord1(tInner->getCoordX(),tInner->getCoordY());
                    newTri->setCoord2(tInner->getCoordX2(),tInner->getCoordY2());
                    newTri->setCoord3(tInner->getCoordX3(),tInner->getCoordY3());
                    shapes.push_back(newTri);  
                    temp2 += tInner->getSize();
                }
                temp2=0;
                r1 += h;
                r2 += h;
            }         
        }
    }
    else if(cOuter != nullptr){
        Circle *newCirc = new Circle;
        newCirc->setSize(cOuter->getSize());
        newCirc->setCoordX(cOuter->getSize());
        newCirc->setCoordY(cOuter->getSize());
        shapes.push_back(newCirc);           
        if(rInner != nullptr){
            int x=2,y=1;
            decltype (x-y) i;
            int j,a,b,c,d,h,lineNum,coloumnNum;
            lineNum = 2*cOuter->getSize() / rInner->getHeight();
            for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() - (i+1)*rInner->getHeight();
                rInner->setCoordX(cOuter->getSize());
                rInner->setCoordY(a);            
                Rectangle *newRect = new Rectangle;
                newRect->setSize(rInner->getSize());
                newRect->setHeight(rInner->getHeight());
                newRect->setCoordX(rInner->getCoordX());
                newRect->setCoordY(rInner->getCoordY());
                shapes.push_back(newRect); 
            }
           for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() + (i)*rInner->getHeight();
                rInner->setCoordX(cOuter->getSize());
                rInner->setCoordY(a);
                Rectangle *newRect = new Rectangle;
                newRect->setSize(rInner->getSize());
                newRect->setHeight(rInner->getHeight());
                newRect->setCoordX(rInner->getCoordX());
                newRect->setCoordY(rInner->getCoordY());
                shapes.push_back(newRect); 
            }
        }
        else if(cInner != nullptr){
            int i,j,a,b,c,d,h,lineNum,coloumnNum;
            coloumnNum = cOuter->getSize() / cInner->getSize();
            cInner->setCoordX(cOuter->getSize());
            cInner->setCoordY(cOuter->getSize());
            Circle *newCirc = new Circle;
            newCirc->setSize(cInner->getSize());
            newCirc->setCoordX(cInner->getCoordX());
            newCirc->setCoordY(cInner->getCoordY());
            shapes.push_back(newCirc);     
            for(i=0; i<(coloumnNum-1)/2; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                cInner->setCoordX(a);
                cInner->setCoordY(cOuter->getSize());
                Circle *newCirc = new Circle;
                newCirc->setSize(cInner->getSize());
                newCirc->setCoordX(cInner->getCoordX());
                newCirc->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc);     
                b=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setCoordX(b);
                cInner->setCoordY(cOuter->getSize());
                Circle *newCirc6 = new Circle;
                newCirc6->setSize(cInner->getSize());
                newCirc6->setCoordX(cInner->getCoordX());
                newCirc6->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc6);     
            }
            lineNum=(cOuter->getSize()-cInner->getSize())/(cInner->getSize()*2);         
            for(i=0; i<lineNum; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                h=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setCoordX(cOuter->getSize());
                cInner->setCoordY(a);
                Circle *newCirc = new Circle;
                newCirc->setSize(cInner->getSize());
                newCirc->setCoordX(cInner->getCoordX());
                newCirc->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc);     
                cInner->setCoordX(cOuter->getSize());
                cInner->setCoordY(h);
               Circle *newCirc5 = new Circle;
                newCirc5->setSize(cInner->getSize());
                newCirc5->setCoordX(cInner->getCoordX());
                newCirc5->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc5);     
                coloumnNum = (cOuter->getSize()-2*(i+1)) / cInner->getSize();
            for(j=0; j<(int)(coloumnNum-1)/2; ++j){
                c=cOuter->getSize()-(j+1)*2*cInner->getSize();
                d=cOuter->getSize()+(j+1)*2*cInner->getSize();
                cInner->setCoordX(c);
                cInner->setCoordY(a);
                Circle *newCirc = new Circle;
                newCirc->setSize(cInner->getSize());
                newCirc->setCoordX(cInner->getCoordX());
                newCirc->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc);     
                cInner->setCoordX(d);
                cInner->setCoordY(a);
                Circle *newCirc2 = new Circle;
                newCirc2->setSize(cInner->getSize());
                newCirc2->setCoordX(cInner->getCoordX());
                newCirc2->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc2);     
                cInner->setCoordX(c);
                cInner->setCoordY(h);
                Circle *newCirc3 = new Circle;
                newCirc3->setSize(cInner->getSize());
                newCirc3->setCoordX(cInner->getCoordX());
                newCirc3->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc3);     
                cInner->setCoordX(d);
                cInner->setCoordY(h);
                Circle *newCirc4 = new Circle;
                newCirc4->setSize(cInner->getSize());
                newCirc4->setCoordX(cInner->getCoordX());
                newCirc4->setCoordY(cInner->getCoordY());
                shapes.push_back(newCirc4);     
                }
            }           
        }
        else{
            tInner->setCoord1(cOuter->getSize(),cOuter->getSize()-(((tInner->getSize()/2)*sqrt(3))/2));
            tInner->setCoord2(cOuter->getSize()-(tInner->getSize()/2),cOuter->getSize()+((tInner->getSize()/2)*sqrt(3))/2);
            tInner->setCoord3(cOuter->getSize()+(tInner->getSize()/2),cOuter->getSize()+((tInner->getSize()/2)*sqrt(3))/2);
            Triangle *newTri = new Triangle;
            newTri->setSize(tInner->getSize());
            newTri->setCoord1(tInner->getCoordX(),tInner->getCoordY());
            newTri->setCoord2(tInner->getCoordX2(),tInner->getCoordY2());
            newTri->setCoord3(tInner->getCoordX3(),tInner->getCoordY3());
            shapes.push_back(newTri);  
               
        }
    }
    else  {
        Triangle *newTri = new Triangle;
        newTri->setSize(tOuter->getSize());
        newTri->setCoord1((double)(this->tOuter->getSize()/2),0);
        newTri->setCoord2(0,(double)(this->tOuter->getSize()/2)*sqrt(3));
        newTri->setCoord3(this->tOuter->getSize(),(double)(this->tOuter->getSize()/2)*sqrt(3));
        shapes.push_back(newTri);  
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
                    coloumnNum = (th-2*a)/rInner->getSize();
                    for(j=0; j<coloumnNum; ++j){
                        rInner->setCoordX(ta);
                        rInner->setCoordY(h-(double)((i+1)*rInner->getHeight()));
                        Rectangle *newRect = new Rectangle;
                        newRect->setSize(rInner->getSize());
                        newRect->setHeight(rInner->getHeight());
                        newRect->setCoordX(rInner->getCoordX());
                        newRect->setCoordY(rInner->getCoordY());
                        shapes.push_back(newRect); 
                        ta += rInner->getSize();
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
                    cInner->setCoordX((i*2*cInner->getSize()+c)/sqrt(3)+cInner->getSize()+temp*2*cInner->getSize());
                    cInner->setCoordY(h-cInner->getSize() -i*2*cInner->getSize());
                    Circle *newCirc = new Circle;
                    newCirc->setSize(cInner->getSize());
                    newCirc->setCoordX(cInner->getCoordX());
                    newCirc->setCoordY(cInner->getCoordY());
                    shapes.push_back(newCirc);       
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
                            tInner->setCoord1(tInner->getSize()/2 + a, H-(temp+1)*h);                     
                            tInner->setCoord2(a, H-temp*h);
                            tInner->setCoord3(tInner->getSize() + a, H-temp*h) ; 
                           Triangle *newTri = new Triangle;
                            newTri->setSize(tInner->getSize());
                            newTri->setCoord1(tInner->getCoordX(),tInner->getCoordY());
                            newTri->setCoord2(tInner->getCoordX2(),tInner->getCoordY2());
                            newTri->setCoord3(tInner->getCoordX3(),tInner->getCoordY3());
                            shapes.push_back(newTri);                             
                            a += tInner->getSize();
                    }
                    a=temp2;
                    for(j=0;j<coloumnNum2;++j){
                            tInner->setCoord1(tInner->getSize() + a, H-temp*h);                           
                            tInner->setCoord2(tInner->getSize()/2 + a, H-(temp+1)*h);                            
                            tInner->setCoord3(tInner->getSize()/2 + tInner->getSize() + a, H-(temp+1)*h);  
                            Triangle *newTri = new Triangle;
                            newTri->setSize(tInner->getSize());
                            newTri->setCoord1(tInner->getCoordX(),tInner->getCoordY());
                            newTri->setCoord2(tInner->getCoordX2(),tInner->getCoordY2());
                            newTri->setCoord3(tInner->getCoordX3(),tInner->getCoordY3());
                            shapes.push_back(newTri);                                                
                            a += tInner->getSize();
                    }
                    t++;
                    temp++;
                    temp2 += tInner->getSize()/2;
            }      
        }
    }   
    
 }
void printAll(vector<Shape*> shape,ostream& out){
    shape[0]->print(out,0);
    for(int i=1; i<shape.size(); ++i)
        shape[i]->print(out,1);
}
void ComposedShape::print(ostream& out,int a)const{  
    out<<"<svg version=\"1.1\" baseProfile=\"full\" ";
    if(this->rOuter != nullptr)
        out<<"width=\""<<this->rOuter->getSize()<<"\" height=\""<<this->rOuter->getHeight()<<"\"";   
    else if(this->cOuter != nullptr)
        out<<"width=\""<<this->cOuter->getSize()*2<<"\" height=\""<<this->cOuter->getSize()*2<<"\"";
    else
        out<<"width=\""<<this->tOuter->getSize()<<"\" height=\""<<this->tOuter->getSize()<<"\"";
    out<<" xmlns=\"http://wwww.w3.org/2000/svg\">";  
   
    printAll(shapes,out); // Using global printAll Function
    
    out<<"</svg>";
}
