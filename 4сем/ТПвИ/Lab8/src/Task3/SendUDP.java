package Task3;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

// udp
public class SendUDP {
    // точно так же юзаем сокеты для подключения, но щас юзаем класс DatagramSocket
    private DatagramSocket socket;


    public SendUDP(int port) throws SocketException {
        // один параметр перегруженной ф-ии,значит коннектимся к определенному порту на локальной машине
        socket = new DatagramSocket(port);
    }


    public void sendMessages(String messages, int port) throws IOException {
        // ф-ия для отправки сообщения,тут все просто
        DatagramPacket message = new DatagramPacket(messages.getBytes(), messages.getBytes().length, InetAddress.getLocalHost(), port);
        socket.send(message);
    }


    public static void main(String[] args) throws IOException {
        SendUDP udp = new SendUDP(1234);
        // попытаемся отправить это сообщение. будет очень жаль если дейтаграмма не дойдет
        udp.sendMessages("всем привет я люблю джаву", 4321);
    }
}

