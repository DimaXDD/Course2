package models;

import db.DBConnection;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;

public class AddTelegram {
    public static void AddTelegramMethod(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        req.setCharacterEncoding("UTF-8");
        DBConnection dataBaseContext = new DBConnection();
        String name = req.getParameter("name");
        String category = req.getParameter("country");
        Integer subs = Integer.parseInt(req.getParameter("subs"));
        if (name.equals("") || category.equals("") || subs.equals("")) {
            req.setAttribute("error", "Заполните все поля");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
            requestDispatcher.forward(req, resp);
        } else {
            try {
                telegram newnat = new telegram(name, category, subs);
                DBConnection dataBaseHandler = new DBConnection();
                telegram newforcheack = new telegram();
                newforcheack = dataBaseHandler.GetByname(name);
                if (newforcheack != null) {
                    RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                    requestDispatcher.forward(req, resp);
                } else {
                    try {
                        dataBaseHandler.AddTelegrams(newnat);
                    } catch (SQLException throwables) {
                        throwables.printStackTrace();
                    }
                    req.setAttribute("error", "Канал " + name + " добавлен");
                    RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                    requestDispatcher.forward(req, resp);
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}