package Diem;

import java.util.Scanner;
import java.io.*;

public class Diem implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int x;
	private int y;
	private Scanner s;
	
	Diem() {
		x = 0;
		y = 0;
	}
	
	Diem(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void nhapDiem() {
		s = new Scanner(System.in);
		System.out.print("\nNhap vao hoanh do x: ");
		x = s.nextInt();
		System.out.print("\nNhap vao tung do y: ");
		y = s.nextInt();
	}
	
	public void hienThi() {
		System.out.print("(" + x + "," + y + ")");
	}
	
	public void doiDiem(int dx, int dy) {
		x += dx;
		y += dy;
	}
	
	public int giaTriX() {
		return x;
	}
	
	public int giaTriY() {
		return y;
	}
	
	public float khoangCach() {
		return (float)Math.sqrt(x * x + y * y);
	}
	
	public float khoangCach(Diem d) {
		return (float)Math.sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
	}
	
	public void writeToFile(FileOutputStream f) {
		try {
			ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(f));
			out.writeObject(this);
			out.close();
			System.out.print("\nXuat thanh cong!");
		}
		catch(IOException e) {
			System.out.print("\nLoi nhap xuat!");
		}
	}
	
	public Diem readFromFile(FileInputStream f) {
		try {
			ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(f));
			Diem d = new Diem();
			d = (Diem)in.readObject();
			in.close();
			System.out.print("\nNhap thanh cong!");
			return d;
		}
		catch(IOException | ClassNotFoundException e) {
			System.out.print("\nLoi khi nhap!");
			return null;
		}
	}
}
