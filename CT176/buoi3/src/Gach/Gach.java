package Gach;
import java.util.Scanner;

public class Gach {
	private Scanner s;
	private String maSo;
	private String mau;
	private int soLuong;
	private int chieuDai;
	private int chieuNgang;
	private long giaBan;
	
	Gach() {
		this.maSo = null;
		this.mau = null;
		this.soLuong = 0;
		this.chieuDai = 0;
		this.chieuNgang = 0;
		this.giaBan = 0;
	}
	
	public void nhapThongTin() {
		s = new Scanner(System.in);
		s.nextLine();
		System.out.print("\nNhap vao ma so: ");
		this.maSo = s.nextLine();
		s.nextLine();
		System.out.print("\nNhap vao mau sac: ");
		this.mau = s.nextLine();
		System.out.print("\nNhap vao so luong: ");
		this.soLuong = s.nextInt();
		System.out.print("\nNhap vao chieu dai: ");
		this.chieuDai = s.nextInt();
		System.out.print("\nNhap vao chieu ngang: ");
		this.chieuNgang = s.nextInt();
		System.out.print("\nNhap vao gia ban: ");
		this.giaBan = s.nextLong();
	}
	
	public void hienThiThongTin() {
		System.out.print("\n- Ma so: " + this.maSo);
		System.out.print("\n- Mau sac: " + this.mau);
		System.out.print("\n- So luong: " + this.soLuong);
		System.out.print("\n- Chieu dai: " + this.chieuDai);
		System.out.print("\n- Chieu ngang: " + this.chieuNgang);
		System.out.print("\n- Gia ban: " + this.giaBan);
	}
	
	public float giaBanLe() {
		return (float)((giaBan / soLuong) * 1.2);
	}
	
	public int dienTichToiDa() {
		return this.chieuDai * this.chieuNgang * this.soLuong;
	}
	
	public int soLuongHop(int D, int N) {
		double svd = Math.ceil((double)D / chieuDai);		//So vien theo chieu dai
		double svn = Math.ceil((double)N / chieuNgang);		//So vien theo chieu ngang
		return (int)Math.ceil((svd * svn) / soLuong);
	}
	
	public void deepCopy(Gach g) {
		this.maSo = g.maSo;
		this.mau = g.mau;
		this.soLuong = g.soLuong;
		this.chieuDai = g.chieuDai;
		this.chieuNgang = g.chieuNgang;
		this.giaBan = g.giaBan;
	}

	public long getGiaBan() {
		return giaBan;
	}

	public void setGiaBan(long giaBan) {
		this.giaBan = giaBan;
	}
}
