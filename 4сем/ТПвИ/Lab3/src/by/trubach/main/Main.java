package by.trubach.main;
import by.trubach.cars.*;
import by.trubach.taxiexception.TaxiException;
import by.trubach.taxitypes.*;
import by.trubach.taxipark.TaxiPark;

import java.io.IOException;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.*;
import javax.xml.validation.*;

import by.trubach.xmlparser.StaxStreamProcessor;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.LogManager;
import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.xml.sax.SAXException;

import javax.xml.XMLConstants;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import java.io.File;

public class Main {

    private static final Logger logger = Logger.getLogger(Main.class);
    static{
        new DOMConfigurator().doConfigure("E:\\2_курс\\4сем\\ТПвИ\\Lab3\\log\\log4j.xml",
                LogManager.getLoggerRepository());
    }

    public static void main(String[] args) throws IOException, TaxiException, SAXException {
        BasicConfigurator.configure();
        logger.info("Начало программы!");

        // Объекты для сериализации (задание 5)
        Economy economy = new Economy("Geely", 0.25, 120);
        Comfort comfort = new Comfort("BMW", 0.35, 180);
        Business business = new Business("Mercedes", 0.4, 200);
        Luxury luxury = new Luxury("Rolls-Royce", 0.5, 220);

        // Объекты для задания 6
        Economy economy1 = new Economy();
        Comfort comfort1 = new Comfort();
        Business business1 = new Business();
        Luxury luxury1 = new Luxury();

        List<Taxi> taxiList = Arrays.asList(economy, comfort, business, luxury);
        List<Taxi> taxiList1 = Arrays.asList(economy1, comfort1, business1, luxury1);

        // Сериализация в JSON
        StringWriter writer = new StringWriter();
        ObjectMapper mapper = new ObjectMapper();
        mapper.writeValue(writer, taxiList);

        String result = writer.toString();
        System.out.println(result);

        // Десериализация из JSON
        String jsonString = "[{\"nameCar\":\"Geely\",\"type\":\"ECONOMY\",\"fuelRate\":0.25,\"speed\":120,\"profit\":0.0}, {\"nameCar\":\"BMW\",\"type\":\"COMFORT\",\"fuelRate\":0.35,\"speed\":180,\"profit\":0.0}, {\"nameCar\":\"Mercedes\",\"type\":\"BUSINESS\",\"fuelRate\":0.4,\"speed\":200,\"profit\":0.0}, {\"nameCar\":\"Rolls-Royce\",\"type\":\"LUXURY\",\"fuelRate\":0.5,\"speed\":220,\"profit\":0.0}]";
        StringReader reader = new StringReader(jsonString);
        Taxi[] taxiArray = mapper.readValue(reader, Taxi[].class);
        System.out.println(taxiArray[0].toString()); // если вывести конкретный
        //System.out.println(Arrays.toString(taxiArray)); // если вывести весь массив

        // списки, куда будут записываться разные данные из xml и потом этими значениями проинициализируем объекты
        ArrayList<String> taxiNamesCar = new ArrayList<>();
        ArrayList<String> taxiFuels = new ArrayList<>();
        ArrayList<String> taxiSpeeds = new ArrayList<>();
        ArrayList<String> taxiTypes = new ArrayList<>();

        // считываем в списки названий, скоростей, расхода топлива и типов такси инфу из xml (ф-ия из класса)
        StaxStreamProcessor.addNamesToList("NameCar", taxiNamesCar);
        StaxStreamProcessor.addNamesToList("Fuel", taxiFuels);
        StaxStreamProcessor.addNamesToList("Speed", taxiSpeeds);
        StaxStreamProcessor.addNamesToList("Type", taxiTypes);

        // выводим на экран считанные из XML-документа данные
        for (int i = 0; i < taxiList1.size(); i++)
        {
            taxiList1.get(i).setNameCar(taxiNamesCar.get(i));
            taxiList1.get(i).setSpeed(Integer.parseInt(taxiSpeeds.get(i)));
            taxiList1.get(i).setFuelRate(Double.parseDouble(taxiFuels.get(i)));
            taxiList1.get(i).ride(Math.random() * 10);  /// применяем метод ride на рандомнео число от 0 до 10
        }


        // выводим на экран проинициализированные машины
        System.out.println("\n\nПроиницализированные XML-документом машины:");
        for (Taxi taxi: taxiList1)
             System.out.println("Название:  " + taxi.getNameCar() + "\nРасход:    " + taxi.getFuelRate() +
                       " л/км\nСкорость:  " + taxi.getSpeed() + " км/ч\nТип такси: " + taxi.getType() + "\n");

        // валидация xml с xsd
        File schemaFile = new File("files/validation.xsd");
        Source xmlFile = new StreamSource(new File("files/taxilist.xml"));
        SchemaFactory schemaFactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI); // нужно для считывания схемы
        Schema schema = schemaFactory.newSchema(schemaFile);    // здесь лежит прочитанная и понятная джаве сама xsd-схема
        Validator validator = schema.newValidator();            // запуск xsd-валидатора из javax.xml.validation.Validator
        validator.validate(xmlFile);                            // сама валидация
        System.out.println("\nXML-файл успешно прошёл валидацию с XSD!");




        // !!!!!!!!!!!!!!!!! Код к 3 лабе !!!!!!!!!!
        /*try
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
*/
    }
}