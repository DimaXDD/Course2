import org.apache.log4j.Logger;
import org.junit.Assert;
import org.junit.Ignore;
import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class DAOTesting {
    private static final Logger logger = Logger.getLogger(Main.class);
    private Connection con;
    private Statement statement;

    @BeforeEach
    void getProperties()
    {
        // сканируем файл database.properties с помощью ResourceBundle
        ResourceBundle resourceBundle = ResourceBundle.getBundle("database");
        String url = resourceBundle.getString("database.url");
        String user = resourceBundle.getString("database.username");
        String password = resourceBundle.getString("database.password");

        List<String> expected = new ArrayList<>();
        expected.add(url);
        expected.add(user);
        expected.add(password);

        DAO dao = new DAO();
        List<String> actual = dao.getProperties();

        Assert.assertEquals(expected, actual);
    }

    @Test
    @Timeout(1000)
    void getConnection()
    {
        DAO dao = new DAO();
        Boolean checkActual;
        Boolean checkExpected;

        try
        {
            ArrayList<String> propsExpected = dao.getProperties();
            String url = propsExpected.get(0);
            String user = propsExpected.get(1);
            String password = propsExpected.get(2);

            checkExpected = dao.getConnection();
            con = DriverManager.getConnection(url, user, password);
            statement = con.createStatement();
            checkActual = true;
        }
        catch (Exception ex)
        {
            logger.error("Connection failed...");
            System.out.println(ex);
            checkActual = false;
            checkExpected = false;
        }

        Assert.assertEquals(checkActual, checkExpected);
    }

    @Test
    void query1()
    {
        String expected;
        String actual;

        try
        {
            System.out.println("------------Запрос 1------------\n");
            DAO dao = new DAO();
            ArrayList<String> propsExpected = dao.getProperties();
            String url = propsExpected.get(0);
            String user = propsExpected.get(1);
            String password = propsExpected.get(2);
            con = DriverManager.getConnection(url, user, password);
            Statement statement = con.createStatement();

            ResultSet expectedRS = statement.executeQuery(
                    "select title, authors, year\n" +
                            "from Books\n" +
                            "where year between 1870 and 1950");

            while(expectedRS.next())
            {
                String title = expectedRS.getString(1);
                String authors = expectedRS.getString(2);
                String year = expectedRS.getString(3);
                System.out.println("Название: " + title + ", Авторы: " + authors + ", Год: " + year);
            }

            expected = expectedRS.toString();
            DAO dao1 = new DAO();
            System.out.println();
            dao1.getConnection();
            actual = dao1.Query1();
        }
        catch (Exception ex)
        {
            System.out.println("Ошибка запроса 1 (func Query1())");
            System.out.println(ex);
            expected = "";
            actual = "";
        }
    }

    @Ignore
    void query2()
    {
        System.out.println("------------Запрос 2------------\n");
        try {
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
            System.out.println(ex);

        }
    }

    public static boolean isPalindrome(String s) {
        String str = new StringBuilder(s).reverse().toString();
        return s == null ? false : str.equals(s);
    }

    @ParameterizedTest(name = "{index} - {0} is a palindrome")
    @ValueSource(strings = { "12321", "pop" })
    void testPalindrome(String word) {
        assertTrue(isPalindrome(word));
    }

    @AfterEach
    void closeConnection()
    {
        try
        {
            DAO dao = new DAO();
            ArrayList<String> propsExpected = dao.getProperties();
            String url = propsExpected.get(0);
            String user = propsExpected.get(1);
            String password = propsExpected.get(2);

            con = DriverManager.getConnection(url, user, password);
            con.close();
        }
        catch (Exception ex)
        {
            System.out.println(ex);
        }
    }
}
