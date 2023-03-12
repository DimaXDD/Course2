package task2;

public class Parking {
    private final int id;
    private final int capacity;

    public Parking(int id, int capacity) {
        this.id = id;
        this.capacity = capacity;
    }

    public int getId() {
        return id;
    }

    public int getCapacity() {
        return capacity;
    }
}
