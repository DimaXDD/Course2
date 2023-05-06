package com.example.lab10;

import com.example.lab10.classes.DAO;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet(name = "RegisterServlet", value = "/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    private final DAO db = new DAO();

    @Override
    public void init() throws ServletException {
        db.getConnection();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String login = request.getParameter("login");
        String password = request.getParameter("password");
        Object pass = password;
        response.setContentType("text/html");
        response.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();

        if (login.length() != 0 && password.length() != 0) {
            try {
                if (!db.Registration(login, password)) {
                    request.setAttribute("ErrorMessage", "Ошибка регистрации");
                    request.getRequestDispatcher("register.jsp").forward(request, response);
                    out.close();
                }
                else {
                    ResultSet res = db.ExecuteQuery("INSERT INTO Users (UserName, UserPassword, UserRole) VALUES ('" + login + "', '" + pass + "','user')");
                    ShowMessage(out, "Регистрация прошла успешно!", "index.jsp");
                    out.close();

                }
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        else {
            request.setAttribute("ErrorMessage", "Поля не могут быть пустыми");
            request.getRequestDispatcher("register.jsp").forward(request, response);
            out.close();
        }
    }
    private void ShowMessage(PrintWriter out, String message, String location) {
        out.println("<script type=\"text/javascript\">");
        out.println("alert('" + message + "');");
        out.println("window.location.href = '" + location + "';");
        out.println("</script>");
        out.println("</body></html>");
    }
}

