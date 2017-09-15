import java.util.Scanner;

public class Dec2Bin {
    public static void D2B(int n) {
        if(n/2 != 0) {
        	D2B(n/2);
        }
        System.out.print(n%2);
    }
    
    public static void main(String[] args) {
        int n;
        Scanner keyboard;
        keyboard = new Scanner(System.in);
        
        System.out.print("Enter the number n: ");
        n = keyboard.nextInt();
        
        D2B(n);
    }
}