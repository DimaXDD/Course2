package by.trubach.taxipark;

import by.trubach.taxiexception.TaxiException;

public interface IManager {
    public double getGeneralProfit();
    public double getCompanyProfit();
    public void searchSpeed(int min, int max) throws TaxiException;
    public void sortFuel();
}
