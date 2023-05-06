package com.example.lab10;

import com.example.lab10.classes.DAO;
import com.example.lab10.classes.User;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@WebServlet(name = "MainServlet", value = "/MainServlet")
public class MainServlet extends HttpServlet {
    private static final DAO db= new DAO();

    private void ShowMessage(PrintWriter out, String message, String location) {
        out.println("<script type=\"text/javascript\">");
        out.println("alert('" + message + "');");
        out.println("window.location.href = '" + location + "';");
        out.println("</script>");
        out.println("</body></html>");
    }

    @Override
    public void init() throws ServletException {
        db.getConnection();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        db.DeleteTelegram(
                request.getParameter("id")
        );

        HttpSession session = request.getSession();
        User user = (User)session.getAttribute("current_user");
        request.setAttribute("name", user.getLogin());
        request.getRequestDispatcher("welcome.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        db.AddTelegram(
                request.getParameter("name"),
                request.getParameter("category"),
                Integer.valueOf(request.getParameter("subs"))
        );

        HttpSession session = request.getSession();
        User user = (User)session.getAttribute("current_user");

        request.setAttribute("name", user.getLogin());
        request.getRequestDispatcher("welcome.jsp").forward(request, response);
    }

    @Override
    public void destroy() {
        db.closeConnection();
    }
}

