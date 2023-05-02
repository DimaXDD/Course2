package com.example.lab10;

import jakarta.servlet.FilterChain;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletContext;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpFilter;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.logging.Filter;
import java.util.logging.LogRecord;

public class FilterNotAutorize extends HttpFilter {

    public void init() {

    }

    public void doFilter(HttpServletRequest request, HttpServletResponse response, FilterChain chain) throws ServletException, IOException {
        String path = "/Error";
        request.setAttribute("message","No Autorize");
        ServletContext context = request.getServletContext();
        RequestDispatcher requestDispatcher = context.getRequestDispatcher(path);
        requestDispatcher.forward(request, response);
    }

    public void destroy() {

    }
}
