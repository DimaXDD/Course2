package com.example.lab9.Task6.forward;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet(name = "toServletForward", value = "/to-servlet-forward")
public class ToServlet extends HttpServlet {


    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        var mesTo = request.getAttribute("mesFrom");

        // ================  TASK 6  ================
//        PrintWriter out = response.getWriter();
//        out.println("<html><body>");
//        out.println("<h2>" + mes.toString() + "</h2>");
//        out.println("</body></html>");
//        out.close();



        // ================  TASK 6b  ================
        request.setAttribute("mesTo", mesTo);
        request.getRequestDispatcher("/task6forward.jsp").forward(request, response);
    }
}