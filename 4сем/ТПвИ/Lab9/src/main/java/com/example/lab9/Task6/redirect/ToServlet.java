package com.example.lab9.Task6.redirect;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet(name = "toServletRedirect", value = "/to-servlet-redirect")
public class ToServlet extends HttpServlet {


    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        // ================  TASK 6c  ================
        var path = request.getContextPath() + "/task6redirect.jsp";
        response.sendRedirect(path);
    }
}