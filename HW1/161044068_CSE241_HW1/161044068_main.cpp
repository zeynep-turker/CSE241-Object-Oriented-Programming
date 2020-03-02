#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.141818
using namespace std;

enum class Shapes {rect, circle, triangle}; //kullanıcıdan alınan şeklin ne olduğunu tutmasını sağlaması için enum class yapılır.
struct RectCoord{ //dikdörtgenin x ve y koordinatlarını tutan struct tanımlanır.
	double x;
	double y;
};
struct CircCoord{ //dairenin x ve y koordinatlarını tutan struct tanımlanır.
	double x;
	double y;
};
struct TriCoord{ //üçgenin uç noktalarının koordinatlarını tutan struct.
	double T1,T2,T3,T4,T5,T6;
};
struct Rectangle { //dikdörtgenin koordinatlarına pointer ile erişen ve genişliğini,yüksekliğini tutan struct.
	int width;
	int height;
	RectCoord *coords;
};
struct Circle { //dairenin koordinatlarına pointer ile erişen ve yarıçapını tutan struct.
	int radius;	
	CircCoord *coords;
};
struct Triangle { //üçgenin koordinatlarına pointer ile erişen ve  kenar uzunlugunu tutan struct.
	int line;
	TriCoord *coords;
};
struct howManyShape{ //dış şeklin içine koyulacak şekilden kaç tane sığabileceğini tutan struct.
	int number;
};
struct whichShape{ // seçilen şekillerinin özelliklerine daha rahat ulaşabilmek için bu struct yapılır.
	Rectangle *rectangle;
	Circle *circle;
	Triangle *triangle;
	Shapes which;
	howManyShape *SmallShapeNum;
	double area;
};

int ShapesChoice(whichShape &shape,int outerOrInner); //kullanıcının dış şekli ya da iç şeklini seçtiği bir fonksiyondur.
double setRectSize(whichShape &rect);//dikdörtgenin genişliği ve yüksekliği kullanıcıdan istenilir.
double setCircSize(whichShape &circ);//dairenin yarıçapı kullanıcıdan istenilir.
double setTriSize(whichShape &tri);//üçgenin kenar uzunluğu kullanıcıdan istenilir.
double setValuesOfShapes(whichShape &which);/*dış ya da iç şeklin gönderilip şekle göre uzunluk değerlerinin belirlenmesi için setRectSize,setCircSize ya da setTriSize
fonksiyonlarına gönderildiği fonksiyondur.*/
void writeSvg(ofstream &file,whichShape outer,whichShape inner);
void writeRect(ofstream &file,whichShape outer,whichShape &inner);
void writeCircle(ofstream &file,whichShape outer,whichShape inner);
void writeTriangle(ofstream &file,whichShape outer,whichShape inner);
void writeInnerShape(ofstream &file,whichShape inner);
void printSmallShapeNumAndEmptyArea(whichShape outer,whichShape inner); /*ekrana dış şeklin içine sığabilen küçük şeklin sayısını ve 
kalan boş alanı basar*/
void shapeArea(whichShape &shape);

int main() {
	ofstream file;
	file.open("result.svg"); // svg yazmak için dosya açılır.
	whichShape outShape,inShape;
	inShape.SmallShapeNum = new howManyShape;	
	inShape.SmallShapeNum->number=0;
	ShapesChoice(outShape, 1);
	setValuesOfShapes(outShape);
	ShapesChoice(inShape, 2);
	setValuesOfShapes(inShape);
	writeSvg(file,outShape,inShape);
	printSmallShapeNumAndEmptyArea(outShape,inShape);

	delete inShape.SmallShapeNum;
	return 0;
}

int ShapesChoice(whichShape &shape,int outerOrInner){
	int flag=0;
	char choice;

	do{ 
		if (outerOrInner == 1) //ikinci parametre olarak gönderilen sayı 1 ise dış şekil,2 ise iç şekil kullanıcıdan istenilir.
			cout<<"Please enter the main container shape (R, C, T)\n";
		else
			cout<<"Please enter the small shape (R, C, T)\n";
		cin>>choice;

		if(choice == 'R' || choice == 'r')
		{
			shape.which=Shapes::rect;
			flag=1;
		}
		else if(choice == 'C' || choice == 'c')
		{
			shape.which=Shapes::circle;
			flag=1;

		}
		else if(choice == 'T' || choice == 't')
		{
			shape.which=Shapes::triangle;
			flag=1;
		}
		else
			cout<<"You entered wrong.Please try again..\n";

		}while(flag == 0);

		

	return 0;
}

