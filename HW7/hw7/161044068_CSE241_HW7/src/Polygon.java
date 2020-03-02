
public abstract class Polygon implements Shape{
	private int h,w;
	private double x1,y1,x2,x3,y2,y3;
	public Polygon(){}
		class Point2D {
			private double x,y;
			public Point2D() { x=0; y=0; }
			public double getCoordX(){ return x; }
			public double getCoordY(){ return y; }
			public void setCoordX(double CoordX) throws IllegalArgumentException{
				if(CoordX < 0)
					throw new IllegalArgumentException();
				x=CoordX;
			}
			public void setCoordY(double CoordY) throws IllegalArgumentException{
				if(CoordY < 0)
					throw new IllegalArgumentException();
				y=CoordY;
			}
			public void setCoord(double CoordX,double CoordY) throws IllegalArgumentException{
				if(CoordX < 0 || CoordY < 0)
					throw new IllegalArgumentException();
				x=CoordX;
				y=CoordY;
			} 
		}
	public void setCoord1(double coordX, double coordY) throws IllegalArgumentException{
			if(coordX < 0 || coordY < 0)
				throw new IllegalArgumentException();
	     	x1=coordX;
	     	y1=coordY;
	}	
	public void setCoord2(double coordX, double coordY) throws IllegalArgumentException{
		if(coordX < 0 || coordY < 0)
			throw new IllegalArgumentException();
     	x2=coordX;
     	y2=coordY;
	}	
	public void setCoord3(double coordX, double coordY) throws IllegalArgumentException{
		if(coordX < 0 || coordY < 0)
			throw new IllegalArgumentException();
     	x3=coordX;
     	y3=coordY;
	}
    public void setHeight(int height) throws IllegalArgumentException{
    	if(height < 0)
    		throw new IllegalArgumentException();
    	h=height;
	}
    public void setWidth(int width) throws IllegalArgumentException{
    	if(width < 0)
    		throw new IllegalArgumentException();
    	w=width;
	}
    public double getWidth() { return w; }
    public double getHeight() { return h; }
    public double getCoordX1() { return x1; }
    public double getCoordY1() { return y1; }
    public double getCoordX2() { return x2; }
    public double getCoordY2() { return y2; }
    public double getCoordX3() { return x3; }
    public double getCoordY3() { return y3; }
    public abstract void absfunct();
    public void increment() {}
    public void decrement() {}
    public int compareTo(Shape o) { return 0; }
}
