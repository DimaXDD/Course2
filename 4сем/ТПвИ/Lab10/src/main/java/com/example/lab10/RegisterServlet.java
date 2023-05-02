package com.example.lab10;


import jakarta.servlet.Servlet;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

@WebServlet("/RegisterServ")
public class RegisterServlet extends HttpServlet {
    public void init()
    {

    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String login = request.getParameter("login");
        String password = request.getParameter("Password");
        try {
            String mes = BDWork.getUsers(login,password);
            if (mes == null ) {
                out.println("<html><body><h1>Good Register</h1></body></html>");
                BDWork.Register(login, password);
            }
            else{
                out.println("<html><body><h1>Error</h1></body></html>");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void destroy()
    {

    }
}
