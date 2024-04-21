import java.util.Scanner;

public class ReverseString {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input string from the user
        System.out.print("Enter a string: ");
        String inputString = scanner.nextLine();

        // Reversing the string
        String reversedString = reverse(inputString);

        // Output the reversed string
        System.out.println("Reversed string: " + reversedString);

        scanner.close();
    }

    // Method to reverse a string
    public static String reverse(String str) {
        StringBuilder reversed = new StringBuilder();

        // Iterate through the string in reverse order and append characters to the StringBuilder
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed.append(str.charAt(i));
        }

        return reversed.toString();
    }
}
