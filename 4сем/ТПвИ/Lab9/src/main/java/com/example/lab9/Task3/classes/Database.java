package com.example.lab9.Task3.classes;

import java.lang.reflect.InvocationTargetException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private String url;
    private String username;
    private String password;

    public Database(String driver, String url, String username, String password) {
        try {
            Class.forName(driver).getDeclaredConstructor().newInstance();
        } catch (ClassNotFoundException | NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new RuntimeException("Driver class is missing in classpath", e);
        }
        this.url = url;
        this.username = username;
        this.password = password;
    }


    public Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }
}