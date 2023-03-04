package by.trubach.taxipark;

import by.trubach.cars.Taxi;
import by.trubach.taxiexception.TaxiException;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class TaxiPark {
    private List<Taxi> taxiList = new ArrayList<>(); // создаем список для таксопарка

    public TaxiPark()
    {
        taxiList = new ArrayList<>();
    }

    public List<Taxi> getTaxiList() {
        return taxiList;
    }

    public void setTaxiList(List<Taxi> taxiList) {
        this.taxiList = taxiList;
    }

    public void add(Taxi taxi)
    {
        taxiList.add(taxi);
    }

    public void delete(Taxi taxi)
    {
        taxiList.remove(taxi);
    }

    public void deleteAll()
    {
        taxiList.removeAll(taxiList);
    }
    

    public class Manager implements IManager
    {
        public double getGeneralProfit()
        {
            double generalProfit = 0;
            for (Taxi taxi: getTaxiList())
                generalProfit += taxi.getProfit();
            return generalProfit;
        }

        public double getCompanyProfit()    /// профит компании с вычетом зарплаты водителям
        {
            return getGeneralProfit()*0.65;
        }

        public void searchSpeed(int min, int max) throws TaxiException
        {
            if (max < min || min < 0)
                throw new TaxiException("Invalid input of min or max speed");
            System.out.println("\nАвтомобили со скоростью " + min + "-" + max + " км/ч:");
            for (Taxi taxi: getTaxiList())
                if (taxi.getSpeed() > min && taxi.getSpeed() < max)
                    System.out.println(taxi.getNameCar() + " (" + taxi.getSpeed() + " км/ч)");
        }

        public void sortFuel()
        {
            getTaxiList().sort(new Comparator<Taxi>() {     // переопределение для сортировки по скорости
                @Override
                public int compare(Taxi o1, Taxi o2) {
                    return o1.compareTo(o2);
                }
            });
            System.out.println("\nОтсортированный по скорости таксопарк:");
            for (Taxi taxi: getTaxiList())
            {
                System.out.println(taxi.getNameCar() + " (" + taxi.getSpeed() + " км/ч)");
            }
        }
    }
}
