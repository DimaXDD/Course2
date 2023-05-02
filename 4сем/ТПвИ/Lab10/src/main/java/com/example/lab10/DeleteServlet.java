package com.example.lab10;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletContext;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/Delete")
public class DeleteServlet extends HttpServlet {
    public void init()
    {

    }

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    {
        response.setContentType("text/html");
        int id = Integer.parseInt(request.getParameter("id"));
        try {
            String result;
            result=  BDWork.DeletePlans(id);
            ServletContext context = request.getServletContext();
            RequestDispatcher dispatcher = context.getRequestDispatcher("/index.jsp");
            dispatcher.forward(request,response);
        } catch (SQLException | ServletException | IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void destroy()
    {

    }
}
