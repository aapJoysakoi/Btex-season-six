import java.util.Scanner;

public class FactorialCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input number from the user
        System.out.print("Enter a number to find its factorial: ");
        int number = scanner.nextInt();

        // Calculate factorial
        long factorial = calculateFactorial(number);

        // Output the result
        System.out.println("Factorial of " + number + " is: " + factorial);

        scanner.close();
    }

    // Method to calculate factorial
    public static long calculateFactorial(int number) {
        // Factorial of 0 and 1 is 1
        if (number == 0 || number == 1) {
            return 1;
        }

        // Initialize factorial as 1
        long factorial = 1;

        // Calculate factorial
        for (int i = 2; i <= number; i++) {
            factorial *= i;
        }

        return factorial;
    }
}
