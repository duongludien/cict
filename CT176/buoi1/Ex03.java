import java.lang.NumberFormatException;

public class Ex03 {
	public static void main(String[] args) {
		Double tmp, sum = 0.0, max = 0.0;

		for(int i=0; i<args.length; i++) {
			try {
				tmp = Double.parseDouble(args[i]);
			}
			catch (NumberFormatException e) {
				continue;
			}

			sum += tmp;

			if(i == 0) {
				max = tmp;
			}
			else {
				if(max < tmp) {
					max = tmp;
				}
			}
		}

		System.out.print("The sum is " + sum);
		System.out.print("\nThe max number is " + max);
	}
}