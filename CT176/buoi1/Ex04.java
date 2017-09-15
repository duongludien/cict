import java.util.Scanner;
import java.util.InputMismatchException;

public class Ex04 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a, b, sum;

		while(true) {
			try {
				System.out.print("Enter number a: ");
				a = s.nextInt();
				System.out.print("Enter number b: ");
				b = s.nextInt();
			}
			catch (InputMismatchException e) {
				System.out.print("Exception: Input Mismatch Exception. Please try again!\n");
				s.nextLine();
				continue;
			}
			/*finally {
				s.nextLine();
			}*/
			break;
		}
		
		sum = a + b;

		System.out.print("The sum of " + a + " and " + b + " is " + sum);
	}
}