package by.trubach.taxitypes;

import by.trubach.cars.Taxi;
import by.trubach.cars.carType;
import by.trubach.taxiexception.TaxiException;

public class Business extends Taxi {
    private final carType type = carType.BUSINESS;
    private double taxiFare = 3;

    public Business() {
    }
    public Business(String nameCar, double fuel, int speed) throws TaxiException {
        super(nameCar, fuel, speed);
    }

    @Override
    public double ride(double km) throws TaxiException {
        if (km < 0)
            throw new TaxiException("Kilometres are less than zero");
        double income = taxiFare * km;
        String priceForRide = String.format("%.2f", income);
        double loss = getFuelRate() * km;
        this.setProfit(getProfit() + income - loss);
        System.out.println("Вы проехали " + km + " км в " + getNameCar() + ". С Вас " + priceForRide + " р. Спасибо за поездку!");
        return getProfit();
    }

    public carType getType() {
        return type;
    }

    public double getTaxiFare() {
        return taxiFare;
    }
}