double setRectSize(whichShape &shape){
	shape.rectangle=new Rectangle;
	shape.rectangle->coords = new RectCoord;

	cout<<"Please enter the width"<<endl;
	cin>>shape.rectangle->width;
	cout<<"Please enter the height"<<endl;
	cin>>shape.rectangle->height;
	
	return 0;
}

double setCircSize(whichShape &shape){
	shape.circle=new Circle;
	shape.circle->coords = new CircCoord;

	cout<<"Please enter the radius"<<endl;
	cin>>shape.circle->radius;

	return 0;
}

double setTriSize(whichShape &shape){
	shape.triangle=new Triangle;
	shape.triangle->coords= new TriCoord;

	cout<<"Please enter the line"<<endl;
	cin>>shape.triangle->line;

	return 0;
}

double setValuesOfShapes(whichShape &shape){

	if( shape.which == Shapes::rect)
		setRectSize(shape);
	else if(shape.which == Shapes::circle)
		setCircSize(shape);
	else
		setTriSize(shape);

	return 0;
}

void writeSvg(ofstream &file,whichShape outer,whichShape inner){

	file<<"<svg version=\"1.1\" baseProfile=\"full\" "; /*dıştaki şekle göre ekranda yer ayırılır.*/
	if(outer.which == Shapes::rect)
		file<<"width=\""<<outer.rectangle->width<<"\" height=\""<<outer.rectangle->height<<"\"";
	else if(outer.which == Shapes::circle){
		int c=outer.circle->radius*2;
		file<<"width=\""<<c<<"\" height=\""<<c<<"\"";
	}
	else
		file<<"width=\""<<outer.triangle->line<<"\" height=\""<<outer.triangle->line<<"\"";

	file<<" xmlns=\"http://wwww.w3.org/2000/svg\">\n";

	switch(outer.which){
		case Shapes::rect : writeRect(file,outer,inner);
							break;
		case Shapes::circle : writeCircle(file,outer,inner);
							break;
		case Shapes::triangle : writeTriangle(file,outer,inner);
							break;					
		default : cout<<"error\n";					

	}

	file.close();

}
void writeRect(ofstream &file,whichShape outer,whichShape &inner){
	file<<"<rect x=\"0\" y=\"0\" "<<"width=\""<<outer.rectangle->width<<"\" height=\""<<outer.rectangle->height<<"\" fill=\"red\" />";
	switch(inner.which){ //dikdörtgenin içine sığılması istenen şekle işlemler yapılır.*/
		int lineNum,coloumnNum,i,j; 
		case Shapes::rect : 
					coloumnNum=outer.rectangle->width/inner.rectangle->width;
					lineNum=outer.rectangle->height/inner.rectangle->height;
					inner.rectangle->coords->y=0;
					for(i=0;i<lineNum;++i)/*tüm şekiller satır ve sütuna göre içiçe 2 for döngüsü şeklinde yapılmıştır.İçteki for tek bir satırdaki oluşacak 
					şekilleri çizer ve dıştaki for satırı değiştirir ve tekrar içteki for a girerek diğer satırı yazar.*/
					{
						inner.rectangle->coords->x=0;
						for(j=0;j<coloumnNum;++j)
						{
							writeInnerShape(file,inner); /*iç şeklin çizilmesi için fonksiyon çağırılir ve toplam iç şeklin sayısı bir artar.*/
							inner.SmallShapeNum->number++;
							inner.rectangle->coords->x += inner.rectangle->width;
						}
						inner.rectangle->coords->y += inner.rectangle->height;
					}
					file<<"</svg>";
					delete inner.rectangle->coords;
					break;
		case Shapes::circle : 
					lineNum=outer.rectangle->height/(2*inner.circle->radius);
					coloumnNum=outer.rectangle->width/(2*inner.circle->radius);
					inner.circle->coords->y=inner.circle->radius;
					for(i=0;i<lineNum;++i){
						inner.circle->coords->x=inner.circle->radius;
						for(j=0;j<coloumnNum;++j){
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							inner.circle->coords->x += 2*inner.circle->radius;
						}
						inner.circle->coords->y += 2*inner.circle->radius;
					}
					file<<"</svg>";
					delete inner.circle->coords;
					break;		
		case Shapes::triangle : 
					int h=(int)(inner.triangle->line/2)*sqrt(3);
					int temp=0,temp2=0;
					int y1=h,y2=0;
					int r1=0,r2=h;
					
					coloumnNum = (int)(outer.rectangle->width/inner.triangle->line);

					lineNum = outer.rectangle->height/h;
					for ( i = 0; i < lineNum; ++i){ 
						temp=0;
						for ( j = 0; j < coloumnNum; ++j) /*İçteki ilk for bir satırdaki düz üçgenleri çizer.İkinci for ise bir satırdaki ters üçgenleri çizer.*/
						{
							inner.triangle->coords->T1=temp + inner.triangle->line/2;
							inner.triangle->coords->T2=y1;
							inner.triangle->coords->T3=temp;
							inner.triangle->coords->T4=y2;
							inner.triangle->coords->T5=temp +inner.triangle->line;
							inner.triangle->coords->T6=y2;
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							inner.triangle->coords->T1 += inner.triangle->line;
							temp += inner.triangle->line;
						}
						y1 +=h;
						y2 +=h;
						for(j=0;j < coloumnNum-1; ++j){
							inner.triangle->coords->T1=temp2 + inner.triangle->line;
							inner.triangle->coords->T2=r1;
							inner.triangle->coords->T3=temp2 + inner.triangle->line/2;
							inner.triangle->coords->T4=r2;
							inner.triangle->coords->T5=temp2 + inner.triangle->line +inner.triangle->line/2;
							inner.triangle->coords->T6=r2;
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							temp2 += inner.triangle->line;
						}
						temp2=0;
						r1 += h;
						r2 += h;


					}
				
					file<<"</svg>";
					delete inner.triangle->coords;
					break;
	

	}		
}
void writeCircle(ofstream &file,whichShape outer,whichShape inner){ /*bu fonksiyonum eksik*/
	file<<"<circle cx=\""<<outer.circle->coords->x<<"\" y=\""<<outer.circle->coords->y<<"\" r=\""<<outer.circle->radius<<"\" "
		<<"fill=\"red\" />";
	writeInnerShape(file,inner);

	switch(inner.which){
		case Shapes::rect : 
						break;
		case Shapes::circle :
						break;
		case Shapes::triangle :
						break;								
	}
}
void writeTriangle(ofstream &file,whichShape outer,whichShape inner){

	file<<"<polygon points=\""<<(double)(outer.triangle->line/2)<<","<<0<<" "<<0<<","
		<<(double)(outer.triangle->line/2)*sqrt(3)<<" "<<outer.triangle->line<<","<<(double)(outer.triangle->line/2)*sqrt(3)<<"\" "<<"fill=\"red\" />";
	int i,j,coloumnNum,lineNum,temp,temp2;
	double h;
	switch(inner.which){
		case Shapes::rect :
					int th;
					temp=0;
					double a,ta;
					a=inner.rectangle->height/sqrt(3);
					h=(double)(outer.triangle->line/2)*sqrt(3);
					lineNum=h / inner.rectangle->height;

					for(i=0;i<lineNum;++i){
						ta=(double)(i+1)*a;
						th=((int)(h-temp*inner.rectangle->height)/sqrt(3))*2;
						coloumnNum=(th-2*a)/inner.rectangle->width;
						for(j=0;j<coloumnNum;++j){
							inner.rectangle->coords->x=ta;
							inner.rectangle->coords->y=h-(double)((i+1)*inner.rectangle->height);
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							ta += inner.rectangle->width;
						}
						temp++;
					}
					
					file<<"</svg>";
					break;
		case Shapes::circle :
					double b,ch,c;
					h=(double)(outer.triangle->line/2)*sqrt(3);
					b=(double)((inner.circle->radius/(sqrt(3)+2))+inner.circle->radius)/sqrt(3);
					c=b*sqrt(3);
					lineNum=h/(2*inner.circle->radius);
					for(i=0;i<lineNum;++i){
						ch=outer.triangle->line - (double)(2*(((i*2*inner.circle->radius)+ c))/sqrt(3));
						coloumnNum=ch/(2*inner.circle->radius);
						temp=0;
						for(j=0;j<coloumnNum;++j){
							inner.circle->coords->x=(i*2*inner.circle->radius+c)/sqrt(3)+inner.circle->radius+temp*2*inner.circle->radius;
							inner.circle->coords->y=h-inner.circle->radius -i*2*inner.circle->radius;
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							temp++;
						}
					}
					file<<"</svg>";
					break;
		case Shapes::triangle :
					double H;
					int coloumnNum2;
					int t;
					t=1;
					H=(double)(outer.triangle->line/2)*sqrt(3);
					h=(double)(inner.triangle->line/2)*sqrt(3);
					lineNum=H/h;
					temp=0;
					temp2=0;
					for(i=0;i<lineNum;++i){
						coloumnNum=(int)((H-temp*h)/sqrt(3))*2 / inner.triangle->line;
						coloumnNum2=(int)((H-t*h)/sqrt(3))*2 / inner.triangle->line;
						cout<<coloumnNum<<endl;
						a=temp2;
						for(j=0;j<coloumnNum;++j){ //her satırdaki düz üçgenleri çizen for döngüsüdür.*/
							inner.triangle->coords->T1=inner.triangle->line/2 + a;
							inner.triangle->coords->T2=H-(temp+1)*h;
							inner.triangle->coords->T3=a;
							inner.triangle->coords->T4=H-temp*h;
							inner.triangle->coords->T5=inner.triangle->line + a;
							inner.triangle->coords->T6=H-temp*h;
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							a += inner.triangle->line;
						}
						a=temp2;
						for(j=0;j<coloumnNum2;++j){ //her satırdaki ters üçgenleri çizen for döngüsüdür.*/
							inner.triangle->coords->T1= inner.triangle->line + a;
							inner.triangle->coords->T2=H-temp*h;
							inner.triangle->coords->T3=inner.triangle->line/2 + a;
							inner.triangle->coords->T4=H-(temp+1)*h;
							inner.triangle->coords->T5=inner.triangle->line/2 + inner.triangle->line + a;
							inner.triangle->coords->T6=H-(temp+1)*h;
							writeInnerShape(file,inner);
							inner.SmallShapeNum->number++;
							a += inner.triangle->line;

						}
						t++;
						temp++;
						temp2 += inner.triangle->line/2;

					}

					file<<"</svg>";
					break;			
		default : cout<<"Error\n";			
	}
}

