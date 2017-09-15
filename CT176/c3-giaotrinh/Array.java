public class Array {
	public static void main(String[] args) {
		int[] arr;			//Declare an array

		arr = new int[5];	//Initialize array

		for (int i=0; i<5; i++) {
			arr[i] = i;
			System.out.print(arr[i] + " ");
		}
	}
}