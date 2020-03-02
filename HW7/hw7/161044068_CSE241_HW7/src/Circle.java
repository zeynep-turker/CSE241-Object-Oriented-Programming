
import java.awt.Graphics;
public class Circle implements Shape {
  private static final double PI =  3.141818;

  private int line;

  private double coordx;

  private double coordy;

  public Circle() throws IllegalArgumentException {
		this(100);
  }

  /**
   * 
   * @param size dairenin yaricapidir.
   * @throws IllegalArgumentException size a negatif bir sayi girildiginde firlatilir.
   */
  public Circle(int size) throws IllegalArgumentException {
		if(size < 0)
			throw new IllegalArgumentException();
		this.line = size;	
  }

  /**
   * 
   * 
   * @param size dairenin yaricapidir.
   * @param coordx dairenin x coordinatidir.
   * @param coordy dairenin y coordinatidir.
   * @throws IllegalArgumentException size ya da coordinatlara negatif bir sayi girildiginde firlatilir.
   */
  public Circle(int size, double coordx, double coordy) throws IllegalArgumentException {
		if(size < 0 || coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.line = size;
		this.coordx = coordx;
		this.coordy = coordy;
  }

  /**
   * 
   * @return Dairenin yaricapini return eder.
   */
  public int getSize() {
 return line;
  }

  /**
   * 
   * @return Dairenin x coordinatini return eder.
   */
  public double getCoordx() {
 return coordx;
  }

  /**
   * 
   * @return  Dairenin y coordinatini return eder.
   */
  public double getCoordy() {
 return coordy;
  }

  /**
   * 
   * @param size Dairenin yaricapidir.
   * @throws IllegalArgumentException Size negatif bir sayi girilirse bu
   * exception firlatilir.
   */
  public void setSize(int size) throws IllegalArgumentException {
		if(size < 0)
			throw new IllegalArgumentException();
		this.line = size; 
  }

  /**
   * 
   * @param coordx Dairenin x coordinatidir.
   * @throws IllegalArgumentException coordx negatif bir sayi girilirse bu
   * exception firlatilir.
   */
  public void setCoordx(double coordx) throws IllegalArgumentException {
		if(coordx < 0)
			throw new IllegalArgumentException();
		this.coordx = coordx; 
  }

  /**
   * 
   * @param coordy Dairenin y coordinatidir.
   * @throws IllegalArgumentException coordy negatif bir sayi girilirse bu
   * exception firlatilir.
   */
  public void setCoordy(double coordy) throws IllegalArgumentException {
		if(coordy < 0)
			throw new IllegalArgumentException();
		this.coordy = coordy; 
  }

  /**
   * 
   * @param coordx Dairenin x coordinatidir.
   * @param coordy Dairenin y coordinatidir
   * @throws IllegalArgumentException coordinatlar negatif bir sayi girilirse bu
   * exception firlatilir.
   */
  public void setCoord(double coordx, double coordy) throws IllegalArgumentException {
		if(coordx < 0 || coordy < 0)
			throw new IllegalArgumentException();
		this.coordx = coordx; this.coordy = coordy; 
  }

  /**
   * 
   * @return Dairenin alani return edilir.
   */
  public double area() {
		return PI *(double)(this.getSize() * this.getSize());
  }

  /**
   * 
   * @return Dairenin çevresi return edilir.
   */
  public double perimeter() {
		return 2 * PI * this.getSize();
  }

  /**
   * Dairenin coordinatlari 1.0 artirilir.
   */
  public void increment() {
		this.coordx = this.coordx + 1.0;
		this.coordy = this.coordy + 1.0;
  }

  /**
   *  Dairenin coordinatlari 1.0 azaltilir.
   */
  public void decrement() {
		this.coordx = this.coordx - 1.0;
		this.coordy = this.coordy - 1.0;	
  }

  /**
   * Daire cizilir.
   * @param draw Graphics tipinde bir degisken
   */
  public void Draw(Graphics draw) {
		draw.fillOval((int)coordx, (int)coordy, line, line);
  }

  /**
   * Dairenin alanı gelen shapin alanıyla karşılaştilir.
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
