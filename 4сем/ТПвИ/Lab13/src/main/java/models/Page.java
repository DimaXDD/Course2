package models;

import db.DBConnection;
import entities.users;
import entities.telegram;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

public class Page {
    public static void PageMethod(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        DBConnection dataBaseContext = new DBConnection();
        ArrayList<telegram> telegrams = null;
        int countTelegrams = 0;
        try {
            telegrams = dataBaseContext.GetAllTelegrams();
            countTelegrams = telegrams.size();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        req.setAttribute("telegrams",telegrams);
        req.setAttribute("user","user");
        req.getServletContext().getRequestDispatcher("/page.jsp").forward(req,resp);
    }
}