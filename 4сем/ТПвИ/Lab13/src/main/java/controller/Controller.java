package controller;

import entities.users;
import entities.telegram;
import entities.telegram;
import jakarta.servlet.*;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

import static models.AddTelegram.AddTelegramMethod;
import static models.DelTelegram.DelTelegramMethod;
import static models.Page.PageMethod;
import static models.Register.RegisterMethod;
import static models.UpdTelegram.UpdateTelegramMethod;
import static models.Welcome.WelcomeMethod;

public class Controller extends HttpServlet {
    private static final String COMMAND="command";
    public static final String LOGIN="login";
    public static final String REGISTER="register";
    public static final String PAGE="page";
    public static final String ADD_TELEGRAM="addTelegram";
    public static final String DEL_TELEGRAM="delTelegram";
    public static final String UPD_TELEGRAM="updTelegram";
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req,resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req,resp);
    }

    private void processRequest(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        String command = request.getParameter(COMMAND);
        switch (command){
            case LOGIN:{
                WelcomeMethod(request,response);
                break;
            }
            case REGISTER:{
                RegisterMethod(request,response);
                break;
            }
            case PAGE:{
                PageMethod(request,response);
                break;
            }
            case ADD_TELEGRAM:{
                AddTelegramMethod(request,response);
                break;
            }
            case DEL_TELEGRAM:{
                DelTelegramMethod(request,response);
                break;
            }
            case UPD_TELEGRAM: {
             UpdateTelegramMethod(request,response);
             break;
            }
            }
        }
    }


