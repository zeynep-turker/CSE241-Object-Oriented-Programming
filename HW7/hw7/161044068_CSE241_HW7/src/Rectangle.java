import java.awt.Graphics;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Rectangle extends JPanel implements Shape{
	private int width,height;
	private double coordx,coordy;
	public Rectangle() {
		this(100,50);
	}
	public Rectangle(int width, int height)throws IllegalArgumentException{
		if(width < 0 || height < 0)
			throw new IllegalArgumentException();
		this.width = width;
		this.height = height;	
	}

	/**
	 *
	 * @param width Dikdortgenin uzun kenaridir.
	 * @param height Dikdortgenin kisa kenaridir.
	 * @param coordx Dikdortgenin x coordinatidir.
	 * @param coordy Dikdortgenin y coordinatidir.
	 * @throws IllegalArgumentException Dikdortgenin kenarlari ve coordinatlari sifirdan kucuk
	 * olamayacagi icin bu exception firlatilir.
	 */
	public Rectangle(int width, int height, double coordx, double coordy) throws IllegalArgumentException{
		if(width < 0 || height < 0 || coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.width = width;
		this.height = height;
		this.coordx = coordx;
		this.coordy = coordy;
	}

	/**
	 *
	 * @return Dikdortgenin kisa kenari return edilir.
	 */
	public int getHeight() { return height; }

	/**
	 *
	 * @return Dikdortgenin uzun kenari return edilir.
	 */
	public int getWidth() { return width; }

	/**
	 *
	 * @return Dikdortgenin x coordinati return edilir.
	 */
	public double getCoordx() { return coordx; }

	/**
	 *
	 * @return  Dikdortgenin y coordinati return edilir.
	 */
	public double getCoordy() { return coordy; }

	/**
	 *
	 * @param height int tipinde bir degisken.
	 * @throws IllegalArgumentException Dikdortgenin kenari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public void setHeight(int height) throws IllegalArgumentException{
		if(height < 0)
			throw  new IllegalArgumentException();
		this.height = height; 
	}

	/**
	 *
	 * @param width int tipinde bir degisken.
	 * @throws IllegalArgumentException Dikdortgenin kenari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public void setWidth(int width) throws IllegalArgumentException{
		if(width < 0)
			throw new IllegalArgumentException();
		this.width = width; 
	}

	/**
	 *
	 * @param coordx double tipinde bir degisken
	 * @throws IllegalArgumentException Dikdortgenin koordinatlari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public void setCoordx(double coordx) throws IllegalArgumentException{
		if(coordx < 0)
			throw new IllegalArgumentException();
		this.coordx = coordx;
	}

	/**
	 *
	 * @param coordy double tipinde bir degisken
	 * @throws IllegalArgumentException Dikdortgenin koordinatlari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public void setCoordy(double coordy) throws IllegalArgumentException{
		if(coordy < 0)
			throw new IllegalArgumentException();
		this.coordy = coordy; 
	}

	/**
	 *
	 * @param coordx double tipinde bir degisken
	 * @param coordy doubles tipinde bir degisken
	 * @throws IllegalArgumentException Dikdortgenin koordinatlari sifirdan kucuk olamayacagi icin
	 * bu exception firlatilir.
	 */
	public void setCoord(double coordx, double coordy) throws IllegalArgumentException{
		if(coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.coordx = coordx; 
		this.coordy = coordy; 
	}

	/**
	 *
	 * @return Dikdortgenin alani return ediilir.
	 */
	public double area() {
		return ((double)(this.getWidth() * this.getHeight()));
	}

	/**
	 *
	 * @return  Dikdortgenin cevresi return ediilir.
	 */
	public double perimeter() {
		return ((double)((2.0*this.getWidth()) + (2.0*this.getHeight())));
	}

	/**
	 * Dikdortgenin koordinatlari 1.0 kadar artirilir.
	 */
	public void increment() {
		this.coordx = this.coordx + 1.0;
		this.coordy = this.coordy + 1.0;
	}

	/**
	 * Dikdortgenin koordinatlari 1.0 kadar azaltilit.
	 */
	public void decrement() {
		this.coordx = this.coordx - 1.0;
		this.coordy = this.coordy - 1.0;	
	}

	/**
	 * dikdortgen cizilir.
	 * @param draw Graphics tipinde bir degiskendir.
	 */
	public void Draw(Graphics draw) {
		draw.fillRect((int)coordx, (int)coordy, width, height);
	}

	/**
	 *
	 * Dikdortgenin alanı gelen shapin alanıyla karşılaştilir.
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
