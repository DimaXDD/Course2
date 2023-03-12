package task2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

public class Main {
    private static final int NUMBER_OF_CARS = 15;
    private static final int FIRST_PARKING = 4;
    private static final int SECOND_PARKING = 5;

    public static void main(String[] args) {
        Parking firstParking = new Parking(1, FIRST_PARKING);
        Parking secondParking = new Parking(2, SECOND_PARKING);

        Semaphore firstSem = new Semaphore(firstParking.getCapacity(), true);
        Semaphore secondSem = new Semaphore(secondParking.getCapacity(), true);

        ExecutorService service = Executors.newCachedThreadPool();

        for (int number = 1; number <= NUMBER_OF_CARS; ) {
            service.execute(new Car(firstSem, firstParking, number++));
            service.execute(new Car(secondSem, secondParking, number++));
        }

        service.shutdown();
    }

}
