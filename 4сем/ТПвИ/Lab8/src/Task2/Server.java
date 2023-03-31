package Task2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {
    // здесь будут храниться все сокеты (то есть все компы, которые подключаются к серверу)
    public static ArrayList<SocketThread> socketThreads = new ArrayList<>();

    public static void main(String[] args) {
        // с помощью класса серверсокет можно установить соединение на стороне сервака
        try (ServerSocket server = new ServerSocket(7068)) {
            System.out.println("Server started");
            while (true) {
                // accept значит что сервак приостанавливает работу и ожидает запроса от клиента; и возвращает его сокет
                Socket socket = server.accept();
                // выводим этот сокет, а именно - имя компа (getHostName)
                System.out.println(socket.getInetAddress().getHostName() + " connected");
                SocketThread socketThread = new SocketThread(socket);
                socketThreads.add(socketThread);
                socketThread.start();
            }
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}
