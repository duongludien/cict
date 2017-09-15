package DoanThang;
public class UseDoanThang {
	public static void main(String[] args) {
		Diem A = new Diem(2, 5);
		Diem B = new Diem(20, 35);
		
		DoanThang AB = new DoanThang(A, B);
		
		AB.tinhTien(5, 3).hienThi();
		
		DoanThang CD = new DoanThang();
		CD.nhapDoanThang();
		
		Double cd, CDx;
		
		cd = CD.tinhDoDai();
		CDx = CD.tinhGoc();
		
		System.out.print("\nDo dai CD la: " + cd + "\nGoc giua CD voi Ox la: " + CDx);
	}
}