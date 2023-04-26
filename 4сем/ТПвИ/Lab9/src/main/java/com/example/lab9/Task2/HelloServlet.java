package com.example.lab9.Task2;

import java.io.*;
import java.util.Date;
import java.util.Enumeration;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;

@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        response.setCharacterEncoding("UTF-8");     // это надо чтобы были русские буквы
        Date currentDate = new Date();              // это - текущая дата и время
        PrintWriter out = response.getWriter();

        // первое задание: на кнопку вывести дату и время и разную инфу о клиенте, протоколе, методе и тд
        out.println("<html><body>");
        out.println("<h1>Информация о клиенте, протоколе, запросе и т. д. (задание 2а)</h1>");
        out.println("<h3>Дата и время: " + currentDate + "</h3>");  // вот и вывод даты в теге h3 в разметке
        out.println("<h3>Протокол: " + request.getProtocol() + "</h3>");
        out.println("<h3>IP клиента: " + request.getRemoteAddr() + "</h3>");
        out.println("<h3>Имя клиента: " + request.getRemoteHost() + " " + request.getRemoteUser() + "</h3>");
        out.println("<h3>Метод доступа: " + request.getMethod() + "</h3>");
        out.println("<h3>URL: " + request.getRequestURL() + "</h3>");
        out.println("<h1>Заголовок запроса (задание 2б)</h1>");

        Enumeration<String> e = request.getHeaderNames();
        while (e.hasMoreElements()) {
            String name = e.nextElement();
            String value = request.getHeader(name);
            out.println(name + " = " + value);
        }

        out.println("</body></html>");
        out.close();
    }

    public void destroy() {
    }
}