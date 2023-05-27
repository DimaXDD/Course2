package filter;

import jakarta.servlet.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

public class ResultFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) res;
        HttpSession session = request.getSession(false);

        String loginURL = request.getContextPath() + "/welcome";
        String registerURL = request.getContextPath() + "/register";

        boolean loggedIn = session != null && session.getAttribute("user") != null;
        boolean loginRequest = request.getRequestURI().equals(loginURL) || request.getRequestURI().equals(loginURL + ".jsp");
        boolean registrRequest = request.getRequestURI().equals(registerURL) || request.getRequestURI().equals(registerURL + ".jsp");

        if(loggedIn || loginRequest || registrRequest) {
            chain.doFilter(req, res);
        }
        else {
            response.sendRedirect("welcome.jsp");
        }
    }

    @Override
    public void destroy() {

    }
}
