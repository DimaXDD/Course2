package com.example.lab10;

import jakarta.servlet.DispatcherType;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletContext;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
@WebServlet("/InsertServlet")
public class InsertServlet extends HttpServlet {
    public void init()
    {

    }
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");
        int id = Integer.parseInt(request.getParameter("id"));
        String type = request.getParameter("type");
        String name = request.getParameter("name");
        ServletContext context = request.getServletContext();
        try {
            BDWork.InsertPlans(id,type,name);
        } catch (SQLException e) {
            RequestDispatcher dispatcher = context.getRequestDispatcher("/Error");
            dispatcher.forward(request,response);
        }
        RequestDispatcher dispatcher = context.getRequestDispatcher("/index.jsp");
        dispatcher.forward(request,response);


    }

    public void destroy()
    {

    }
}

