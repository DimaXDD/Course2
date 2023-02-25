package by.trubach.cars;
import by.trubach.taxiexception.TaxiException;

import java.io.Serializable;

public class Taxi extends Car implements Comparable <Taxi> { // наследуем от Comparable, чтобы перегрузить compareTo()
    private String nameCar;            // поля из класса Car
    private carType type;
    private double fuelRate;
    private int speed;

    private double taxiFare = 1; // новые поля для класса Taxi
    private double profit = 0;

    public Taxi()
    {

    }

    public Taxi(String nameCar, double fuel, int speed) throws TaxiException // конструктор с параметрами
    {
        if (nameCar == null || nameCar.isEmpty()) // проверка на пустую строку
        {
            throw new TaxiException("Название не может быть пустым");
        }
        this.nameCar = nameCar;
        this.fuelRate = fuel;
        this.speed = speed;
    }

    @Override
    public int compareTo(Taxi o)
    {
        return Integer.compare(this.getSpeed(), o.getSpeed());
    }

    public double ride(double km) throws TaxiException       // метод для поездок, который будем переопределять в каждом классе
    {
        if (km < 0)
            throw new TaxiException("Kilometres are less than zero");
        double income = taxiFare * km;
        String priceForRide = String.format("%.2f", income);
        double loss = getFuelRate() * km;
        this.setProfit(getProfit() + income - loss);
        System.out.println("Вы проехали " + km + " км в " + getNameCar() + ". С Вас " + priceForRide + " р. Спасибо за поездку!");
        return getProfit();
    }

    // геттеры и сеттеры для поля nameCar
    public String getNameCar() {
        return nameCar;
    }

    public void setNameCar(String nameCar) {
        this.nameCar = nameCar;
    }

    // геттеры и сеттеры для поля carType

    public carType getType() {
        return type;
    }

    public void setType(carType type) {
        this.type = type;
    }

    // геттеры и сеттеры для поля fuelRate

    public double getFuelRate() {
        return fuelRate;
    }

    public void setFuelRate(double fuelRate) {
        this.fuelRate = fuelRate;
    }

    // геттеры и сеттеры для поля speed

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    // геттеры и сеттеры для поля TaxiFare
    public double getTaxiFare() {
        return taxiFare;
    }

    public void setTaxiFare(double taxiFare) {
        this.taxiFare = taxiFare;
    }

    // геттеры и сеттеры для поля profit

    public double getProfit() {
        return profit;
    }

    public void setProfit(double profit) {
        this.profit = profit;
    }

}
