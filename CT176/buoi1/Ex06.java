import java.util.Scanner;

public class Ex06 {
	public static boolean isPrime(int n) {
		if(n < 2) {
			return false;
		}
		else {
			for(int i = 2; i <= (int)(Math.sqrt(n)); i++) {
				if(n % i == 0) {
					return false;
				}
			}
		}
		return true;
	}

	public static void dec2Bin(int n) {
		if(n / 2 != 0) {
			dec2Bin(n / 2);
		}
		System.out.print(n % 2);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n;

		System.out.print("Enter the number n: ");
		n = s.nextInt();

		if(isPrime(n)) {
			System.out.print(n + " is a prime number");
		}
		else {
			System.out.print(n + " is not a prime number");
		}
		System.out.print("\nThe binary value of " + n + " is ");
		dec2Bin(n);
	}
}