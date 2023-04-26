package com.example.lab9.Task6.redirect;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet(name = "fromServletRedirect", value = "/from-servlet-redirect")
public class FromServlet extends HttpServlet {

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String path = request.getContextPath() + "/to-servlet-redirect";
        response.sendRedirect(path);
    }

}