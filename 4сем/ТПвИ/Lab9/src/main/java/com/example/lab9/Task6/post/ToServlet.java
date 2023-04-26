package com.example.lab9.Task6.post;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "toServletPost", value = "/to-servlet-post")
public class ToServlet extends HttpServlet {

    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String user = request.getParameter("user");

        response.setContentType("text/html");
        response.setCharacterEncoding("UTF-8");

        // create HTML response
        PrintWriter writer = response.getWriter();
        writer.append("<!DOCTYPE html>\r\n")
                .append("<html>\r\n")
                .append("        <head>\r\n")
                .append("            <title>Welcome message</title>\r\n")
                .append("        </head>\r\n")
                .append("        <body>\r\n");
        if (user != null && !user.trim().isEmpty()) {
            writer.append("    Welcome, " + user + "!\r\n");
        } else {
            writer.append("    You did not entered a name!\r\n");
        }
        writer.append("        </body>\r\n")
                .append("</html>\r\n");
    }
}