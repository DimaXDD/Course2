package task2;

import java.util.Random;
import java.util.concurrent.Semaphore;

public class Car implements Runnable{
    private final Semaphore slot;
    private final Parking parking;
    private final int id;

    public Car(Semaphore slot, Parking parking, int id) {
        this.slot = slot;
        this.parking = parking;
        this.id = id;
    }

    public void parking() {
        System.out.println("Машина " + id + " припарковалась на парковке " + parking.getId());
    }

    public void unparking() {
        System.out.println("Машина " + id + " уехала с парковки " + parking.getId());
    }

    @Override
    public void run() {
        try {
            slot.acquire(); // занимаем слот
            parking();
            Thread.sleep(new Random().nextInt(300));
            slot.release(); // освобождаем слот
            unparking();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
