package com.example.lab9.Task8;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;



public class ParamServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        String message = getServletConfig().getInitParameter("message");
        System.out.println(message);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String message = getServletConfig().getInitParameter("message");
        response.setContentType("text/html");
        PrintWriter writer = response.getWriter();
        try {
            writer.println("<h2>" + message + "</h2>");
        } finally {
            writer.close();
        }

//        request.setAttribute("parameter", message);
//        request.getRequestDispatcher("/task8.jsp").include(request, response);

    }

}