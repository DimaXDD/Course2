package models;


import db.DBConnection;
import entities.users;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;


public class Welcome {
    public static void WelcomeMethod(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        DBConnection dataBaseContext = new DBConnection();
        String login = req.getParameter("login");
        String password = req.getParameter("password");
        if(login.equals("") || password.equals("")){
            req.setAttribute("result", "Заполните все поля");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("/welcome.jsp");
            requestDispatcher.forward(req, resp);
        }
        String role = null;

        users user = null;
        try {
            user = dataBaseContext.GetByUsername(login);
        } catch (SQLException throwables) {
            req.setAttribute("result", "SQL Error");
        }
        if (user != null) {
            role = user.getRole();
            if (!user.getPassword().equals(password)) {
                req.setAttribute("result", "Ошибка при вводе данных");
                RequestDispatcher requestDispatcher = req.getRequestDispatcher("/welcome.jsp");
                requestDispatcher.forward(req, resp);
            }
            else if(role.equals("user")){
                RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                requestDispatcher.forward(req, resp);
            }
            else if(role.equals("admin")){
                RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                requestDispatcher.forward(req, resp);
            }
        }
        else  { RequestDispatcher requestDispatcher = req.getRequestDispatcher("register.jsp");
            requestDispatcher.forward(req, resp);}
    }
}

