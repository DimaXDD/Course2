package com.example.lab9.Lab10_servlets;

import com.example.lab9.Task3.classes.Database;
import com.example.lab9.Task3.classes.User;
import com.example.lab9.Task3.classes.UserDAO;
import com.microsoft.sqlserver.jdbc.StringUtils;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.*;

import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.Logger;


@WebServlet(name = "SignInServlet", value = "/sign-in-servlet")
public class SignInServlet extends HttpServlet {
    private UserDAO userDAO;
    public List<User> areas = new ArrayList<>();
    private static Logger logger = Logger.getLogger(SignInServlet.class);


    public void init() throws ServletException {
        String driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String url = "jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
        String username = "sa";
        String password = "1111";
        Database database = new Database(driver, url, username, password);
        this.userDAO = new UserDAO(database);
        BasicConfigurator.configure();
    }



    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        Date currentDate = new Date();
        boolean isFoundUser = false;
        boolean isWrongPassword = false;
        boolean isNotFoundUser = false;
        String loginCookie = "testLogin";
        String roleCookie = "testRole";


        try { areas = userDAO.list(); }
        catch (SQLException e) {
            logger.error("Can't get users from Database");
            throw new ServletException("Cannot retrieve areas", e);
        }


        String login = request.getParameter("login");
        String password = request.getParameter("password");
        HttpSession session = request.getSession();
        session.setAttribute("userSignedIn", null);
        logger.debug("login = " + login + ", pass = " + password);

        for (User user : areas) {
            if (user.UserName.equals(login) && !user.UserPassword.equals(password)) {
                isWrongPassword = true;
                request.setAttribute("ErrorMessage", "Неверный пароль");
                session.setAttribute("userSignedIn", null);
                break;
            }
            else if (user.UserName.equals(login) && user.UserPassword.equals(password)) {
                request.setAttribute("name", user.getUserName());
                request.setAttribute("role", user.getUserRole());
                request.setAttribute("date", currentDate);
                request.setAttribute("ErrorMessage", "");
                request.setAttribute("usersList", areas);
                session.setAttribute("usersList", areas);
                session.setAttribute("userSignedIn", user.getUserName());
                isFoundUser = true;
                loginCookie = user.getUserName();
                roleCookie = user.getUserRole();
                break;
            }
            else {
                isNotFoundUser = true;
                session.setAttribute("userSignedIn", null);
                request.setAttribute("ErrorMessage", "Пользователя не существует");
            }
        }


        if (StringUtils.isEmpty(login) || StringUtils.isEmpty(password)) {
            request.setAttribute("ErrorMessage", "Заполните все поля");
            logger.warn("Empty inputs in sign in form");
            request.getRequestDispatcher("/signInForm_10.jsp").forward(request, response);
        }


        Cookie cookieLogin = new Cookie("login", loginCookie);
        Cookie cookieRole = new Cookie("role", roleCookie);
        response.addCookie(cookieRole);
        response.addCookie(cookieLogin);

        logger.info("Forwarding from SignInServlet...");

        if (isFoundUser)
        {
            logger.info("to mainPageAdmin, user is found");
            request.getRequestDispatcher("/mainPageAdmin_10.jsp").forward(request, response);
        }
        else if (isWrongPassword)
        {
            logger.info("to signInForm, wrong password");
            request.getRequestDispatcher("/signInForm_10.jsp").forward(request, response);
        }
        else if (isNotFoundUser)
        {
            logger.info("to signInForm, user not found");
            request.getRequestDispatcher("/signInForm_10.jsp").forward(request, response);
        }

    }


}