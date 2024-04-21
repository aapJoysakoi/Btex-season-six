import java.util.Scanner;

public class RectangleAreaCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input length and width of the rectangle from the user
        System.out.print("Enter length of the rectangle: ");
        double length = scanner.nextDouble();

        System.out.print("Enter width of the rectangle: ");
        double width = scanner.nextDouble();

        // Calculate area of the rectangle
        double area = calculateArea(length, width);

        // Output the result
        System.out.println("Area of the rectangle: " + area);

        scanner.close();
    }

    // Method to calculate area of the rectangle
    public static double calculateArea(double length, double width) {
        return length * width;
    }
}
