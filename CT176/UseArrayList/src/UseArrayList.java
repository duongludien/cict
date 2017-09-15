import java.util.*;

public class UseArrayList {
	private static Scanner s;
	
	public static void main(String []args) {
		s = new Scanner(System.in);
		int a;
		String t;
		
		System.out.print("\nNhap tuoi: ");
		a = s.nextInt();
		
		System.out.print("\nNhap ten: ");
		t = s.nextLine();
		
		System.out.println(t + ": " + a);
	}
}
