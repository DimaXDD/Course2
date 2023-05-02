package com.example.lab10;

import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;


import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;

@WebServlet("/HelloServlet")
public class HelloServlet extends HttpServlet
{
    static  Integer count = 0;
    public HelloServlet()
    {
        super();
    }
    @Override
    public void init(ServletConfig config) throws ServletException {
        super.init(config);
    }

    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        super.service(req,res);
        System.out.println("service");
    }
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        count ++;

        response.setContentType("text/html");
        String login = request.getParameter("login");
        String password = request.getParameter("password");



        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        String type;
        try {
            type = BDWork.getUsers(login,password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        if (type == null)
        {
            FilterNotAutorize notAutorize = new FilterNotAutorize();
            notAutorize.doFilter(request,response,null);
        }
        else
        {
            ServletContext context = request.getServletContext();
            RequestDispatcher dispatcher = context.getRequestDispatcher("/EnterWidow.jsp");
            request.setAttribute("login",login);
            request.setAttribute("password",password);
            try {
                ArrayList<ForestPlans> list = BDWork.GetPlans();
                request.setAttribute("planes",list);
                ForestPlans plans = list.get(0);
                dispatcher.forward(request,response);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException{
    }

    public void destroy()
    {
        super.destroy();
    }
}
