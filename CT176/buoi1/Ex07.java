import java.util.Scanner;

public class Ex07 {
	public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String fullName, name = null;

        fullName = s.nextLine();

        for (int i = fullName.length() - 1; i >= 0; i--) {
            if (fullName.charAt(i) == ' ') {
                name = fullName.substring(i + 1, fullName.length());
                break;
            }
        }

        System.out.print(name);
    }

}