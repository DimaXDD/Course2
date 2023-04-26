package com.example.lab9.Task3.classes;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class UserDAO {
    private Database database;

    public UserDAO(Database database) {
        this.database = database;
    }

    public List<User> list() throws SQLException {
        Connection connection = null;
        PreparedStatement statement = null;
        ResultSet resultSet = null;
        List<User> areas = new ArrayList<User>();

        try {
            connection = database.getConnection();
            statement = connection.prepareStatement("select UserName, UserPassword, UserRole from Users");
            resultSet = statement.executeQuery();
            while (resultSet.next()) {
                User area = new User();
                area.setUserName(resultSet.getString("UserName"));
                area.setUserPassword(resultSet.getString("UserPassword"));
                area.setUserRole(resultSet.getString("UserRole"));
                areas.add(area);
            }
        } finally {
            if (resultSet != null) try { resultSet.close(); } catch (SQLException logOrIgnore) {}
            if (statement != null) try { statement.close(); } catch (SQLException logOrIgnore) {}
            if (connection != null) try { connection.close(); } catch (SQLException logOrIgnore) {}
        }
        return areas;
    }


    public void addUser(String name, String pass) throws SQLException {
        Connection connection = null;
        Statement statement = null;

        connection = database.getConnection();
        statement = connection.createStatement();
        statement.executeUpdate("insert into Users(UserName, UserPassword, UserRole) " +
                "values ('" +  name +"', '" + pass + "', 'user')");
    }


    public void addUserByAdmin(String name, String pass, String role) throws SQLException {
        Connection connection = null;
        Statement statement = null;

        connection = database.getConnection();
        statement = connection.createStatement();
        statement.executeUpdate("insert into Users(UserName, UserPassword, UserRole) " +
                "values ('" +  name +"', '" + pass + "', '" + role + "')");
    }


    public void deleteUser(String name) throws SQLException {
        Connection connection = null;
        Statement statement = null;

        connection = database.getConnection();
        statement = connection.createStatement();
        statement.executeUpdate("delete from Users where UserName = '" + name + "'");
    }

}