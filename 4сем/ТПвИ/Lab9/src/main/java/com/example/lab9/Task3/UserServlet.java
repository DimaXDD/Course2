package com.example.lab9.Task3;

import com.example.lab9.Task3.classes.Database;
import com.example.lab9.Task3.classes.User;
import com.example.lab9.Task3.classes.UserDAO;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.*;

@WebServlet(name = "userServlet", value = "/user-servlet")
public class UserServlet extends HttpServlet {
    private UserDAO userDAO;
    public List<User> areas = new ArrayList<>();
    private int numberr;
    private String numberCookie;
    private String loginCookie = "testLogin";
    private String roleCookie = "testRole";
    private String dateCookie;


    // тут надо будет заменить на свою строку подключения. не забудьте добавить в Libraries драйвер ssms
    // и добавить в Artifacts -> war exploded -> WEB-INF -> lib -> Add a copy of -> Library files и туда нужные либы
    public void init() {
        String driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String url = "jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
        String username = "sa";
        String password = "1111";
        Database database = new Database(driver, url, username, password);
        this.userDAO = new UserDAO(database);
    }



    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        Date currentDate = new Date();
        boolean isFoundUser = false;
        numberr++;

        try {
            areas = userDAO.list();
        } catch (SQLException e) {
            throw new ServletException("Cannot retrieve areas", e);
        }

        String login = request.getParameter("login");
        String password = request.getParameter("password");

        response.setContentType("text/html");
        response.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");

        for (User user : areas) {
            if (user.UserName.equals(login) && user.UserPassword.equals(password)) {
//                out.println("<h1>Greetings!</h1>");
//                out.println("<h3>Name: " + user.getUserName() + "</h3>");
//                out.println("<h3>Role: " + user.getUserRole() + "</h3>");
//                out.println("<h3>Date: " + currentDate + "</h3>");
                request.setAttribute("name", user.getUserName());
                request.setAttribute("role", user.getUserRole());
                request.setAttribute("date", currentDate);
                isFoundUser = true;
                loginCookie = user.getUserName();
                roleCookie = user.getUserRole();
                dateCookie = currentDate.toString();
                numberCookie = "1";
            }
        }




        // =================================  TASK 4 (COOKIES)  =================================

        HttpSession session = request.getSession();

        Cookie cookieLogin = new Cookie("login", loginCookie);
        Cookie cookieRole = new Cookie("role", roleCookie);
//        Cookie cookieDate = new Cookie("date", new Date(session.getLastAccessedTime()).toString());
//        Cookie cookieCount = new Cookie("count", "1");
        response.addCookie(cookieRole);
        response.addCookie(cookieLogin);
//        response.addCookie(cookieDate);
//        response.addCookie(cookieCount);

        if (isFoundUser)
            request.getRequestDispatcher("/main.jsp").forward(request, response);
        else
            request.getRequestDispatcher("/registration.jsp").forward(request, response);

        out.println("</body></html>");
        out.close();


    }

}