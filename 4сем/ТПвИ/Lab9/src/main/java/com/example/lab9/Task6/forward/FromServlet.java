package com.example.lab9.Task6.forward;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet(name = "fromServletForward", value = "/from-servlet-forward")
public class FromServlet extends HttpServlet {

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String mesFrom = "Hello! I am from-servlet.";
        request.setAttribute("mesFrom", mesFrom);
        request.getRequestDispatcher("/to-servlet-forward").forward(request, response);
    }

}