package models;

import db.DBConnection;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;

public class DelTelegram {
    public static void DelTelegramMethod(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        req.setCharacterEncoding("UTF-8");
        DBConnection dataBaseContext = new DBConnection();
        String name = req.getParameter("namedelet");
        if (name.equals("")) {
            req.setAttribute("error", "Заполните поле");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
            requestDispatcher.forward(req, resp);
            return;
        } else {
            telegram Telegram = null;
            try {
                Telegram = dataBaseContext.GetByname(name);
            } catch (SQLException e) {
                e.printStackTrace();
            }
            if (Telegram == null)
            {
                req.setAttribute("error", " Такого канала не существует");
                RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                requestDispatcher.forward(req, resp);
            }
            else{
                try {
                    req.setAttribute("error", "Канал " + name + " удален");
                    dataBaseContext.Remove(name);
                    RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
                    requestDispatcher.forward(req, resp);
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
            req.setAttribute("error", "Нация " + name + " удалена");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("controller?command=page");
            requestDispatcher.forward(req, resp);
        }
    }
