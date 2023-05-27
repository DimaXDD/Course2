package models;

import db.DBConnection;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;

public class UpdTelegram {
    public static void UpdateTelegramMethod(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        req.setCharacterEncoding("UTF-8");
        String name = req.getParameter("name");
        String subs = req.getParameter("number");
        if (name.equals("") || subs.equals("")) {
            req.setAttribute("error", "Заполните все поля");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
            requestDispatcher.forward(req, resp);
        } else {
            DBConnection dataBaseHandler = new DBConnection();
            telegram Telegram = null;
            try {
                Telegram = dataBaseHandler.GetByname(name);
            } catch (SQLException e) {
                e.printStackTrace();
            }
            if (Telegram == null)
            {
                req.setAttribute("error", " Такого народа не существует");
                RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                requestDispatcher.forward(req, resp);
            }
            else{
                try {
                    dataBaseHandler.Update(name, subs);
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
        req.setAttribute("error", " Обновлено");
        req.getRequestDispatcher("controller?command=page").forward(req, resp);
    }
}

