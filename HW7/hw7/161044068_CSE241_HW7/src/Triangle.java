import java.awt.Graphics;
import java.awt.Polygon;
public class Triangle implements Shape{
	private int line;
	private double coordx1,coordx2,coordx3;
	private double coordy1,coordy2,coordy3;
	
	public Triangle() throws IllegalArgumentException{
		this(50);
	}

	/**
	 *
	 * @param size Ucgenin kenar uzunlugudur.
	 * @throws IllegalArgumentException Gelen size negatif bir degerse bu exception firlatilir.
	 */
	public Triangle(int size) throws IllegalArgumentException{
		if(size < 0)
			throw new IllegalArgumentException();
		this.line = size;
	}

	/**
	 *
	 * @param size Ucgenin kenar uzunlugudur.
	 * @param coordx1 Ucgenin 1. x coordinatidir.
	 * @param coordy1 Ucgenin 1. y coordinatidir.
	 * @param coordx2 Ucgenin 2. x coordinatidir.
	 * @param coordy2 Ucgenin 2. y coordinatidir.
	 * @param coordx3 Ucgenin 3. x coordinatidir.
	 * @param coordy3 Ucgenin 3. y coordinatidir.
	 * @throws IllegalArgumentException Ucgenin kenar uzunlugu ve coordinatlari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public Triangle(int size,double coordx1,double coordy1,double coordx2,double coordy2,double coordx3,double coordy3) throws IllegalArgumentException{
		if(size<0 || coordx1<0 || coordy1<0 || coordx2<0 || coordy2<0 || coordx3<0 || coordy3<0)
			throw new IllegalArgumentException();
		this.line = size; 
		this.coordx1 = coordx1; this.coordy1 = coordy1; 
		this.coordx2 = coordx2; this.coordy2 = coordy2;
		this.coordx3 = coordx3; this.coordy3 = coordy3;
	}

	/**
	 *
	 * @return Ucgenin kenar uzunlugu return edilir.
	 */
	public int getSize() { return line; }
	public double getCoordx1() { return coordx1; }
	public double getCoordx2() { return coordx2; }
	public double getCoordx3() { return coordx3; }
	public double getCoordy1() { return coordy1; }
	public double getCoordy2() { return coordy2; }
	public double getCoordy3() { return coordy3; }

	/**
	 *
	 * @param line Ucgenin kenar uzunlugudur.
	 * @throws IllegalArgumentException Ucgenin kenar uzunlugu sifirdan kucuk olamayacagi
	 * icin bu exception firlatilir.
	 */
	public void setSize(int line) throws IllegalArgumentException{
		if(line < 0)
			throw new IllegalArgumentException();
		this.line = line; 
	}

	/**
	 *
	 * @param coordx Ucgenin 1. x coordinatidir.
	 * @param coordy Ucgenin 1. y coordinatidir.
	 * @throws IllegalArgumentException Ucgenin koordinatlari sifir olamayaci icin
	 * bu exception firlatilir.
	 */
	public void setCoord1(double coordx, double coordy) throws IllegalArgumentException{
		if(coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.coordx1 = coordx;
		this.coordy1 = coordy;
	}

	/**
	 *
	 * @param coordx Ucgenin 2. x coordinatidir.
	 * @param coordy Ucgenin 2. y coordinatidir.
	 * @throws IllegalArgumentException Ucgenin koordinatlari sifir olamayaci icin
	 * bu exception firlatilir.
	 */
	public void setCoord2(double coordx, double coordy) throws IllegalArgumentException{
		if(coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.coordx2 = coordx;
		this.coordy2 = coordy;
	}

	/**
	 *
	 * @param coordx Ucgenin 3. x coordinatidir.
	 * @param coordy Ucgenin 3. y coordinatidir.
	 * @throws IllegalArgumentException  Ucgenin koordinatlari sifir olamayaci icin
	 * bu exception firlatilir.
	 */
	public void setCoord3(double coordx, double coordy) throws IllegalArgumentException{
		if(coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.coordx3 = coordx;
		this.coordy3 = coordy;
	}

	/**
	 *
	 * @return Ucgenin alani return  edilir.
	 */
	public double area() {
		return ((double)(this.getSize() * this.getSize()) * Math.sqrt(3.0)/4.0);
	}

	/**
	 *
	 * @return Ucgenin cevresi return edilir.
	 */
	public double perimeter() {
		return (3.0 * (double)(this.getSize()));
	}

	/**
	 * Ucgenin koordinatlari 1.0 kadar artirilir.
	 */
	public void increment() {
		this.coordx1 = this.coordx1 + 1.0;
		this.coordy1 = this.coordy1 + 1.0;
		this.coordx2 = this.coordx2 + 1.0;
		this.coordy2 = this.coordy2 + 1.0;
		this.coordx3 = this.coordx3 + 1.0;
		this.coordy3 = this.coordy3 + 1.0;
	}

	/**
	 * Ucgenin koordinatlari 1.0 kadar azaltilir.
	 */
	public void decrement() {
		this.coordx1 = this.coordx1 - 1.0;
		this.coordy1 = this.coordy1 - 1.0;
		this.coordx2 = this.coordx2 - 1.0;
		this.coordy2 = this.coordy2 - 1.0;
		this.coordx3 = this.coordx3 - 1.0;
		this.coordy3 = this.coordy3 - 1.0;
	}

	/**
	 * Ucgen cizilir.
	 * @param draw Graphics tipinde bir degisken
	 */
	public void Draw(Graphics draw) {
		Polygon p = new Polygon();
		p.addPoint((int)coordx1,(int)coordy1); p.addPoint((int)coordx2,(int)coordy2); p.addPoint((int)coordx3,(int)coordy3);
		draw.fillPolygon(p);
	}

	/**
	 *
	 * Ucgenin alanı gelen shapin alanıyla karşılaştilir.
	 * @param o Shape objesi
	 * @return Gelen objenin alani bu objeden buyukse -1,esitlerse 0
	 * gelen objenin alani bu objeden kucukse 1 return edilir.
	 */
	public int compareTo(Shape o) {
		if(this.area() == o.area())
			return 0;
		else if(this.area() > o.area())
			return 1;
		else
			return -1;
	}

}
