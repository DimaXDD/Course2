package com.example.lab10.classes;

import java.lang.reflect.InvocationTargetException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Base64;
import java.util.ResourceBundle;

public class DAO  implements IConnection, IQuery {
    private String DB_ConnectionStr;
    private String DB_Login;
    private String DB_Password;
    private String Driver ;
    private Connection con;
    private Statement statement;
    private PreparedStatement preparedStatement;

    public DAO(){
    }
    //Авторизация
    public String[] Authorization(String UserName, String UserPassword){
        try (Connection connection = DriverManager.getConnection(DB_ConnectionStr, DB_Login, DB_Password))
        {
            Statement statement = connection.createStatement();
            String sqlCommand = "SELECT UserName, UserPassword, UserRole FROM Users";
            ResultSet resultset = statement.executeQuery(sqlCommand);

            Boolean peopleIn = false;
            String[] inform = new String[3];
            while (resultset.next()) {
                String Name = resultset.getString(1);
                String pass = resultset.getString(2);
                String role = resultset.getString(3);

                if( Name.equals(UserName) && checkPassword(UserPassword, pass)){
                    peopleIn=true;
                    inform[0] = Name;
                    inform[1] = role;
                    inform[2] = LocalTime.now().toString();
                }
            }
            if(peopleIn){
                return inform;
                //потом добавить cookie
            }
        }catch (SQLException | NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }

        return null;
    }
    //регистрация пользователя
    public boolean Registration(String un, String up){
        try (Connection connection = DriverManager.getConnection(DB_ConnectionStr, DB_Login, DB_Password)) {
            Statement statement = connection.createStatement();
            //создание строки запроса
            String insert = "INSERT INTO Users(UserName, UserPassword, UserRole) \n" + " VALUES(?,?,?)";

            PreparedStatement stp = connection.prepareStatement(insert);

            //надо переделать, что бы пароль хешировался

            stp.setString(1, un);//user name
            stp.setString(2, hashPassword(up));//user password
            stp.setString(3, "user");//user role

            //выполнение запроса
            stp.executeUpdate();
            try{
                connection.close();
                statement.close();
                stp.close();
            }finally {
                return true;
            }
        } catch (SQLException | NoSuchAlgorithmException e) {throw new RuntimeException(e);}
    }

    //хеширование пароля
    public static String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashedBytes = md.digest(password.getBytes());
        return Base64.getEncoder().encodeToString(hashedBytes);
    }

    //сравнение пароля с хешем
    public static boolean checkPassword(String password, String hashedPassword) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashedBytes = md.digest(password.getBytes());
        String hashedPasswordToCheck = Base64.getEncoder().encodeToString(hashedBytes);
        return hashedPassword.equals(hashedPasswordToCheck);
    }

    //Установка параметров соединения с бд (тут MySQL)
    @Override
    public ArrayList<String> getProperties() {
        DB_ConnectionStr = "jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
        DB_Login = "sa";
        DB_Password = "1111";
        Driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        try{
            Class.forName(Driver).getDeclaredConstructor().newInstance();
        }catch (ClassNotFoundException | NoSuchMethodException | IllegalAccessException | InstantiationException | InvocationTargetException e) {
            throw new RuntimeException(e);
        }

        ArrayList<String> ret = new ArrayList<>();
        ret.add(DB_ConnectionStr);
        ret.add(DB_Login);
        ret.add(DB_Password);
        return ret;
    }

    //Получение подключения
    @Override
    public Boolean getConnection() {

        try {
            getProperties();
            con = DriverManager.getConnection(DB_ConnectionStr, DB_Login, DB_Password);
            statement = con.createStatement();
            return true;
        }
        catch(Exception ex) {
            ex.printStackTrace();
            return false;
        }
    }

    //Закрытие подключения
    @Override
    public void closeConnection() {
        try {
            con.close();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    //выполнение кастомного запроса
    @Override
    public ResultSet ExecuteQuery(String sqlQuery) {
        try {
            //этот пашет
            return statement.executeQuery(sqlQuery);
        }
        catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
    }
    //
    public ArrayList<Telegram> getTelegram() {
        ArrayList<Telegram> telegrams = new ArrayList<>();
        ResultSet rs = ExecuteQuery("select * from telegram");
        try {
            while (rs.next()) {
                Telegram currentUniversityClass = new Telegram();
                currentUniversityClass.setId(rs.getInt("Id"));
                currentUniversityClass.setName(rs.getString("Name"));
                currentUniversityClass.setCategory(rs.getString("Category"));
                currentUniversityClass.setSubs(rs.getInt("Subs"));
                telegrams.add(currentUniversityClass);
            }
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        return telegrams;
    }

    public boolean AddTelegram(String _name, String _category, Integer _subs){
        try (Connection connection = DriverManager.getConnection(DB_ConnectionStr, DB_Login, DB_Password)) {
            Statement statement = connection.createStatement();
            //создание строки запроса
            String insert = "INSERT INTO telegram(name, category, subs) \n" + " VALUES(?,?,?)";

            PreparedStatement stp = connection.prepareStatement(insert);

            //надо переделать, что бы пароль хешировался

            stp.setString(1, _name);
            stp.setString(2, _category);
            stp.setInt(3, _subs);

            //выполнение запроса
            stp.executeUpdate();
            try{
                connection.close();
                statement.close();
                stp.close();
            }finally {
                return true;
            }
        } catch (SQLException e) {throw new RuntimeException(e);}
    }
    public boolean DeleteTelegram(String _id){
        try (Connection connection = DriverManager.getConnection(DB_ConnectionStr, DB_Login, DB_Password)) {
            Statement statement = connection.createStatement();
            //создание строки запроса
            String insert = "delete from telegram where id = " + _id;

            PreparedStatement stp = connection.prepareStatement(insert);

            //выполнение запроса
            stp.executeUpdate();
            try{
                connection.close();
                statement.close();
                stp.close();
            }finally {
                return true;
            }
        } catch (SQLException e) {throw new RuntimeException(e);}

    }
}