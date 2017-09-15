package SinhVien;

import java.util.Scanner;

public class Date {
    private int ngay;
    private int thang;
    private int nam;
    private Scanner s;
    
    Date() {
        ngay = 1;
        thang = 1;
        nam = 1900;
    }
    
    Date(int d, int m, int y) {
        ngay = d;
        thang = m;
        nam = y;
    }
    
    /* Cach khac
    Date(int ngay, int thang, int nam) {
        this.ngay = ngay;
        this.thang = thang;
        this.nam = nam;
    }
    */
    
    public int getNgay() {
        return ngay;
    }

    public int getThang() {
        return thang;
    }

    public int getNam() {
        return nam;
    }

    public void hienThi() {
        System.out.print(ngay + "/" + thang + "/" + nam);
    }
    
    public boolean hopLe() {
        int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
            ngayTrongThang[2] = 29;
        
        if(thang < 1 || thang > 12)
            return false;
        return (ngay >= 1 && ngay <= ngayTrongThang[thang]);
    }
    
    public void nhapNgay() {
        s = new Scanner(System.in);
        do {
            System.out.print("Nhap ngay: ");
            ngay = s.nextInt();
            System.out.print("Nhap vao thang: ");
            thang = s.nextInt();
            System.out.print("Nhap vao nam: ");
            nam = s.nextInt();
            if(!this.hopLe())
                System.out.println("Ngay thang nam vua nhap khong hop le. Vui long kiem tra lai!");
        }
        while(!this.hopLe());
    }
    
    public Date ngayHomSau() {
        Date tomorrow = new Date();
        int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
            ngayTrongThang[2] = 29;
        
        if(ngay >= 1 && ngay < ngayTrongThang[thang]) {
            tomorrow.ngay = ngay + 1;
            tomorrow.thang = thang;
            tomorrow.nam = nam;
        }
        else {
            tomorrow.ngay = 1;
            tomorrow.thang = thang + 1;
            tomorrow.nam = nam;
        }
        
        if(tomorrow.thang == 13) {
            tomorrow.thang = 1;
            tomorrow.nam++;
        }
        
        return tomorrow;
    }
    
    public Date congNgay(int n) {
        Date d = new Date(ngay, thang, nam);
        for(int i=0; i<n; i++)
            d = d.ngayHomSau();
        return d;
    }
}

