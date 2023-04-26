package com.example.lab9.Task5;

import java.io.IOException;
import java.util.ArrayList;
import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;

/**
 * SimpleServletFilter реализует интерфейс Filter
 */
@WebFilter("/RegisterFilter")
public class RegisterFilter implements Filter
{
    private FilterConfig filterConfig;
    private static ArrayList<String> pages;  // хранилище страниц

    public RegisterFilter()
    {
        // Создание хранилища страниц
        if (pages == null)
            pages = new ArrayList<String>();
    }

    public void destroy()
    {
        filterConfig = null;
    }


    /**
     * Метод инициализации фильтра
     * @see Filter#init(FilterConfig)
     */
    @Override
    public void init(FilterConfig fConfig) throws ServletException
    {
        filterConfig = fConfig;
    }


    /**
     * Метод фильтрации
     * @see Filter#doFilter(ServletRequest, ServletResponse, FilterChain)
     */
    @Override
    public void doFilter(ServletRequest request, ServletResponse response,
                         FilterChain filterChain) throws IOException, ServletException
    {
        // Если фильтр активной, то выполнить проверку
        if (filterConfig.getInitParameter("active").equalsIgnoreCase("true")) {
            HttpServletRequest req = (HttpServletRequest)request;
            // Раскладываем адрес на составляющие
            String[] list = req.getRequestURI().split("/");
            // Извлекаем наименование страницы
            String page = null;
            if (list[list.length - 1].indexOf(".jsp") > 0) {
                page = list[list.length - 1];
            }
            // Если открывается главная страница, то выполняем проверку
            if ((page != null) && page.equalsIgnoreCase("main.jsp")) {
                // Если была предварительно открыта одна из страниц
                // login.jsp, то передаем управление
                // следующему элементу цепочки фильтра
                if (pages.contains("login.jsp") ) {
                    filterChain.doFilter(request, response);
                    return;
                } else {
                    // Перенаправление на страницу login.jsp
                    ServletContext ctx = filterConfig.getServletContext();
                    RequestDispatcher dispatcher = ctx.getRequestDispatcher("/login.jsp");
                    dispatcher.forward(request, response);
                    return;
                }
            } else if (page != null) {
                // Добавляем страницу в список
                if (!pages.contains(page))
                    pages.add(page);
            }
        }
        filterChain.doFilter(request, response);
    }
}