void writeInnerShape(ofstream &file,whichShape inner){

	switch(inner.which)
	{
		case Shapes::rect : file<<"<rect x=\""<<inner.rectangle->coords->x<<"\" "<<"y=\""<<inner.rectangle->coords->y<<"\" width=\""
								<<inner.rectangle->width<<"\" height=\""<<inner.rectangle->height<<"\" "<<"fill=\"green\" />";
							break;
		case Shapes::circle : file<<"<circle cx=\""<<inner.circle->coords->x<<"\" cy=\""<<inner.circle->coords->y<<"\" r=\""
								  <<inner.circle->radius<<"\" "<<"fill=\"green\" />";
							break;
		case Shapes::triangle : file<<"<polygon points=\""<<inner.triangle->coords->T1<<","<<inner.triangle->coords->T2<<" "
								<<inner.triangle->coords->T3<<","<<inner.triangle->coords->T4<<" "<<inner.triangle->coords->T5
								<<","<<inner.triangle->coords->T6<<"\" "<<"fill=\"green\"/>";
							break;
		default : cout<<"Error\n";					
	}	
}

void printSmallShapeNumAndEmptyArea(whichShape outer,whichShape inner){
	shapeArea(outer);
	shapeArea(inner);
	double emptyArea;
	if(outer.area > inner.area*inner.SmallShapeNum->number )
		emptyArea = outer.area - (inner.area*inner.SmallShapeNum->number);

	else	
		emptyArea = (inner.area*inner.SmallShapeNum->number) - outer.area;
	cout<<"I can fit at most "<<inner.SmallShapeNum->number<<" small shapes into the main container. The empty area (red) in container is "
		<<emptyArea<<endl; 
}

void shapeArea(whichShape &shape){

	if(shape.which == Shapes::rect)
		shape.area=(shape.rectangle->width)*(shape.rectangle->height);
	else if(shape.which == Shapes::circle)
		shape.area=PI*shape.circle->radius*shape.circle->radius;
	else
		shape.area=((shape.triangle->line/2)*sqrt(3)*shape.triangle->line)/2;
}









