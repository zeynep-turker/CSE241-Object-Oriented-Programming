import java.awt.*;

/**
 * Butun shape lerin icerdigi methodlara sahipdir.
 */
public interface Shape extends Comparable<Shape>{
	public double area();
	public double perimeter();
	public void increment();
	public void decrement();
	public void Draw(Graphics draw);
}
