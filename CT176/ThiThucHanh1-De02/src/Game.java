import java.io.*;
import java.util.Scanner;

public class Game {
	private static Scanner s;

	public static void main(String[] args) {
		Cuop linh = new Cuop("Cuop 001", new ToaDo(200, 200), 50, 100, "Mo khoa");
		linh.doiViTri(100, 200);
		System.out.println("Thong tin ten linh: ");
		linh.xuatThongTin();
		
		s = new Scanner(System.in);
		int n;
		System.out.print("\nNhap so ten cuop: ");
		n = s.nextInt();
		Cuop[] cuop = new Cuop[n];
		for(int i=0; i<n; i++) {
			cuop[i] = new Cuop();
			System.out.print("Nhap thong tin ten cuop thu " + (i+1) + ": ");
			cuop[i].nhapThongTin();
		}
		
		//Xuat thong tin cua n ten cuop ra file save.bin
		
		try {
			ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("save.bin")));
			for(int i=0; i<n; i++) {
				out.writeObject(cuop[i]);
			}
			out.flush();
			out.close();
			System.out.print("\nDa ghi thong tin thanh cong vao file save.bin");
		}
		catch(IOException e) {
			System.out.print("\nLoi: " + e);
		}
		
		//Nhap thong tin cua n ten cuop tu file save.bin
		Cuop[] cuop1 = new Cuop[n];
		
		try {
			ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(new FileInputStream("save.bin")));
			for(int i=0; i<n; i++) {
				cuop1[i] = new Cuop();
				cuop1[i] = (Cuop)in.readObject();
			}
			in.close();
			System.out.println("\nDa doc thong tin thanh cong tu file save.bin");
		}
		catch(IOException | ClassNotFoundException e) {
			System.out.print("\nLoi: " + e);
		}
		
		for(int i=0; i<n; i++) {
			System.out.println("\nThong tin ten cuop thu " + (i+1) + ": ");
			cuop1[i].xuatThongTin();
		}
	}
}