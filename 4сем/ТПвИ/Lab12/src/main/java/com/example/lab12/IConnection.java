package com.example.lab12;

import java.util.ArrayList;

public interface IConnection {
    public ArrayList<String> getProperties();
    public Boolean getConnection();
    public void closeConnection();
}