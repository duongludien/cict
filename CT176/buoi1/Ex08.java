import java.util.Scanner;
import java.util.Arrays;

public class Ex08 {
	public static int count(int x, int[] arr, int n) {
		int count_variable = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i] == x) {
				count_variable++;
			}
		}
		return count_variable;
	}

	public static void main(String[] args) {
		//Declaration
		Scanner s = new Scanner(System.in);
		int[] arr;
		int n, x = 2;

		//Initialize an array has n items
		System.out.print("Enter the number of items: ");
		n = s.nextInt();
		arr = new int[n];

		//Enter array
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the item number " + (i+1) + ": ");
			arr[i] = s.nextInt();
		}

		//Count
		System.out.print("There are " + count(x, arr, n) + " item(s) of array equal(s) to " + x);

		//Sort
		Arrays.sort(arr);
		System.out.print("\nThe array after sorting is: ");
		for(int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
        }
	}
}