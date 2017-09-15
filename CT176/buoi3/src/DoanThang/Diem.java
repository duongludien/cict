package DoanThang;
import java.util.Scanner;

public class Diem {

    private int x;
    private int y;
	private Scanner s;

    Diem() {
        this.x = 0;
        this.y = 0;
    }

    Diem(int a, int b) {
        this.x = a;
        this.y = b;
    }

    public void nhapDiem() {
        s = new Scanner(System.in);

        System.out.print("\nNhap vao hoanh do: x = ");
        this.x = s.nextInt();

        System.out.print("\nNhap vao tung do: y = ");
        this.y = s.nextInt();

        //s.close();
    }

    public void hienThi() {
        System.out.print("(" + this.x + "," + this.y + ")");
    }

    public void doiDiem(int dx, int dy) {
        this.x += dx;
        this.y += dy;
    }

    public int giaTriX() {
        return x;
    }

    public int giaTriY() {
        return y;
    }

    public float khoangCach() {
        return (float) Math.sqrt(this.x * this.x + this.y * this.y);
    }

    public float khoangCach(Diem d) {
        return (float) Math.sqrt((this.x - d.x) * (this.x - d.x) + (this.y - d.y) * (this.y - d.y));
    }

	public void setX(int x) {
		this.x = x;
	}

	public void setY(int y) {
		this.y = y;
	}

}