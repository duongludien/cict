import java.util.Scanner;

public class Prime {
	//This is the first way to do this
	public static boolean isPrime(int n) {
		if(n < 2) {
			return false;
		}
		else {
			for(int i=2; i<=(int)(Math.sqrt(n)); i++) {
				if(n % i == 0) {
					return false;
				}
			}
		}
		return true;
	}

	public static void main(String[] args) {
		int n;
		Scanner keyboard = new Scanner(System.in);

		System.out.print("Enter the number n: ");	
		n = keyboard.nextInt();

		//This is the first way to do this
		/*
		for(int i=2; i<=n; i++) {
			if(isPrime(i)) {
				System.out.print(i + " ");
			}
		}
		*/

		//And this is the second way
		boolean[] isPrime = new boolean[n+5];

		for(int i=2; i<n; i++) {
			isPrime[i] = true;
		}

		for(int i=2; i*i<=n; i++) {
			for(int j=i; i*j<=n; j++) {
				isPrime[i*j] = false;
			}
		}

		for(int i=0; i<=n; i++) {
			if(isPrime[i]) {
				System.out.print(i + " ");
			}
		}
	}
}