package PhanSo;
import java.util.Scanner;

public class UsePhanSo {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        //PhanSo a = new PhanSo(3,7);
        //PhanSo b = new PhanSo(4,9);
        PhanSo x = new PhanSo();
        PhanSo y = new PhanSo();

        int n;
        //PhanSo[] arr;
        PhanSo tong = new PhanSo();

        x.nhapPhanSo();
        y.nhapPhanSo();

        System.out.print("\nGia tri nghich dao cua x la: ");
        x.giaTriNghichDao().hienThi();

        System.out.print("\nx + y = ");
        x.cong(y).hienThi();

        System.out.print("\nNhap vao n: ");
        n = s.nextInt();

        PhanSo[] arr = new PhanSo[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new PhanSo();
            arr[i].nhapPhanSo();
            tong = tong.cong(arr[i]);
        }

        System.out.print("\nTong " + n + " phan so la: ");
        tong.hienThi();

        PhanSo max = new PhanSo();

        max.deepCopy(arr[0]);

        for (int i = 1; i < n; i++) {
            if (arr[i].lonHon(max)) {
                max.deepCopy(arr[i]);
            }
        }

        System.out.print("\nPhan so lon nhat la: ");
        max.hienThi();

        PhanSo tmp = new PhanSo();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i].lonHon(arr[j])) {
                    tmp.deepCopy(arr[i]);
                    arr[i].deepCopy(arr[j]);
                    arr[j].deepCopy(tmp);
                }
            }
        }

        System.out.print("\nDanh sach sau khi sap xep: ");
        for (int i = 0; i < n; i++) {
            arr[i].hienThi();
            System.out.print(" ");
        }

        s.close();
    }
}