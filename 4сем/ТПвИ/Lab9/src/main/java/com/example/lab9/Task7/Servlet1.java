package com.example.lab9.Task7;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Servlet1", value = "/servlet1")
public class Servlet1 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        var num1 = 5;
        request.setAttribute("number1", num1);
        // передаем управление servlet2. после того как он отработает управление вернется в servlet1 и запустится код ниже
        request.getRequestDispatcher("/servlet2").include(request, response);

        // получаем атрибут number2, который обработался в servlet2 (увеличился на 1)
        var num2 = request.getAttribute("number2");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h2>" + num2 + "</h2>");   // и получилось 6 вау
        out.println("</body></html>");
        out.close();
    }
}