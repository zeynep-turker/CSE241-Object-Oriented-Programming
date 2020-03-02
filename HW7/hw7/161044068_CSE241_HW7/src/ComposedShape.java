import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class ComposedShape extends JPanel implements Shape{
	private Shape Outer,Inner;
	private ArrayList<Shape> shapes = new ArrayList<Shape>();
	private char outer,inner;
	public ComposedShape(Rectangle outer, Rectangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'R';
		this.inner = 'r';
		optimalFit();
	}
	public ComposedShape(Rectangle outer, Circle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'R';
		this.inner = 'c';
		optimalFit(); 
	}
	public ComposedShape(Rectangle outer, Triangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'R';
		this.inner = 't';
		optimalFit(); 
	}
	public ComposedShape(Circle outer, Rectangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'C';
		this.inner = 'r';
		optimalFit(); 
	}
	public ComposedShape(Circle outer, Circle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'C';
		this.inner = 'c';
		optimalFit(); 
	}
	public ComposedShape(Circle outer, Triangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'C';
		this.inner = 't';
		optimalFit(); 
	}
	public ComposedShape(Triangle outer, Rectangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'T';
		this.inner = 'r';
		optimalFit(); 
	}
	public ComposedShape(Triangle outer, Circle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'T';
		this.inner = 'c';
		optimalFit(); 
	}
	public ComposedShape(Triangle outer, Triangle inner) {
		Outer = outer;
		Inner = inner;
		this.outer = 'T';
		this.inner = 't';
		optimalFit(); 
	}

	/**
	 *
	 * @return Shape tutan bir ArrayList return edilir.
	 */
	public ArrayList<Shape> getArrayList() { return shapes; }
	public double area() { return 0; }
	public double perimeter() { return 0; }
	public void increment() {}
	public void decrement() {}
	public void Draw(Graphics draw) {
		draw.setColor(Color.PINK);
		this.getArrayList().get(0).Draw(draw);
		for(int i=0; i<this.getArrayList().size(); ++i) {
			draw.setColor(Color.CYAN);
			this.getArrayList().get(i).Draw(draw);
		}
			
	}
	public int compareTo(Shape o) { return 0; }

	/**
	 * ice ice sekilleri bir ArrayListe toplar.
	 */
	public void optimalFit() {
		if(outer == 'R'){
			Rectangle newRect = new Rectangle();
	        newRect.setWidth(((Rectangle)Outer).getWidth());
	        newRect.setHeight(((Rectangle)Outer).getHeight());
	        newRect.setCoordx(0);
	        newRect.setCoordy(0);
			shapes.add(Outer);
	        if(inner == 'r'){
	        	int i,j,coloumnNum,lineNum;
	            coloumnNum=((Rectangle)Outer).getWidth()/((Rectangle)Inner).getWidth();
	            lineNum=((Rectangle)Outer).getHeight()/((Rectangle)Inner).getHeight();
	            ((Rectangle)Inner).setCoordy(0);
	            for(i=0; i<lineNum; ++i)
	            {
	            	((Rectangle)Inner).setCoordx(0);
	                for(j=0; j<coloumnNum; ++j)
	                {
	                    Rectangle newRect2 = new Rectangle();
	                    newRect2.setWidth(((Rectangle)Inner).getWidth());
	                    newRect2.setHeight(((Rectangle)Inner).getHeight());
	                    newRect2.setCoordx(((Rectangle)Inner).getCoordx());
	                    newRect2.setCoordy(((Rectangle)Inner).getCoordy());
	                    shapes.add(newRect2); 
	                    ((Rectangle)Inner).setCoordx(((Rectangle)Inner).getCoordx() + ((Rectangle)Inner).getWidth());
	                }
	                ((Rectangle)Inner).setCoordy(((Rectangle)Inner).getCoordy() + ((Rectangle)Inner).getHeight());
	             }
	        }
	        else if(inner == 'c'){
	            int i,j,lineNum,coloumnNum;
	            lineNum=((Rectangle)Outer).getHeight()/(2*((Circle)Inner).getSize());
	            coloumnNum=((Rectangle)Outer).getWidth()/(2*((Circle)Inner).getSize());
	            ((Circle)Inner).setCoordy(((Circle)Inner).getSize());
	            for(i=0;i<lineNum;++i){
	            	((Circle)Inner).setCoordx(((Circle)Inner).getSize());
	                for(j=0;j<coloumnNum;++j){                 
	                    Circle newCirc = new Circle();
	                    newCirc.setSize(((Circle)Inner).getSize());
	                    newCirc.setCoordx(((Circle)Inner).getCoordx());
	                    newCirc.setCoordy(((Circle)Inner).getCoordy());
	                    shapes.add(newCirc);                 
	                    ((Circle)Inner).setCoordx(((Circle)Inner).getCoordx() + 2*((Circle)Inner).getSize());
	                }
	                ((Circle)Inner).setCoordy(((Circle)Inner).getCoordy() + 2*((Circle)Inner).getSize());         
	            }
	        }
	        else {
	        int i,j,lineNum,coloumnNum;
            double h=(double)(((Triangle)Inner).getSize()/2.0)*Math.sqrt(3.0);
            int temp=0,temp2=0;
            double y1=h,y2=0.0;
            double r1=0.0,r2=h;

            coloumnNum = (((Rectangle)Outer).getWidth()/((Triangle)Inner).getSize());
            lineNum = (int)((double)((Rectangle)Outer).getHeight()/h);
            
            for (i=0; i < lineNum; ++i){ 
                temp=0;
                for (j=0; j < coloumnNum; ++j)
                {
                	((Triangle)Inner).setCoord1(temp + ((Triangle)Inner).getSize()/2, y1);
                	((Triangle)Inner).setCoord2(temp, y2);
                	((Triangle)Inner).setCoord3(temp + ((Triangle)Inner).getSize(),y2);
                    Triangle newTri = new Triangle();
                    newTri.setSize(((Triangle)Inner).getSize());
                    newTri.setCoord1(((Triangle)Inner).getCoordx1(),((Triangle)Inner).getCoordy1());
                    newTri.setCoord2(((Triangle)Inner).getCoordx2(),((Triangle)Inner).getCoordy2());
                    newTri.setCoord3(((Triangle)Inner).getCoordx3(),((Triangle)Inner).getCoordy3());
                    shapes.add(newTri);  
                    ((Triangle)Inner).setCoord1(((Triangle)Inner).getCoordx1() + ((Triangle)Inner).getSize(), ((Triangle)Inner).getCoordy1());
                    temp += ((Triangle)Inner).getSize();
                }
                y1 +=h;
                y2 +=h;
                for(j=0; j < coloumnNum-1; ++j){
                	((Triangle)Inner).setCoord1(temp2 + ((Triangle)Inner).getSize(), r1);
                	((Triangle)Inner).setCoord2(temp2 + ((Triangle)Inner).getSize()/2,r2);
                	((Triangle)Inner).setCoord3(temp2 + ((Triangle)Inner).getSize() + ((Triangle)Inner).getSize()/2 , r2);
                    Triangle newTri = new Triangle();
                    newTri.setSize(((Triangle)Inner).getSize());
                    newTri.setCoord1(((Triangle)Inner).getCoordx1(),((Triangle)Inner).getCoordy1());
                    newTri.setCoord2(((Triangle)Inner).getCoordx2(),((Triangle)Inner).getCoordy2());
                    newTri.setCoord3(((Triangle)Inner).getCoordx3(),((Triangle)Inner).getCoordy3());
                    shapes.add(newTri);  
                    temp2 += ((Triangle)Inner).getSize();
                }
                temp2=0;
                r1 += h;
                r2 += h;
            	}         
	        }
		}
		else if(outer == 'C'){
	        Circle newCirc = new Circle();
	        newCirc.setSize(((Circle)Outer).getSize());
	        newCirc.setCoordx(((Circle)Outer).getSize());
	        newCirc.setCoordy(((Circle)Outer).getSize());
	        shapes.add(newCirc);           
	        if(inner == 'r'){
	            int i;
	            int j,a,b,c,d,h,lineNum,coloumnNum;
	            lineNum = 2*((Circle)Outer).getSize() / ((Rectangle)Inner).getHeight();
	            for(i=0; i<lineNum/2; ++i){
	                a=((Circle)Outer).getSize() - (i+1)*((Rectangle)Inner).getHeight();
	                ((Rectangle)Inner).setCoordx(((Circle)Outer).getSize());
	                ((Rectangle)Inner).setCoordy(a);            
	                Rectangle newRect = new Rectangle();
	                newRect.setWidth(((Rectangle)Inner).getWidth());
	                newRect.setHeight(((Rectangle)Inner).getHeight());
	                newRect.setCoordx(((Rectangle)Inner).getCoordx());
	                newRect.setCoordy(((Rectangle)Inner).getCoordy());
	                shapes.add(newRect); 
	            }
	           for(i=0; i<lineNum/2; ++i){
	                a=((Circle)Outer).getSize() + (i)*((Rectangle)Inner).getHeight();
	                ((Rectangle)Inner).setCoordx(((Circle)Outer).getSize());
	                ((Rectangle)Inner).setCoordy(a);
	                Rectangle newRect = new Rectangle();
	                newRect.setWidth(((Rectangle)Inner).getWidth());
	                newRect.setHeight(((Rectangle)Inner).getHeight());
	                newRect.setCoordx(((Rectangle)Inner).getCoordx());
	                newRect.setCoordy(((Rectangle)Inner).getCoordy());
	                shapes.add(newRect); 
	            }
	        }
	        else if(inner == 'c'){
	            int i,j,a,b,c,d,h,lineNum,coloumnNum;
	            coloumnNum = ((Circle)Outer).getSize() / ((Circle)Inner).getSize();
	            ((Circle)Inner).setCoordx(((Circle)Outer).getSize());
	            ((Circle)Inner).setCoordy(((Circle)Outer).getSize());
	            Circle newCirccc = new Circle();
	            newCirccc.setSize(((Circle)Inner).getSize());
	            newCirccc.setCoordx(((Circle)Inner).getCoordx());
	            newCirccc.setCoordy(((Circle)Inner).getCoordy());
	            shapes.add(newCirccc);     
	            for(i=0; i<(coloumnNum-1)/2; ++i){
	                a=((Circle)Outer).getSize()-(i+1)*2*((Circle)Inner).getSize();
	                ((Circle)Inner).setCoordx(a);
	                ((Circle)Inner).setCoordy(((Circle)Outer).getSize());
	                Circle newCircc = new Circle();
	                newCircc.setSize(((Circle)Inner).getSize());
	                newCircc.setCoordx(((Circle)Inner).getCoordx());
	                newCircc.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCircc);     
	                b=((Circle)Outer).getSize()+(i+1)*2*((Circle)Inner).getSize();
	                ((Circle)Inner).setCoordx(b);
	                ((Circle)Inner).setCoordy(((Circle)Outer).getSize());
	                Circle newCirc6 = new Circle();
	                newCirc6.setSize(((Circle)Inner).getSize());
	                newCirc6.setCoordx(((Circle)Inner).getCoordx());
	                newCirc6.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc6);     
	            }
	            lineNum=(((Circle)Outer).getSize()-((Circle)Inner).getSize())/(((Circle)Inner).getSize()*2);         
	            for(i=0; i<lineNum; ++i){
	                a=((Circle)Outer).getSize()-(i+1)*2*((Circle)Inner).getSize();
	                h=((Circle)Outer).getSize()+(i+1)*2*((Circle)Inner).getSize();
	                ((Circle)Inner).setCoordx(((Circle)Outer).getSize());
	                ((Circle)Inner).setCoordy(a);
	                Circle newCirc7 = new Circle();
	                newCirc7.setSize(((Circle)Inner).getSize());
	                newCirc7.setCoordx(((Circle)Inner).getCoordx());
	                newCirc7.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc7);     
	                ((Circle)Inner).setCoordx(((Circle)Outer).getSize());
	                ((Circle)Inner).setCoordy(h);
	                Circle newCirc5 = new Circle();
	                newCirc5.setSize(((Circle)Inner).getSize());
	                newCirc5.setCoordx(((Circle)Inner).getCoordx());
	                newCirc5.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc5);     
	                coloumnNum = (((Circle)Outer).getSize()-2*(i+1)) / ((Circle)Inner).getSize();
	            for(j=0; j<(int)(coloumnNum-1)/2; ++j){
	                c=((Circle)Outer).getSize()-(j+1)*2*((Circle)Inner).getSize();
	                d=((Circle)Outer).getSize()+(j+1)*2*((Circle)Inner).getSize();
	                ((Circle)Inner).setCoordx(c);
	                ((Circle)Inner).setCoordy(a);
	                Circle newCirc11 = new Circle();
	                newCirc11.setSize(((Circle)Inner).getSize());
	                newCirc11.setCoordx(((Circle)Inner).getCoordx());
	                newCirc11.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc11);     
	                ((Circle)Inner).setCoordx(d);
	                ((Circle)Inner).setCoordy(a);
	                Circle newCirc2 = new Circle();
	                newCirc2.setSize(((Circle)Inner).getSize());
	                newCirc2.setCoordx(((Circle)Inner).getCoordx());
	                newCirc2.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc2);     
	                ((Circle)Inner).setCoordx(c);
	                ((Circle)Inner).setCoordy(h);
	                Circle newCirc3 = new Circle();
	                newCirc3.setSize(((Circle)Inner).getSize());
	                newCirc3.setCoordx(((Circle)Inner).getCoordx());
	                newCirc3.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc3);     
	                ((Circle)Inner).setCoordx(d);
	                ((Circle)Inner).setCoordy(h);
	                Circle newCirc4 = new Circle();
	                newCirc4.setSize(((Circle)Inner).getSize());
	                newCirc4.setCoordx(((Circle)Inner).getCoordx());
	                newCirc4.setCoordy(((Circle)Inner).getCoordy());
	                shapes.add(newCirc4);     
	                }
	            }
	        }
	        else{
	            ((Triangle)Inner).setCoord1(((Circle)Outer).getSize(),((Circle)Outer).getSize()-(((((Triangle)Inner).getSize()/2)*Math.sqrt(3))/2));
	            ((Triangle)Inner).setCoord2(((Circle)Outer).getSize()-(((Triangle)Inner).getSize()/2),((Circle)Outer).getSize()+((((Triangle)Inner).getSize()/2)*Math.sqrt(3))/2);
	            ((Triangle)Inner).setCoord3(((Circle)Outer).getSize()+(((Triangle)Inner).getSize()/2),((Circle)Outer).getSize()+((((Triangle)Inner).getSize()/2)*Math.sqrt(3))/2);
	            Triangle newTri = new Triangle();
	            newTri.setSize(((Triangle)Inner).getSize());
	            newTri.setCoord1(((Triangle)Inner).getCoordx1(),((Triangle)Inner).getCoordy1());
	            newTri.setCoord2(((Triangle)Inner).getCoordx2(),((Triangle)Inner).getCoordy2());
	            newTri.setCoord3(((Triangle)Inner).getCoordx3(),((Triangle)Inner).getCoordy3());
	            shapes.add(newTri);  
	               
	        }
	    }
		else  {
	        Triangle newTri = new Triangle();
	        newTri.setSize(((Triangle)Outer).getSize());
	        newTri.setCoord1((double)(((Triangle)Outer).getSize()/2),0);
	        newTri.setCoord2(0,(double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3));
	        newTri.setCoord3(((Triangle)Outer).getSize(),(double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3));
	        shapes.add(newTri);  
	        if(inner == 'r'){
	            int i,j,lineNum,coloumnNum,th,temp;
	            double a,ta,h;
	            temp=0;
	            a = ((Rectangle)Inner).getHeight()/Math.sqrt(3);
	            h = (double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3);
	            lineNum = (int)(h / ((Rectangle)Inner).getHeight());

	            for(i=0; i<lineNum; ++i){
	                    ta = (double)(i+1)*a;
	                    th = (int)(((int)(h-temp*((Rectangle)Inner).getHeight())/Math.sqrt(3))*2);
	                    coloumnNum = (int)((th-2*a)/((Rectangle)Inner).getWidth());
	                    for(j=0; j<coloumnNum; ++j){
	                    	((Rectangle)Inner).setCoordx(ta);
	                    	((Rectangle)Inner).setCoordy(h-(double)((i+1)*((Rectangle)Inner).getHeight()));
	                        Rectangle newRect = new Rectangle();
	                        newRect.setWidth(((Rectangle)Inner).getWidth());
	                        newRect.setHeight(((Rectangle)Inner).getHeight());
	                        newRect.setCoordx(((Rectangle)Inner).getCoordx());
	                        newRect.setCoordy(((Rectangle)Inner).getCoordy());
	                        shapes.add(newRect); 
	                        ta += ((Rectangle)Inner).getWidth();
	                    }
	                    temp++;
	            }
	        }
	        else if(inner == 'c'){
	            double b,ch,c,h;
	            int i,j,lineNum,coloumnNum,temp;
	            h = (double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3);
	            b = (double)((((Circle)Inner).getSize()/(Math.sqrt(3)+2))+((Circle)Inner).getSize())/Math.sqrt(3);
	            c = b*Math.sqrt(3);
	            lineNum = (int)(h/(2*((Circle)Inner).getSize()));
	            for(i=0; i<lineNum; ++i){
	                ch = ((Triangle)Outer).getSize() - (double)(2*(((i*2*((Circle)Inner).getSize())+ c))/Math.sqrt(3));
	                coloumnNum = (int)(ch/(2*((Circle)Inner).getSize()));
	                temp=0;
	                for(j=0; j<coloumnNum; ++j){
	                	((Circle)Inner).setCoordx((i*2*((Circle)Inner).getSize()+c)/Math.sqrt(3)+((Circle)Inner).getSize()+temp*2*((Circle)Inner).getSize());
	                	((Circle)Inner).setCoordy(h-((Circle)Inner).getSize() -i*2*((Circle)Inner).getSize());
	                    Circle newCirc = new Circle();
	                    newCirc.setSize(((Circle)Inner).getSize());
	                    newCirc.setCoordx(((Circle)Inner).getCoordx());
	                    newCirc.setCoordy(((Circle)Inner).getCoordy());
	                    shapes.add(newCirc);       
	                    temp++;
	                }
	            }  
	            
	        }
	        else{
	            double H,h;
	            int i,j,lineNum,coloumnNum,coloumnNum2;
	            int t,temp,temp2,a;
	            t=1;
	            H=(double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3);
	            h=(double)(((Triangle)Outer).getSize()/2)*Math.sqrt(3);
	            lineNum=(int)(H/h);
	            temp=0;
	            temp2=0;
	            for(i=0;i<lineNum;++i){
	                    coloumnNum=(int)((H-temp*h)/Math.sqrt(3))*2 / ((Triangle)Inner).getSize();
	                    coloumnNum2=(int)((H-t*h)/Math.sqrt(3))*2 / ((Triangle)Inner).getSize();
	                    a=temp2;
	                    for(j=0;j<coloumnNum;++j){
	                    	((Triangle)Inner).setCoord1(((Triangle)Inner).getSize()/2 + a, H-(temp+1)*h);                     
	                    	((Triangle)Inner).setCoord2(a, H-temp*h);
	                    	((Triangle)Inner).setCoord3(((Triangle)Inner).getSize() + a, H-temp*h) ; 
	                    	Triangle newTrii = new Triangle();
	                    	newTrii.setSize(((Triangle)Inner).getSize());
	                    	newTrii.setCoord1(((Triangle)Inner).getCoordx1(),((Triangle)Inner).getCoordy1());
	                    	newTrii.setCoord2(((Triangle)Inner).getCoordx2(),((Triangle)Inner).getCoordy2());
	                    	newTrii.setCoord3(((Triangle)Inner).getCoordx3(),((Triangle)Inner).getCoordy3());
	                            shapes.add(newTrii);                             
	                            a += ((Triangle)Inner).getSize();
	                    }
	                    a=temp2;
	                    for(j=0;j<coloumnNum2;++j){
	                    	((Triangle)Inner).setCoord1(((Triangle)Inner).getSize() + a, H-temp*h);                           
	                    	((Triangle)Inner).setCoord2(((Triangle)Inner).getSize()/2 + a, H-(temp+1)*h);                            
	                    	((Triangle)Inner).setCoord3(((Triangle)Inner).getSize()/2 + ((Triangle)Inner).getSize() + a, H-(temp+1)*h);  
	                            Triangle newTriii = new Triangle();
	                            newTriii.setSize(((Triangle)Inner).getSize());
	                            newTriii.setCoord1(((Triangle)Inner).getCoordx1(),((Triangle)Inner).getCoordy1());
	                            newTriii.setCoord2(((Triangle)Inner).getCoordx2(),((Triangle)Inner).getCoordy2());
	                            newTriii.setCoord3(((Triangle)Inner).getCoordx3(),((Triangle)Inner).getCoordy3());
	                            shapes.add(newTriii);                                                
	                            a += ((Triangle)Inner).getSize();
	                    }
	                    t++;
	                    temp++;
	                    temp2 += ((Triangle)Inner).getSize()/2;
	            }
       
	        }
		}
	}
	/*public void paintCompotent(Graphics g) {
		
		for(int i=0; i<getArrayList().size(); ++i) {
			if(i != 0) {
				g.setColor(Color.red);
				getArrayList().get(i).Draw(g);
			}
			else {
			g.setColor(Color.green);
			getArrayList().get(0).Draw(g);
			}
		}
		super.paintComponents(g);
	}*/
}