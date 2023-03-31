package Task1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;

public class Connect {
    public void getLocalHost() {
        try {
            // получаем IP локального хоста
            var localHostIP = InetAddress.getLocalHost();
            System.out.println("Localhost IP: " + localHostIP.getLocalHost().getHostAddress());
            //System.out.println("Local IP: " + InetAddress.getLocalHost());
        } catch (UnknownHostException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void getByName(String website) {
        try {
            // получаем IP сайта по имени
            var currentWebsiteIP = InetAddress.getByName(website);
            System.out.println("Website IP by name: " + currentWebsiteIP.getHostAddress());
        } catch (UnknownHostException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void getByAddress(String name, byte[] ip) {
        try {
            // доступен ли сайт по IP
            var pageIP = InetAddress.getByAddress(name, ip);
            System.out.println("IP доступен? " + pageIP.isReachable(300));
        }
        catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void readHTML(String urlName) {
        try {       // еще можно весь штмл считать через команды

            // в url закидываем адрес сайта
            var url = new URL(urlName);
            // через буферизированный поток все читаем построчно
            try (var reader = new BufferedReader(new InputStreamReader(url.openStream()))) {
                String HTMLLine;
                while ((HTMLLine = reader.readLine()) != null) {
                    System.out.println(HTMLLine);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        catch(MalformedURLException ex) {
            ex.printStackTrace();
        }
    }

    // можно еще всякую разную инфу о соединении получить
    public void getInfo(String urlName) {
        var timeout = 10_000;
        try {
            var url = new URL(urlName);
            // создали объект коннекшена к какому то сайту из параметров функции
            final var connection = url.openConnection();

            System.out.println("Content type:     " + connection.getContentType() +     // тип контента (штмл страница)
                    "\nClass:            " + connection.getClass() +           // класс
                    "\nContent length:   " + connection.getContentLength());   // длина контента
        } catch(IOException ex) {
            ex.printStackTrace();
        }
    }

}
