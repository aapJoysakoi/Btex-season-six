import java.util.Scanner;

public class InterestCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input principal amount, rate of interest, and time period from the user
        System.out.print("Enter the principal amount: ");
        double principal = scanner.nextDouble();

        System.out.print("Enter the rate of interest (in percentage): ");
        double rate = scanner.nextDouble();

        System.out.print("Enter the time period (in years): ");
        double time = scanner.nextDouble();

        // Calculate and display simple interest
        double simpleInterest = calculateSimpleInterest(principal, rate, time);
        System.out.println("Simple Interest: " + simpleInterest);

        // Calculate and display compound interest
        double compoundInterest = calculateCompoundInterest(principal, rate, time);
        System.out.println("Compound Interest: " + compoundInterest);

        scanner.close();
    }

    // Method to calculate simple interest
    public static double calculateSimpleInterest(double principal, double rate, double time) {
        return (principal * rate * time) / 100;
    }

    // Method to calculate compound interest
    public static double calculateCompoundInterest(double principal, double rate, double time) {
        double amount = principal * Math.pow(1 + (rate / 100), time);
        return amount - principal;
    }
}
