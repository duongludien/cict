import java.util.Scanner;

public class Ex05 {
	//Solve Linear Equation
	public static void solveLinearEquation(double a, double b) {
		double x;

		if(a == 0) {
			if(b == 0) {
				System.out.print("There are numberless solutions");
			}
			else {
				System.out.print("There are no solutions");
			}
		}
		else {
			x = -b / a;
			System.out.print("The solution is " + x);
		}
	}

	//Solve Quadratic
	public static void solveQuadratic(double a, double b, double c) {
		double delta, x1, x2;

		delta = b * b - 4 * a * c;

		if(delta < 0) {
			System.out.print("There are no solutions");
		}
		else if(delta == 0) {
			x1 = -b / (2 * a);
			System.out.print("The solution is " + x1);
		}
		else {
			x1 = (-b + Math.sqrt(delta)) / (2 * a);
			x2 = (-b - Math.sqrt(delta)) / (2 * a);
			System.out.print("There are 2 solutions: x1 = " + x1 + "\tx2 = " + x2);
		}
	}

	//Main method
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		double a, b, c;

		System.out.print("Enter number a: ");
		a = s.nextDouble();
		System.out.print("Enter number b: ");
		b = s.nextDouble();
		System.out.print("Enter number c: ");
		c = s.nextDouble();

		if(a == 0) {
			solveLinearEquation(b, c);
		}
		else {
			solveQuadratic(a, b, c);
		}
	}
}