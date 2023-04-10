package Task3;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class GetUDP {
    private final DatagramSocket socket;
    // протокол передает байты, значит все будет писать в массив байт определенной длины
    private final byte[] messageUDP = new byte[21];


    public GetUDP(int port) throws SocketException {
        socket = new DatagramSocket(port);
    }


    // через receive получаем сообщения
    public void getMessages() throws IOException {
        socket.receive(new DatagramPacket(messageUDP, 21));
        // здесь кстати никакой коннекшен не устанавливается мы тупа молимся что наше сообщение кто то услышит
        // а если нас никто не будет слушать то никто и не услышит что логично
        var message = new String(messageUDP);
        System.out.println(message);
    }


    public static void main(String[] args) throws IOException {
        GetUDP getUDP = new GetUDP(4321);
        while (true)
            // постоянно прослушиваем порт и принимаем сообщения
            getUDP.getMessages();
    }
}
