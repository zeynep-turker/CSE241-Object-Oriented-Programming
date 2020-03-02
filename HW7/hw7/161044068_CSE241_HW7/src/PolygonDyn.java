import java.awt.Graphics;

public class PolygonDyn extends Polygon{
	private static final double PI = 3.141818;
	private Point2D[] p;
	private int used;
	private int capacity,i;
	private double angle;

    /**
     * ilk atamalar yapilir.
     */
	public PolygonDyn() {
		used = 0;
		capacity = 50;
        p = new Point2D[capacity];
    }

    /**
     *
     * @param num int bir degisken
     * @throws IllegalArgumentException Array capacity sifirdan kucuk olamayacagi icin
     * bu exception firlatilir.
     */
	public PolygonDyn(int num) throws IllegalArgumentException{
		if(num < 0)
			throw new IllegalArgumentException();
		used = 0;
		capacity = num;
        p = new Point2D[capacity];
	}
	public PolygonDyn(double x,double y) {
		used=1;
        capacity=10;
        p = new Point2D[capacity];
        p[0].setCoord(x,y);
	}
    public int getUsed() { return used; }
    public int getCapacity() { return capacity; }
    public Point2D[] getArray() { return p; }

    /**
     *
     * @param shape Shape tipli objedir.
     * @return Point2D leri tutan Array return eder.
     */
    public Point2D[] convert(Shape shape) {
    	if(shape instanceof Rectangle){
    		p = new Point2D[50];
            p[0].setCoord(((Rectangle)shape).getCoordx(),((Rectangle)shape).getCoordy());
            p[1].setCoord(((Rectangle)shape).getCoordx()+((Rectangle)shape).getWidth(),((Rectangle)shape).getCoordy());
            p[2].setCoord(((Rectangle)shape).getCoordx()+((Rectangle)shape).getWidth(),((Rectangle)shape).getCoordy()+((Rectangle)shape).getHeight());
            p[3].setCoord(((Rectangle)shape).getCoordx(),((Rectangle)shape).getCoordy()+((Rectangle)shape).getHeight());
            used = 4;
        }
        else if(shape instanceof Circle){
        	p = new Point2D[150];
            used = 100;
            for(i=0; i<100; i++){
                angle=3.6*i*(PI/180);       
                p[i].setCoord(((Circle)shape).getCoordx()+((Circle)shape).getSize()*Math.cos(angle),((Circle)shape).getCoordy()+((Circle)shape).getSize()*Math.sin(angle));              
            }
        }
        else if(shape instanceof Triangle){
        	p = new Point2D[50];
            p[0].setCoord(((Triangle)shape).getCoordx1(),((Triangle)shape).getCoordy1());
            p[1].setCoord(((Triangle)shape).getCoordx2(),((Triangle)shape).getCoordy2());
            p[2].setCoord(((Triangle)shape).getCoordx3(),((Triangle)shape).getCoordy3());
            used = 3;
        }
    	return p;
    }
    public double area() {return 0;}
    public double perimeter() {return 0;}     
    //public void print(ostream& out,int a)const{};
    //public void printPolygon(ostream& out,vector<Shape*> v);
	public void Draw(Graphics draw) {}
	public void absfunct() {}

}
