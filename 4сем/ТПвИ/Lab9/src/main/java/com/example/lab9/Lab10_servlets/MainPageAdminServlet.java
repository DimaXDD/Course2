package com.example.lab9.Lab10_servlets;

import com.example.lab9.Task3.classes.Database;
import com.example.lab9.Task3.classes.User;
import com.example.lab9.Task3.classes.UserDAO;
import jakarta.servlet.ServletException;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.Logger;

import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "MainPageAdminServlet", value = "/main-admin-servlet")
public class MainPageAdminServlet extends HttpServlet {
    private static Logger logger = Logger.getLogger(MainPageAdminServlet.class);
    private UserDAO userDAO;


    public void init() throws ServletException {
        String driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String url = "jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
        String username = "sa";
        String password = "1111";
        Database database = new Database(driver, url, username, password);
        this.userDAO = new UserDAO(database);
        BasicConfigurator.configure();
    }



    // Метод doPost вызывается при нажатии на кнопку "Добавить" на главной странице
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<User> users = new ArrayList<>();

        String login = request.getParameter("login");
        String password = request.getParameter("password");
        String role = request.getParameter("role");

        logger.info("Adding new user: " + login + ", " + password + ", " + role);

        try {
            users = userDAO.list();
            logger.info("usersList size = " + users.size());
        } catch (SQLException e) {
            logger.error("Can't get users from Database");
            throw new ServletException("Cannot retrieve areas", e);
        }



        try {
            userDAO.addUserByAdmin(login, password, role);
            request.setAttribute("ErrorMessage", "Вы успешно зарегистрировались! Войдите в систему");
            logger.info("User successfully added!");
        } catch (SQLException e) {
            logger.error("Can't add user to DB");
            e.printStackTrace();
            request.setAttribute("ErrorMessage", "Логин уже занят");
        }


        HttpSession session = request.getSession();
        session.setAttribute("usersList", users);
        System.out.println(users.size());
        request.getRequestDispatcher("/mainPageAdmin_10.jsp").forward(request, response);
    }







    // Метод doGet вызывается при нажатии на кнопку "Удалить" на главной странице
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<User> users = new ArrayList<>();
        String login = request.getParameter("login");

        logger.info("Try to delete user " + login);

        try {
            users = userDAO.list();
        } catch (SQLException e) {
            logger.error("Can't get users from Database");
            throw new ServletException("Cannot retrieve areas", e);
        }

        try {
            userDAO.deleteUser(login);
            request.setAttribute("ErrorMessage", "Вы успешно зарегистрировались! Войдите в систему");
        } catch (SQLException e) {
            logger.error("Can't delete user from DB");
            e.printStackTrace();
            request.setAttribute("ErrorMessage", "Логин уже занят");
        }

        request.setAttribute("usersList", users);
        System.out.println(users.size());
        request.getRequestDispatcher("/mainPageAdmin_10.jsp").forward(request, response);
    }
}
