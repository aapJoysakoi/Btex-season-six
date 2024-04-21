import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class BinarySearchTree {
    Node root;

    BinarySearchTree() {
        root = null;
    }

    // Method to insert a new node with given key
    Node insert(Node root, int key) {
        // If the tree is empty, return a new node
        if (root == null) {
            root = new Node(key);
            return root;
        }

        // Otherwise, recur down the tree
        if (key < root.data)
            root.left = insert(root.left, key);
        else if (key > root.data)
            root.right = insert(root.right, key);

        // Return the unchanged node pointer
        return root;
    }

    // Method to perform inorder traversal of the tree
    void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.data + " ");
            inorderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree tree = new BinarySearchTree();

        System.out.print("Enter the number of elements to insert: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements:");

        // Inserting elements into the tree
        for (int i = 0; i < n; i++) {
            int element = scanner.nextInt();
            tree.root = tree.insert(tree.root, element);
        }

        System.out.println("Inorder traversal of the binary search tree:");
        tree.inorderTraversal(tree.root);

        scanner.close();
    }
}
