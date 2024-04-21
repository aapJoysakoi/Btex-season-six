import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListToArrayConverter {
    public static void main(String[] args) {
        // Create a list
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        // Convert list to array
        Integer[] array = list.toArray(new Integer[0]);

        // Print the array
        System.out.println("Array from List:");
        System.out.println(Arrays.toString(array));

        // Create an array
        Integer[] newArray = {6, 7, 8, 9, 10};

        // Convert array to list
        List<Integer> newList = Arrays.asList(newArray);

        // Print the list
        System.out.println("\nList from Array:");
        for (int num : newList) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
