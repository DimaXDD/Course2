package db;

import entities.users;
import entities.telegram;

import java.sql.*;
import java.util.ArrayList;

public class DBConnection {
    //static final Logger logger = LogManager.getLogger(DBConnection.class);
    private Connection connection;
    private Statement statement;

    public Connection GetConnection() throws SQLException {
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver").getDeclaredConstructor().newInstance();
            String url = "jdbc:sqlserver://DIMADD;databaseName=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
            connection = (Connection) DriverManager.getConnection(url, "sa","1111");
            System.out.println("Connection successful!");
        }catch (Exception ex) {
            System.out.println("Connection failed...");

            System.out.println(ex);
        }

        return connection;
    }

    public ArrayList<users> GetAllUsers() throws SQLException {
        String sqlQuery="select * from Users;";
        statement = connection.createStatement();
        ResultSet resultSet=statement.executeQuery(sqlQuery);

        ArrayList<users> users = new ArrayList<entities.users>();
        while(resultSet.next()){
            String username = resultSet.getString(1);
            String password = resultSet.getString(2);
            String role = resultSet.getString(3);

            entities.users user = new users(username,password,role);
            users.add(user);
        }
        return users;
    }

    public boolean AddUser(users user) throws SQLException {

        //проверка на существующее имя пользователя
        String select="insert into Users(UserName,UserPassword,UserRole) values('"+user.getUsername() +"','"+user.getPassword()+ "','user');";
        statement = GetConnection().createStatement();
        //logger.info("Добавление пользователя");
        statement.executeUpdate(select);

        return true;
    }

    public users GetByUsername(String Username) throws SQLException {
        String select ="select UserName,UserPassword,UserRole from Users where UserName = '"+Username+"';";
        statement = GetConnection().createStatement();
        ResultSet resultSet= statement.executeQuery(select);
        users user=null;
        if(resultSet != null){
            while(resultSet.next()){
                String username = resultSet.getString(1);
                String password = resultSet.getString(2);
                String role = resultSet.getString(3);
                user = new users(username,password,role);
            }
        }
        return  user;
    }
    public telegram GetByname(String names) throws SQLException {
        String select ="select name, category, subs from telegram where name = '"+names+"';";
        statement = GetConnection().createStatement();
        ResultSet resultSet= statement.executeQuery(select);
        telegram telegrams = null;
        if(resultSet != null){
            while(resultSet.next()){
                String name = resultSet.getString(1);
                String category = resultSet.getString(2);
                Integer subs = resultSet.getInt(3);
                telegrams = new telegram(name, category, subs);
            }
        }
        return  telegrams;
    }
    public ArrayList<telegram> GetAllTelegrams() throws SQLException {
        String sqlQuery="select name, category, subs from telegram;";
        statement = GetConnection().createStatement();
        ResultSet resultSet=statement.executeQuery(sqlQuery);

        ArrayList<telegram> telegrams = new ArrayList<telegram>();
        while(resultSet.next()){
            String name = resultSet.getString(1);
            String category = resultSet.getString(2);
            Integer subs = resultSet.getInt(3);
            telegram telegram = new telegram(name, category, subs);
            telegrams.add(telegram);
        }
        return telegrams;
    }
    public boolean AddTelegrams(telegram tel) throws SQLException {
        //logger.info("Добавление народа");
        String select="insert into telegram(name,category,subs) values('"+tel.getName() +"','"+tel.getCategory()+ "','"+tel.getSubs()+"');";
        statement = GetConnection().createStatement();
        statement.executeUpdate(select);
        return true;
    }
    public boolean Remove(String names) throws SQLException {
        //logger.info("Удаление народа");
        String select="DELETE FROM telegram WHERE name ='"+names+"'";
        statement = GetConnection().createStatement();

        statement.executeUpdate(select);

        return true;
    }
    public boolean Update(String names,String number) throws SQLException {
        //logger.info("Изменение народа");
        String select="UPDATE telegram SET subs ='"+number+"' WHERE name ='"+names+"'";
        statement = GetConnection().createStatement();
        statement.executeUpdate(select);

        return true;
    }
}