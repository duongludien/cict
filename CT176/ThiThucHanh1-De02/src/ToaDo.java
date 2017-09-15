import java.io.Serializable;
import java.util.Scanner;

public class ToaDo implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int x;
	private int y;
	private static final Scanner s = new Scanner(System.in);
	
	ToaDo() {
		x = 0;
		y = 0;
	}
	
	ToaDo(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void nhapToaDo() {
		System.out.print("Nhap hoanh do x: ");
		x = s.nextInt();
		System.out.print("Nhap tung do y: ");
		y = s.nextInt();
	}
	
	public void xuatToaDo() {
		System.out.print("(" + x + "," + y + ")");
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
}
