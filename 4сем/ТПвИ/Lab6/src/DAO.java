import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.Logger;

import java.sql.*;
import java.util.ArrayList;
import java.util.ResourceBundle;
public class DAO implements IConnect, IQuery {
    private String url;
    private String user;
    private String password;
    private Connection con;
    private Statement statement;
    private static final Logger logger = Logger.getLogger(Main.class);

    // LOG
    public void logInfo() {
        BasicConfigurator.configure();
        logger.info("Начало Main");
    }

    public ArrayList<String> getProperties() {
        // сканируем файл database.properties с помощью ResourceBundle
        ResourceBundle resourceBundle = ResourceBundle.getBundle("database");
        url = resourceBundle.getString("url");
        user = resourceBundle.getString("user");
        password = resourceBundle.getString("password");

        ArrayList<String> prop = new ArrayList<String>();
        prop.add(url);
        prop.add(user);
        prop.add(password);
        return prop;
    }

    public Boolean getConnection() {
        // Подключение БД в Java :):):):):)

        // cd "E:\2_курс\4сем\ТПвИ\Lab6\src"
        // javac Main.java
        // java -classpath mssql-jdbc-11.2.3.jre17.jar;. Main

        try {
            logger.info("Подключение к БД (func getConnection())");
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String connectionUrl = "jdbc:sqlserver://DIMADD;databaseName=Lab6_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false";
            con = DriverManager.getConnection(connectionUrl, "sa", "1111");
            statement = con.createStatement();
            logger.info("Подключение к БД успешно (func getConnection())");
            return true;
        }
        catch(Exception ex) {
            logger.error("Ошибка подключения к БД (func getConnection())");
            System.out.println(ex);
            return false;
        }
    }

    public void closeConnection() {
        try {
            logger.info("Закрытие соединения с БД (func closeConnection())");
            con.close();
            logger.info("Соединение с БД закрыто (func closeConnection())");
        }
        catch (Exception ex) {
            logger.error("Ошибка закрытия соединения с БД (func closeConnection())");
            System.out.println(ex);
        }
    }

    public String Query1() {
        // Найти все книги, вышедшие в текущем и прошлом году
        try {
            logger.info("Запрос 1 (func Query1())");
            // Для выборки данных с помощью команды SELECT
            /*ResultSet resultSet = statement.executeQuery(
                    "SELECT * FROM Books " +
                            "WHERE YEAR(Date) = YEAR(GETDATE()) OR YEAR(Date) = YEAR(GETDATE()) - 1");*/
            ResultSet resultSet = statement.executeQuery(
                    "select title, authors, year\n" +
                            "from Books\n" +
                            "where year between 1870 and 1950"
            );

            // пока в ResultSet (результирующий набор строк) есть строки, выбираем и выводим как нам угодно нужные столбцы
            while(resultSet.next()) {
                String title = resultSet.getString(1);
                String authors = resultSet.getString(2);
                String year = resultSet.getString(3);
                logger.info("Запрос 1 (func Query1())");
                System.out.println("Название: " + title + ", Авторы: " + authors + ", Год: " + year);
            }
            return resultSet.toString();

        } catch (Exception ex) {
            logger.error("Ошибка запроса 1 (func Query1())");
            System.out.println(ex);
            return "";
        }
    }

    public void Query2() {
        // Вывести информацию об авторах
        try {
            logger.info("Запрос 2 (func Query2())");
            ResultSet resultSet = statement.executeQuery(
                    "SELECT * FROM authors"
            );

            while(resultSet.next()) {
                String id = resultSet.getString(1);
                String full_name = resultSet.getString(2);
                String country = resultSet.getString(3);
                logger.info("Запрос 2 (func Query2())");
                System.out.println("ID: " + id + ", ФИО: " + full_name + ", Страна: " + country);
            }
        }
        catch (Exception ex) {
            logger.error("Ошибка запроса 2 (func Query2())");
            System.out.println(ex);

        }
    }

    public void Query3(int n) {
        // Вывести информацию об авторах, написавших как минимум n книг
        try {
            logger.info("Запрос 3 (func Query3())");
            String preparedQuery = "SELECT full_name, COUNT(*) AS count FROM authors " +
                    "INNER JOIN books ON Authors.id = Books.author_id " +
                    "GROUP BY full_name" +
                    "HAVING COUNT(*) >= " + n;
            PreparedStatement preparedStatement = con.prepareStatement(preparedQuery);
            preparedStatement.setInt(1, n);
            ResultSet resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                String full_name = resultSet.getString(1);
                String count = resultSet.getString(2);
                logger.info("Запрос 3 (func Query3())");
                System.out.println("ФИО: " + full_name + ", Количество книг: " + count);
            }
        }
        catch (Exception ex) {
            logger.error("Ошибка запроса 3 (func Query3())");
            System.out.println(ex);
        }
    }

    public void Query4()
    {
        // Удалить все книги, публикация которых была позднее заданного года
        try {
            logger.info("Start Query4");
            statement.executeUpdate(
                    "DELETE FROM books " +
                            "WHERE year > 1950"
            );

            // Вывести, сколько строк было затронуто
            ResultSet resultSet = statement.executeQuery(
                    "SELECT @@ROWCOUNT"
            );

            while(resultSet.next()){
                String count = resultSet.getString(1);
                System.out.println("Rows affected: " + count);
            }
        }
        catch (Exception ex) {
            logger.error("Error in query4!");
            System.out.println("Error in query4!");
            System.out.println(ex);
        }
    }
}
