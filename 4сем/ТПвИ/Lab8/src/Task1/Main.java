package Task1;

public class Main {
    public static void main(String[] args) {
        var connect = new Connect();
        connect.getLocalHost();
        connect.getByName("www.google.com");
        byte[] ip = {(byte)127, (byte)0, (byte)0, (byte)1};
        connect.getByAddress("Loopback", ip);
        System.out.println("");
        connect.readHTML("https://www.google.com/");
        connect.getInfo("https://www.google.com/");
    }
}
