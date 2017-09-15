package DiemMau;

import java.util.Scanner;

public class DiemMau extends Diem {
	private String mau;
	private Scanner s;
	
	DiemMau() {
		super();
		mau = null;
	}
	
	DiemMau(int x, int y, String mau) {
		super(x, y);
		this.mau = mau;
	}
	
	public void ganMau(String mau) {
		this.mau = mau;
	}
	
	public void nhapDiem() {
		s = new Scanner(System.in);
		
		super.nhapDiem();
		
		//s.nextLine();
		System.out.print("\nNhap vao mau sac: ");
		mau = s.nextLine();
	}
	
	@Override
	public void hienThi() {
		super.hienThi();
		System.out.print(" " + mau);
	}
	
	
}
