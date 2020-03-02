//============================================================================
// Name        : 161044068_main.cpp
// Author      : Zeynep Nazire Yüksel - 161044068
//============================================================================


#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Circle.h"
#include "structs.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include <sstream>


using namespace std;

string FileName();
int main(int argc, char** argv) {

    ofstream File;
    int i;
    Rectangle rArr[4]; /*ödevde istenilen 4 arrayi oluşturdum.*/
    Triangle tArr[4];
    Circle cArr[4];
    ComposedShape *(cs[6]);
    /*dikdörtgen arrayindeki her bir objenin width si ve height si rectangle classındaki setSize fonk. gönderilerek tanımlanır.*/
    rArr[0].setSize(15,10); /*setPosition fonksiyonlarını driverda çağırmadım çünkü composedShape classında çağrılıyor.*/
    rArr[1].setSize(17,13);
    rArr[2].setSize(900,850);
    rArr[3].setSize(857,659);
    for(i=0; i<4; i++){
        cout<<"Width of rArr["<<i<<"] : "<<rArr[i].getWidth()<<endl; /*dikdörtgen arrayindeki her bir objenin widthleri ve heightleri rectangle classındaki getWidth ve getHeight*/  
        cout<<"Height of rArr["<<i<<"] : "<<rArr[i].getHeight()<<endl; /*fonksiyonları sayesinde ekrana bastırılır.*/
        File.open(FileName().c_str());
        rArr[i].drawRect(File,true); /*her bir obje rectangle classındaki drawRect fonksiyonuyla tek şekil olarak svg olarak dosya olusturur.*/
    }
    cout<<endl;
    cArr[0].setSize(10); /*circle arrayindeki her bir objenin radius u circle classındaki setSize fonksiyonuna gönderilerek tanimlanir.*/
    cArr[1].setSize(13);
    cArr[2].setSize(250);
    cArr[3].setSize(333);
    for(i=0; i<4; ++i){
        cout<<"Radius of cArr["<<i<<"] : "<<cArr[i].getSize()<<endl;
	    File.open(FileName().c_str());
        cArr[i].drawCirc(File,true); /*her bir obje circle classındaki drawCirc fonksiyonuyla tek şekil olarak svg olarak dosya olusturur.*/
    }
    cout<<endl;
    tArr[0].setSize(11);/*triangle arrayindeki her bir objenin line ı triangle classındaki setSize fonksiyonuna gönderilerek tanimlanir.*/
    tArr[1].setSize(23);
    tArr[2].setSize(257);    
    tArr[3].setSize(368);   /*driver da optimal fit fonksiyonunu çağırmadım çünkü bu fonksiyon ComposedShape classındaki drawShape fonksiyonunda çağrılır,kullanıcının çağırmasına gerek yoktur.*/
    for(i=0; i<4; ++i){
        cout<<"Line of tArr["<<i<<"] : "<<tArr[i].getSize()<<endl;
	    File.open(FileName().c_str());
        tArr[i].drawTri(File,true); /*her bir obje triangle classındaki drawTri fonksiyonuyla tek şekil olarak svg olarak dosyası olusturur.*/
    }
    cout<<endl;
	cs[0] = new ComposedShape(&rArr[3],&rArr[0]); /*main containerin içine small shape li test için yukarda tanimlanan objeleri ikili halinde ComposedShape classına gönderdim.*/
    cs[1] = new ComposedShape(&rArr[3],&cArr[0]);
    cs[2] = new ComposedShape(&rArr[3],&tArr[1]);
    cs[3] = new ComposedShape(&tArr[2],&rArr[1]);
    cs[4] = new ComposedShape(&tArr[3],&cArr[1]);
    cs[5] = new ComposedShape(&tArr[3],&tArr[0]);
    for(i=0; i<6; ++i){
        File.open(FileName().c_str());
        cs[i]->drawShape(File);
        if(i % 3 == 0) /*index numarasının 3 e bölümünden kalanına göre ikinci şekli ifade eden if else yaptım.Bu if else lerde ComposedShape classında tutmuş olduğum vectorden yardım alarak */
            cout<<"Number of small rectangles in main container : "<<cs[i]->getRectSmallShapesVector().size()<<endl;/*small shape sayısını ekrana bastırdım.*/
        else if(i % 3 == 1)
            cout<<"Number of small circles in main container : "<<cs[i]->getCircSmallShapesVector().size()<<endl;
        else
            cout<<"Number of small triangles in main container : "<<cs[i]->getTriSmallShapesVector().size()<<endl;
    }

   

    return 0;
}

string FileName() { /*art arta oluşacak svg dosyalarının silinmesini istemediğim için her dosya kapandığında açılan dosyanın ismini değiştirmek için statik bir int değişkeni tutarak bu int i */
    static int i=1; /*her fonksiyona girildiğinde artırıp string yapıp "result" stringi ile birleştirerek yeni bir dosya ismi elde ettim.*/
    stringstream s;
    s << i;
    ++i;
    string text = "result" + s.str();

    return text;
}
