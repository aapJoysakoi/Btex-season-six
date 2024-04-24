import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        // Port number for the server
        int portNumber = 12345;

        try {
            // Create a server socket
            ServerSocket serverSocket = new ServerSocket(portNumber);
            System.out.println("Server started. Waiting for clients to connect...");

            // Accept client connections
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket);

            // Create input and output streams for communication with the client
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            // Read input from the client and send a response
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println("Client: " + inputLine);
                out.println("Server: Received '" + inputLine + "'");
            }

            // Close streams and sockets
            in.close();
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
