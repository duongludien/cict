package Diem;
public class UseDiem {

    public static void main(String[] args) {
        Diem O = new Diem();
        Diem A = new Diem(3, 4);
        Diem B = new Diem();
        Diem C;

        System.out.print("A");
        A.hienThi();

        B.nhapDiem();
        System.out.print("\nB");
        B.hienThi();

        C = new Diem(-B.giaTriX(), -B.giaTriY());
        System.out.print("\nC");
        C.hienThi();

        System.out.print("\nd(B,O) = " + B.khoangCach(O));

        System.out.print("\nd(A,O) = " + A.khoangCach(O));
    }
}
