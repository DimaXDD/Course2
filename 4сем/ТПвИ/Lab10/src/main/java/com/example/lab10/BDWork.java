package com.example.lab10;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class BDWork {
    private  static Connection connecor;

    private static void connection() throws SQLException
    {
        connecor = DriverManager.getConnection("jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false","sa","1111");
    }
    private static void closeConnection() throws SQLException
    {
        connecor.close();
    }

    public static String getUsers(String login, String password) throws SQLException {
        connection();
        String zapros = "Select * from Users where Login = ? and Password = ?";
        PreparedStatement statement = connecor.prepareStatement(zapros);
        statement.setString(1,login);
        statement.setString(2,password);
        ResultSet resultSet = statement.executeQuery();
        String response = null;
        while (resultSet.next()) {
            response = resultSet.getString(3);
        }
        return response;
    }

    public static String Register(String login, String Password) throws SQLException {
        connection();
        String zapros = "Insert Users values(?,?,?)";
        PreparedStatement preparedStatement = connecor.prepareStatement(zapros);
        preparedStatement.setString(1,login);
        preparedStatement.setString(2,Password);
        preparedStatement.setString(3,"user");
        int resultSet = preparedStatement.executeUpdate();
        if (resultSet != 1)
        {
            return "error";
        }
        return "good";
    }

    public static ArrayList<ForestPlans> GetPlans() throws SQLException {
        ArrayList<ForestPlans> plansList = new ArrayList<ForestPlans>();
        String zapros = "select * from ForestPlans";
        PreparedStatement preparedStatement = connecor.prepareStatement(zapros);
        ResultSet result = preparedStatement.executeQuery();
        while (result.next())
        {
            ForestPlans forestPlans = new ForestPlans(result.getInt(1),result.getString(2),result.getString(3));
            plansList.add(forestPlans);
        }
        return  plansList;
    }

    public static String InsertPlans(int id,String type, String name) throws SQLException {
        connection();
        String zapros = "Insert Forestplans values(?,?,?)";
        PreparedStatement preparedStatement = connecor.prepareStatement(zapros);
        preparedStatement.setInt(1,id);
        preparedStatement.setString(2,type);
        preparedStatement.setString(3,name);
        int resultSet = preparedStatement.executeUpdate();
        if (resultSet != 1)
        {
            return "error";
        }
        return "good";
    }

    public static String DeletePlans(int id) throws SQLException {
        connection();
        String zapros = "delete from ForestPlans where Id = ?";
        PreparedStatement statement = connecor.prepareStatement(zapros);
        statement.setInt(1,id);
        int resultSet = statement.executeUpdate();
        if (resultSet != 1)
        {
            return "error";
        }
        return "good";

    }

}
