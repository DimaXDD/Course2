import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // cd "E:\2_курс\4сем\ТПвИ\Lab7\src"
        // javac -cp "./log4j-1.2.17-2.0.jar;" Main.java
        // java -cp "./mssql-jdbc-11.2.3.jre17.jar;./log4j-1.2.17-2.0.jar";. Main

        DAO dao = new DAO();
        dao.logInfo();
        dao.getConnection();
        System.out.println("------------Запрос 1------------\n");
        dao.Query1();
        System.out.println("------------Запрос 2------------\n");
        dao.Query2();
        System.out.println("------------Запрос 3------------\n");
        System.out.println("Введите кол-во книг: ");
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        dao.Query3(input);
        System.out.println("------------Запрос 4------------\n");
        dao.Query4();
        dao.closeConnection();

        /*DAOTesting daoTesting = new DAOTesting();
        daoTesting.getProperties();
        daoTesting.getConnection();

        daoTesting.query1();
        daoTesting.query2();
        daoTesting.closeConnection();*/

    }
}