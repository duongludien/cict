package PhanSo;
import java.util.Scanner;

public class PhanSo {

    private int tuSo;
    private int mauSo;
	private Scanner s;

    PhanSo() {
        this.tuSo = 0;
        this.mauSo = 1;
    }

    PhanSo(int tu, int mau) {
        this.tuSo = tu;
        this.mauSo = mau;
    }

    public void deepCopy(PhanSo a) {
        this.tuSo = a.tuSo;
        this.mauSo = a.mauSo;
    }

    public void nhapPhanSo() {
        s = new Scanner(System.in);

        System.out.print("\nNhap vao tu so: ");
        this.tuSo = s.nextInt();

        do {
            System.out.print("\nNhap vao mau so: ");
            this.mauSo = s.nextInt();

            if (this.mauSo == 0) {
                System.out.print("\nMau so khong hop le. Xin kiem tra lai!");
            }
        } while (this.mauSo == 0);

        //s.close();
    }

    public void hienThi() {
        if (this.tuSo == 0) {
            System.out.print("0");
            return;
        }
        if (mauSo == 1) {
            System.out.print(this.tuSo);
            return;
        }
        System.out.print(this.tuSo + "/" + this.mauSo);
    }

    public void nghichDao() {
        int tmp;

        tmp = this.tuSo;
        this.tuSo = this.mauSo;
        this.mauSo = tmp;
    }

    public PhanSo giaTriNghichDao() {
        PhanSo nghichDao = new PhanSo();

        nghichDao.tuSo = this.mauSo;
        nghichDao.mauSo = this.tuSo;

        return nghichDao;
    }

    public double giaTriThuc() {
        return this.tuSo / this.mauSo;
    }

    public boolean lonHon(PhanSo a) {
        return this.giaTriThuc() > a.giaTriThuc();
    }

    public int GCD(int t, int m) {
        if (t < 0) {
            t /= (-1);
        }
        if (m < 0) {
            m /= (-1);
        }
        while (t != m) {
            if (t > m) {
                t -= m;
            } else {
                m -= t;
            }
        }

        return t;
    }

    public void rutGon() {
        int GCD;

        GCD = GCD(this.tuSo, this.mauSo);
        this.tuSo = this.tuSo / GCD;
        this.mauSo = this.mauSo / GCD;
    }

    public PhanSo cong(PhanSo a) {
        PhanSo tong = new PhanSo();

        tong.tuSo = this.tuSo * a.mauSo + this.mauSo * a.tuSo;
        tong.mauSo = this.mauSo * a.mauSo;

        tong.rutGon();

        return tong;
    }

    public PhanSo cong(int n) {
        PhanSo tong = new PhanSo();

        tong.tuSo = this.mauSo * n + this.tuSo;
        tong.mauSo = this.mauSo;

        tong.rutGon();

        return tong;
    }

    public PhanSo tru(PhanSo a) {
        PhanSo hieu = new PhanSo();

        hieu.tuSo = this.tuSo * a.mauSo - this.mauSo * a.tuSo;
        hieu.mauSo = this.mauSo * a.mauSo;

        hieu.rutGon();

        return hieu;
    }

    public PhanSo tru(int n) {
        PhanSo hieu = new PhanSo();

        n *= (-1);

        hieu.tuSo = this.mauSo * n + this.tuSo;
        hieu.mauSo = this.mauSo;

        hieu.rutGon();

        return hieu;
    }

    public PhanSo nhan(PhanSo a) {
        PhanSo tich = new PhanSo();

        tich.tuSo = this.tuSo * a.tuSo;
        tich.mauSo = this.mauSo * a.mauSo;

        tich.rutGon();

        return tich;
    }

    public PhanSo nhan(int n) {
        PhanSo tich = new PhanSo();

        tich.tuSo = this.tuSo * n;
        tich.mauSo = this.mauSo;

        tich.rutGon();

        return tich;
    }

    public PhanSo chia(PhanSo a) {
        PhanSo thuong = new PhanSo();

        thuong = this.nhan(a.giaTriNghichDao());

        return thuong;
    }

    public PhanSo chia(int n) {
        PhanSo thuong = new PhanSo();

        thuong.tuSo = this.tuSo;
        thuong.mauSo = this.mauSo * n;

        thuong.rutGon();

        return thuong;
    }

}