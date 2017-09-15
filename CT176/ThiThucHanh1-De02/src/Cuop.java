import java.io.Serializable;
import java.util.Scanner;

public class Cuop implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String maNhanVat;
	private ToaDo viTri;
	private int mucDoNguyHiem;
	private int nangLuong;
	private String soTruong;
	private static final Scanner s = new Scanner(System.in);
	
	Cuop() {
		maNhanVat = null;
		viTri = new ToaDo();
		mucDoNguyHiem = 0;
		nangLuong = 0;
		soTruong = null;
	}
	
	Cuop(String mnv, ToaDo td, int mdnh, int nl, String st) {
		maNhanVat = mnv;
		viTri = new ToaDo(td.getX(), td.getY());
		mucDoNguyHiem = mdnh;
		nangLuong = nl;
		soTruong = st;
	}
	
	public void nhapThongTin() {
		System.out.print("\nNhap ma nhan vat: ");
		maNhanVat = s.nextLine();
		System.out.println("\nNhap vi tri: ");
		viTri.nhapToaDo();
		System.out.print("\nNhap muc do nguy hiem: ");
		mucDoNguyHiem = s.nextInt();
		System.out.print("\nNhap nang luong: ");
		nangLuong = s.nextInt();
		s.nextLine();
		System.out.print("\nNhap so truong: ");
		soTruong = s.nextLine();
	}
	
	public void xuatThongTin() {
		System.out.println("+ Ma nhan vat: " + maNhanVat);
		System.out.print("+ Vi tri: ");
		viTri.xuatToaDo();
		
		System.out.println("\n+ Muc do nguy hiem: " + mucDoNguyHiem);
		System.out.println("+ Nang luong: " + nangLuong);
		System.out.println("+ So truong: " + soTruong);
	}
	
	public void doiViTri(int x, int y) {
		viTri.setX(x);
		viTri.setY(y);
	}
	
	public void giamNangLuong() {
		nangLuong--;
	}
	
	public void lamDayNangLuong() {
		nangLuong = 100;
	}
}
