package by.trubach.main;
import by.trubach.cars.*;
import by.trubach.taxiexception.TaxiException;
import by.trubach.taxitypes.*;
import by.trubach.taxipark.TaxiPark;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.*;

public class Main {
    static Logger LOGGER;
    static {
        try(FileInputStream ins = new FileInputStream("E:\\2_курс\\4сем\\ТПвИ\\Lab3\\log\\log.properties")){
            LogManager.getLogManager().readConfiguration(ins);
            LOGGER = Logger.getLogger(Main.class.getName());
        }catch (Exception ignore){
            ignore.printStackTrace();
        }
    }
    public static void main(String[] args) throws IOException {
        Handler fileHandler = new FileHandler();
        LOGGER.addHandler(fileHandler);
        LOGGER.setUseParentHandlers(false);

        try
        {
            // Инициализация такси разных типов
            Economy economy = new Economy("Geely", 0.25, 120);
            economy.ride(3.5);

            Comfort comfort = new Comfort("BMW", 0.35, 180);
            comfort.ride(5.7);

            Business business = new Business("Mercedes", 0.4, 200);
            business.ride(7);

            Luxury luxury = new Luxury("Rolls-Royce", 0.5, 220);
            luxury.ride(9.2);
            LOGGER.info("Созданы экземпляры классов Economy, Comfort, Business, Luxury");

            // Инициализация таксопарка
            TaxiPark taxiPark = new TaxiPark();
            taxiPark.add(economy);
            taxiPark.add(comfort);
            taxiPark.add(business);
            taxiPark.add(luxury);
            LOGGER.info("Создан экземпляр класса TaxiPark");
            System.out.println("\nМашины в таксопарке: ");
            for (Taxi taxi: taxiPark.getTaxiList())
                System.out.println(taxi.getNameCar());

            // Создание менеджера и вызов его методов
            TaxiPark.Manager manager = taxiPark.new Manager();
            String genProfit = String.format("%.3f", manager.getGeneralProfit());   // форматированный вывод после запятой
            System.out.println("\nОбщая прибыль за прошедший час без вычета зарплаты: " + genProfit + " р.");
            String companyProfit = String.format("%.3f", manager.getCompanyProfit());
            System.out.println("Общая прибыль за прошедший час с вычетом зарплаты:  " + companyProfit + " р.");
            LOGGER.info("Создали менеджера и посчитали по заданию");
            manager.searchSpeed(100,180);
            manager.sortFuel();
            LOGGER.info("Конец программы!!!");
        }
        catch (TaxiException e)
        {
            LOGGER.log(Level.SEVERE, "Ошибка создания экземпляра класса", e);
        }

    }
}