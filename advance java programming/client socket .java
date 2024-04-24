import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        // Server's IP address and port number
        String serverAddress = "localhost";
        int portNumber = 12345;

        try {
            // Create a socket to connect to the server
            Socket socket = new Socket(serverAddress, portNumber);
            System.out.println("Connected to server: " + serverAddress + ":" + portNumber);

            // Create input and output streams for communication with the server
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            // Send a message to the server
            out.println("Hello, server!");

            // Read the server's response
            String response;
            while ((response = in.readLine()) != null) {
                System.out.println("Server: " + response);
            }

            // Close streams and socket
            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
