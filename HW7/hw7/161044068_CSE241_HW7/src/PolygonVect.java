import java.awt.Graphics;
import java.util.ArrayList;

public class PolygonVect extends Polygon{
    private static final double PI = 3.141818;
    private Point2D a,b,c,d;
    private int i;
    private double angle;
	private ArrayList<Point2D> v = new ArrayList<Point2D>();
	
	public PolygonVect() {}
	public PolygonVect(double x,double y) {
        a.setCoord(x,y);
        v.add(a);
	}

    /**
     *
     * @return Point2D leri tutan  ArrayList return edilir.
     */
	public ArrayList<Point2D> getVect() { return v; }

    /**
     *
     * @param shape Shapa tipinde bir objedir.
     * @return Point2D leri tutan ArrayList return eder.
     */
	public ArrayList<Point2D> convert(Shape shape){
		if(shape instanceof Rectangle){ 
            a.setCoord(((Rectangle)shape).getCoordx(),((Rectangle)shape).getCoordy());
            b.setCoord(((Rectangle)shape).getCoordx()+((Rectangle)shape).getWidth(),((Rectangle)shape).getCoordy());
            c.setCoord(((Rectangle)shape).getCoordx()+((Rectangle)shape).getWidth(),((Rectangle)shape).getCoordy()+((Rectangle)shape).getHeight());
            d.setCoord(((Rectangle)shape).getCoordx(),((Rectangle)shape).getCoordy()+((Rectangle)shape).getHeight());
            v.add(a);
            v.add(b);
            v.add(c);
            v.add(d);    
        }
        else if(shape instanceof Circle){
            for(i=0; i<100; i++){
                angle=3.6*i*(PI/180);       
                a.setCoord(((Circle)shape).getCoordx()+((Circle)shape).getSize()*Math.cos(angle),((Circle)shape).getCoordy()+((Circle)shape).getSize()*Math.sin(angle));
                v.add(a);
            }
        }
        else if(shape instanceof Triangle){
            a.setCoord(((Triangle)shape).getCoordx1(),((Triangle)shape).getCoordy1());
            b.setCoord(((Triangle)shape).getCoordx2(),((Triangle)shape).getCoordy2());
            c.setCoord(((Triangle)shape).getCoordx3(),((Triangle)shape).getCoordy3());
            v.add(a);
            v.add(b);
            v.add(c);
        }
        return v;
	}
	public double area() {return 0;}
	public double perimeter() {return 0;}
	public void Draw(Graphics draw){}
	public void absfunct() {}
}
