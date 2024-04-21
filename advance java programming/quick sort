public class QuickSort {
    // Method to perform Quick Sort
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            // Partition the array
            int pivotIndex = partition(array, low, high);

            // Recursively sort the left and right subarrays
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }

    // Method to partition the array
    public static int partition(int[] array, int low, int high) {
        // Choose the pivot element
        int pivot = array[high];
        int i = low - 1;

        // Partition the array around the pivot
        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Swap array[i+1] and array[high] (pivot)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;
    }

    // Method to print the array
    public static void printArray(int[] array) {
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main method to test the implementation
    public static void main(String[] args) {
        int[] array = {10, 7, 8, 9, 1, 5};
        int n = array.length;

        System.out.println("Original array:");
        printArray(array);

        quickSort(array, 0, n - 1);

        System.out.println("Sorted array:");
        printArray(array);
    }
}
