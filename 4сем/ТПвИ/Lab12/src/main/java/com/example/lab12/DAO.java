package com.example.lab12;

import java.lang.reflect.InvocationTargetException;
import java.sql.*;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class DAO implements IConnection, IQuery {
    private String url;
    private String user;
    private String password;
    private String driver;
    private Connection con;
    private Statement statement;

    public DAO() {

    }

    public ArrayList<String> getProperties() {
        url = "jdbc:sqlserver://DIMADD;database=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
        user = "sa";
        password = "1111";
        driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        try {
            Class.forName(driver);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException("Driver class is missing in classpath", e);
        }

        ArrayList<String> ret = new ArrayList<>();
        ret.add(url);
        ret.add(user);
        ret.add(password);
        return ret;
    }
    public Boolean getConnection() {
        try {
            getProperties();
            con = DriverManager.getConnection(url, user, password);
            statement = con.createStatement();
            return true;
        }
        catch(Exception ex) {
            ex.printStackTrace();
            return false;
        }
    }

    public ResultSet ExecuteQuery(String sqlQuery) {
        try {
            return statement.executeQuery(sqlQuery);
        }
        catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
    }
    public void closeConnection()
    {
        try {
            con.close();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
