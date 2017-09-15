import java.util.Scanner;

public class SoHoanThien {
	public static boolean isSHT(int n) {
		int total = 0;

		for(int i=1; i<=n; i++) {
			if(n % i == 0) {
				total += i;
			}
		}

		return (total <= n);
	}

	public static void main(String[] args) {
		int n;
		Scanner keyboard = new Scanner(System.in);

		System.out.print("Enter the number n: ");
		n = keyboard.nextInt();

		for(int i=0; i<=n; i++) {
			if(isSHT(i)) {
				System.out.print(i + " ");
			}
		}
	}
}