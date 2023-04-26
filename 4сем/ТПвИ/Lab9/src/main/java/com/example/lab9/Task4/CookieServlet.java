package com.example.lab9.Task4;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ServletCookie" , value = "/cookie-servlet")
public class CookieServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Cookie[] cookies = request.getCookies();
        String cookieLoginName = "login";
        String cookieRoleName = "role";
        String cookieDateName = "date";
        String cookieCountName = "count";
        Cookie cookieLogin = null;
        Cookie cookieRole = null;
        Cookie cookieDate = null;
        Cookie cookieCount = null;

        if (cookies != null) {
            for (Cookie c: cookies) {
                if (cookieLoginName.equals(c.getName()))
                    cookieLogin = c;
                if (cookieRoleName.equals((c.getName())))
                    cookieRole = c;
                if (cookieDateName.equals((c.getName())))
                    cookieDate = c;
                if (cookieCountName.equals((c.getName())))
                    cookieCount = c;
            }
        }

        PrintWriter out = response.getWriter();
        try {
            out.println("From cookies:");
            out.println("Login: " + cookieLogin.getValue());
            out.println("Role:  " + cookieRole.getValue());
            out.println("Date:  " + cookieDate.getValue());
            out.println("Count: " + cookieCount.getValue());
        }
        finally {
            out.close();
        }

    }

}