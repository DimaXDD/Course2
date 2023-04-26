package com.example.lab9.Task7;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet(name = "Servlet2", value = "/servlet2")
public class Servlet2 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // получаем переданный атрибут из servlet1 (число 5)
        var num1 = (int)request.getAttribute("number1");
        // увеличиваем его на 1 (получится 6)
        num1++;
        // передаем его обратно в servlet1 через атрибуты, ведь после этой строчки управление вернется к servlet1
        request.setAttribute("number2", num1);
    }

}