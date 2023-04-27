package com.example.lab9.Lab10_servlets;

import com.example.lab9.Task3.classes.Database;
import com.example.lab9.Task3.classes.User;
import com.example.lab9.Task3.classes.UserDAO;
import com.microsoft.sqlserver.jdbc.StringUtils;
import jakarta.servlet.ServletException;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.Logger;

import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.*;

@WebServlet(name = "SignUpServlet", value = "/sign-up-servlet")
public class SignUpServlet extends HttpServlet {
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
        boolean isExistsUser = false;
        boolean isShortPassword = false;
        String loginCookie = "testLogin";
        String roleCookie = "testRole";



        try { areas = userDAO.list(); }
        catch (SQLException e) { throw new ServletException("Cannot retrieve areas", e); }


        String login = request.getParameter("login");
        String password = request.getParameter("password");



        for (User user : areas) {
            System.out.println(user.getUserName() + user.getUserPassword());
            if (user.UserName.equals(login)) {
                isExistsUser = true;
                request.setAttribute("ErrorMessage", "Логин уже занят");
                System.out.println("логин занят");
                break;
            }
            else if (password.length() < 6){
                isShortPassword = true;
                request.setAttribute("ErrorMessage", "Минимальная длина пароля – 6 символов");
                System.out.println("пароль плох");
            }
            else {
                System.out.println("все ок");
                try {
                    userDAO.addUser(login, password);
                    request.setAttribute("ErrorMessage", "Вы успешно зарегистрировались! Войдите в систему");
                } catch (SQLException e) {
                    e.printStackTrace();
                    request.setAttribute("ErrorMessage", "Логин уже занят");
                }
                break;
            }
        }


        if (StringUtils.isEmpty(login) || StringUtils.isEmpty(password)) {
            request.setAttribute("ErrorMessage", "Заполните все поля");
            request.getRequestDispatcher("/signUpForm_10.jsp").forward(request, response);
        }

        if (isShortPassword)
            request.getRequestDispatcher("/signUpForm_10.jsp").forward(request, response);
        else if (isExistsUser)
            request.getRequestDispatcher("/signUpForm_10.jsp").forward(request, response);
        else
            request.getRequestDispatcher("/signInForm_10.jsp").forward(request, response);
    }

}