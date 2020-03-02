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
}

ComposedShape::ComposedShape(Rectangle *outer, Circle *inner){
    rOuter = outer;
    cInner = inner;   
}

ComposedShape::ComposedShape(Rectangle *outer, Triangle *inner){
    rOuter = outer;
    tInner = inner;
}

ComposedShape::ComposedShape(Circle *outer, Rectangle *inner){
    cOuter = outer;
    rInner = inner;
}

ComposedShape::ComposedShape(Circle *outer, Circle *inner){
    cOuter = outer;
    cInner = inner;
}

ComposedShape::ComposedShape(Circle *outer, Triangle *inner){
    cOuter = outer;
    tInner = inner;
}

ComposedShape::ComposedShape(Triangle *outer, Rectangle *inner){
    tOuter = outer;
    rInner = inner;  
}

ComposedShape::ComposedShape(Triangle *outer, Circle *inner){
    tOuter = outer;
    cInner = inner;
}

ComposedShape::ComposedShape(Triangle *outer, Triangle *inner){
    tOuter = outer;
    tInner = inner;
}

void ComposedShape::optimalFit(){ /*bu fonksiyonda main container ın içine gelebilecek şekil objesinin koordinatları bulunur ve küçük şeklin tipine göre belirlenecek vektöre eklenir.*/
     
    if(rOuter != nullptr){  
        if(rInner != nullptr){
            vRect = new vector<Rectangle>;
            int i,j,coloumnNum,lineNum;
            coloumnNum=rOuter->getWidth()/rInner->getWidth();
            lineNum=rOuter->getHeight()/rInner->getHeight();
            rInner->setPositionY(0);
            for(i=0; i<lineNum; ++i)
            {
                rInner->setPositionX(0);
                for(j=0; j<coloumnNum; ++j)
                {     
                    vRect->push_back(*rInner);
                    rInner->setPositionX(rInner->getPosition().x + (double)rInner->getWidth());
                }
                rInner->setPositionY(rInner->getPosition().y + (double)rInner->getHeight());
             }
        }
        else if(cInner != nullptr){
            vCirc = new vector<Circle>;
            int i,j,lineNum,coloumnNum;
            lineNum=rOuter->getHeight()/(2*cInner->getSize());
            coloumnNum=rOuter->getWidth()/(2*cInner->getSize());
            cInner->setPositionY(cInner->getSize());
            for(i=0;i<lineNum;++i){
                cInner->setPositionX(cInner->getSize());
                for(j=0;j<coloumnNum;++j){
                    vCirc->push_back(*cInner);
                    cInner->setPositionX(cInner->getPosition().x + 2*cInner->getSize());
                }
                cInner->setPositionY(cInner->getPosition().y + 2*cInner->getSize());
            }
        }
        else{
            vTri = new vector<Triangle>;
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
                    vTri->push_back(*tInner);
                    tInner->setPositionT1(tInner->getPositionT1().x+tInner->getSize(), tInner->getPositionT1().y);
                    temp += tInner->getSize();
                }
                y1 +=h;
                y2 +=h;
                for(j=0; j < coloumnNum-1; ++j){
                    tInner->setPositionT1(temp2 + tInner->getSize(), r1);
                    tInner->setPositionT2(temp2 + tInner->getSize()/2,r2);
                    tInner->setPositionT3(temp2 + tInner->getSize() + tInner->getSize()/2 , r2);
                    vTri->push_back(*tInner);
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
            vRect = new vector<Rectangle>;
            int x=2,y=1;
            decltype (x-y) i;
            int j,a,b,c,d,h,lineNum,coloumnNum;
            lineNum = 2*cOuter->getSize() / rInner->getHeight();
            for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() - (i+1)*rInner->getHeight();
                rInner->setPositionX(cOuter->getSize());
                rInner->setPositionY(a);
                vRect->push_back(*rInner);
            }
           for(i=0; i<lineNum/2; ++i){
                a=cOuter->getSize() + (i)*rInner->getHeight();
                rInner->setPositionX(cOuter->getSize());
                rInner->setPositionY(a);
                vRect->push_back(*rInner);
            }
        }
        else if(cInner != nullptr){
            vCirc = new vector<Circle>;
            int i,j,a,b,c,d,h,lineNum,coloumnNum;
            coloumnNum = cOuter->getSize() / cInner->getSize();
            cInner->setPositionX(cOuter->getSize());
            cInner->setPositionY(cOuter->getSize());
            vCirc->push_back(*cInner);
            for(i=0; i<(coloumnNum-1)/2; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                cInner->setPositionX(a);
                cInner->setPositionY(cOuter->getSize());
                vCirc->push_back(*cInner);
                b=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setPositionX(b);
                cInner->setPositionY(cOuter->getSize());
                vCirc->push_back(*cInner);
            }
            lineNum=(cOuter->getSize()-cInner->getSize())/(cInner->getSize()*2);         
            for(i=0; i<lineNum; ++i){
                a=cOuter->getSize()-(i+1)*2*cInner->getSize();
                h=cOuter->getSize()+(i+1)*2*cInner->getSize();
                cInner->setPositionX(cOuter->getSize());
                cInner->setPositionY(a);
                vCirc->push_back(*cInner);
                cInner->setPositionX(cOuter->getSize());
                cInner->setPositionY(h);
                vCirc->push_back(*cInner);
                coloumnNum = (cOuter->getSize()-2*(i+1)) / cInner->getSize();
                for(j=0; j<(int)(coloumnNum-1)/2; ++j){
                    c=cOuter->getSize()-(j+1)*2*cInner->getSize();
                    d=cOuter->getSize()+(j+1)*2*cInner->getSize();
                    cInner->setPositionX(c);
                    cInner->setPositionY(a);
                    vCirc->push_back(*cInner);
                    cInner->setPositionX(d);
                    cInner->setPositionY(a);
                    vCirc->push_back(*cInner);
                    cInner->setPositionX(c);
                    cInner->setPositionY(h);
                    vCirc->push_back(*cInner);
                    cInner->setPositionX(d);
                    cInner->setPositionY(h);
                    vCirc->push_back(*cInner);
                }
            }           
        }
        else{
            
        }
    }
    else  {
        if(rInner != nullptr){
            vRect = new vector<Rectangle>;
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
                        vRect->push_back(*rInner);
                        ta += rInner->getWidth();
                    }
                    temp++;
            }

        }
        else if(cInner != nullptr){
            vCirc = new vector<Circle>;
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
                    vCirc->push_back(*cInner);
                    temp++;
                }
            }
            
            
        }
        else{
            vTri = new vector<Triangle>;
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
                            vTri->push_back(*tInner);                           
                            a += tInner->getSize();
                    }
                    a=temp2;
                    for(j=0;j<coloumnNum2;++j){
                            tInner->setPositionT1(tInner->getSize() + a, H-temp*h);                           
                            tInner->setPositionT2(tInner->getSize()/2 + a, H-(temp+1)*h);                            
                            tInner->setPositionT3(tInner->getSize()/2 + tInner->getSize() + a, H-(temp+1)*h);  
                            vTri->push_back(*tInner);                                                
                            a += tInner->getSize();

                    }
                    t++;
                    temp++;
                    temp2 += tInner->getSize()/2;

            }      
        }
    }     
    
 }

