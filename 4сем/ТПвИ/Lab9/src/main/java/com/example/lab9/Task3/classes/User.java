package com.example.lab9.Task3.classes;

public class User {
    public String UserName;
    public String UserPassword;
    public String UserRole;

    public User() { }
    public User(String userName, String userPassword, String userRole) {
        UserName = userName;
        UserPassword = userPassword;
        UserRole = userRole;
    }


    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        UserName = userName;
    }

    public String getUserPassword() {
        return UserPassword;
    }

    public void setUserPassword(String userPassword) {
        UserPassword = userPassword;
    }

    public String getUserRole() {
        return UserRole;
    }

    public void setUserRole(String userRole) {
        UserRole = userRole;
    }
}