package com.example.lab9.Task5;

import java.io.*;

import jakarta.servlet.*;
import jakarta.servlet.http.*;

public final class LoggingFilter implements Filter {
    private FilterConfig filterConfigObj = null;

    public void init(FilterConfig filterConfigObj) {
        this.filterConfigObj = filterConfigObj;
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        String remoteAddress =  request.getRemoteAddr();
        String uri = ((HttpServletRequest) request).getRequestURI();
        String protocol = request.getProtocol();

        chain.doFilter(request, response);
        System.out.println("Logging Filter Servlet called");
        System.out.println("=====================================================================");
        System.out.println("User Logged! User IP: " + remoteAddress +
                " Resource File: " + uri + " Protocol: " + protocol);
    }

    public void destroy() { }
}
