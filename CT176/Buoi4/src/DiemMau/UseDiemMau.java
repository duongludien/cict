package DiemMau;

public class UseDiemMau {
	public static void main(String []args) {
		DiemMau A = new DiemMau(5, 10, "trang");
		A.hienThi();
		
		DiemMau B = new DiemMau();
		B.nhapDiem();
		B.doiDiem(10, 8);
		B.hienThi();
		B.ganMau("Vang");
		System.out.print("\nDiem B sau khi gan mau: ");
		B.hienThi();
	}
}