void ComposedShape::drawShape(ofstream &File){
    optimalFit();
    File<<"<svg version=\"1.1\" baseProfile=\"full\" ";
    if(rOuter != nullptr)
        File<<"width=\""<<rOuter->getWidth()<<"\" height=\""<<rOuter->getHeight()<<"\"";   
    else if(cOuter != nullptr)
        File<<"width=\""<<cOuter->getSize()*2<<"\" height=\""<<cOuter->getSize()*2<<"\"";
    else
        File<<"width=\""<<tOuter->getSize()<<"\" height=\""<<tOuter->getSize()<<"\"";
    File<<" xmlns=\"http://wwww.w3.org/2000/svg\">";  
    
    if(rOuter != nullptr)
        File<<"<rect x=\"0\" y=\"0\" "<<"width=\""<<rOuter->getWidth()<<"\" height=\""<<rOuter->getHeight()<<"\" fill=\"red\" />";
    else if(tOuter != nullptr)
        File<<"<polygon points=\""<<(double)(tOuter->getSize()/2)<<","<<0<<" "<<0<<","<<(double)(tOuter->getSize()/2)*sqrt(3)
        <<" "<<tOuter->getSize()<<","<<(double)(tOuter->getSize()/2)*sqrt(3)<<"\" "<<"fill=\"red\" />";
    else
        File<<"<circle cx=\""<<cOuter->getSize()<<"\" cy=\""<<cOuter->getSize()<<"\" r=\"" <<cOuter->getSize()<<"\" "<<"fill=\"red\" />";
    int i;
    if(rInner != nullptr){ /*main container ın içine konulacak şeklin tipine göre vRect,vCirc veya vTri vektörlerinin içinde bulunan objeler kendi tipinin classına gönderilir ve orada çizilir.*/
        for(i=0; i<vRect->size(); ++i)
            (*vRect)[i].drawRect(File,false);
    }
    else if(cInner != nullptr){
        for(i=0; i<vCirc->size(); ++i)
            (*vCirc)[i].drawCirc(File,false);
    }
    else{
        for(i=0; i<vTri->size(); ++i)
            (*vTri)[i].drawTri(File,false);
    }
         
File<<"</svg>";
File.close();  
}
