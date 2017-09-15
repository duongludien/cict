package Date;
import java.util.Scanner;

public class Date {

    private int ngay;
    private int thang;
    private int nam;
	private Scanner s;

    Date() {
        this.ngay = 0;
        this.thang = 0;
        this.nam = 0;
    }

    Date(int d, int m, int y) {
        this.ngay = d;
        this.thang = m;
        this.nam = y;
    }

    public void deepCopy(Date d) {
        this.ngay = d.ngay;
        this.thang = d.thang;
        this.nam = d.nam;
    }

    public void hienThi() {
        System.out.print(this.ngay + "/" + this.thang + "/" + this.nam);
    }

    public boolean namNhuan(int n) {
        return ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0));
    }

    public boolean hopLe() {
        if (this.thang < 1 || this.thang > 12) {
            return false;
        }
        switch (this.thang) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return (this.ngay >= 1 && this.ngay <= 31);
            case 2:
                if (namNhuan(this.nam)) {
                    return (this.ngay >= 1 && this.ngay <= 29);
                } else {
                    return (this.ngay >= 1 && this.ngay <= 28);
                }
            case 4:
            case 6:
            case 9:
            case 11:
                return (this.ngay >= 1 && this.ngay <= 30);
        }
        return false;
    }

    public void nhapNgay() {
        s = new Scanner(System.in);
        do {
            System.out.print("\nNhap ngay: ");
            this.ngay = s.nextInt();
            System.out.print("\nNhap thang: ");
            this.thang = s.nextInt();
            System.out.print("\nNhap nam: ");
            this.nam = s.nextInt();
            if (!this.hopLe()) {
                System.out.print("\nNgay thang nam da nhap khong hop le. Xin kiem tra lai!");
            }
        } while (!this.hopLe());

        //s.close();
    }

    public Date ngayHomSau() {
        Date tmp = new Date();

        switch (this.thang) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (this.ngay >= 1 && this.ngay <= 30) {
                    tmp.ngay = this.ngay + 1;
                    tmp.thang = this.thang;
                    tmp.nam = this.nam;
                } else {
                    tmp.ngay = 1;
                    if (this.thang == 12) {
                        tmp.thang = 1;
                        tmp.nam = this.nam + 1;
                    } else {
                        tmp.thang = this.thang + 1;
                        tmp.nam = this.nam;
                    }
                }
                break;
            case 2:
                if (namNhuan(this.nam)) {
                    if (this.ngay >= 1 && this.ngay <= 28) {
                        tmp.ngay = this.ngay + 1;
                        tmp.thang = this.thang;
                        tmp.nam = this.nam;
                    } else {
                        tmp.ngay = 1;
                        tmp.thang = this.thang + 1;
                        tmp.nam = this.nam;
                    }
                } else {
                    if (this.ngay >= 1 && this.ngay <= 27) {
                        tmp.ngay = this.ngay + 1;
                        tmp.thang = this.thang;
                        tmp.nam = this.nam;
                    } else {
                        tmp.ngay = 1;
                        tmp.thang = this.thang + 1;
                        tmp.nam = this.nam;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (this.ngay >= 1 && this.ngay <= 29) {
                    tmp.ngay = this.ngay + 1;
                    tmp.thang = this.thang;
                    tmp.nam = this.nam;
                } else {
                    tmp.ngay = 1;
                    tmp.thang = this.thang + 1;
                    tmp.nam = this.nam;
                }
                break;
        }

        return tmp;
    }

    public Date congNgay(int n) {
        Date tmp = new Date();
        tmp.deepCopy(this);

        for (int i = 0; i < n; i++) {
            tmp = tmp.ngayHomSau();
        }

        return tmp;
    }

}
