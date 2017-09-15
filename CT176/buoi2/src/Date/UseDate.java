package Date;
public class UseDate {

    public static void main(String[] args) {
        Date d1 = new Date();
        Date d2 = new Date();

        d1.nhapNgay();
        d1.hienThi();

        System.out.print("\nNgay hom sau la: ");
        d1.ngayHomSau().hienThi();

        d2.nhapNgay();
        d2.hienThi();
        System.out.print("Cong them 20 ngay la: ");
        d2.congNgay(20).hienThi();
    }
}