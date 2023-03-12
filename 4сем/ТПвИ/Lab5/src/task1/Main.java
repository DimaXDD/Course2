package task1;

import java.util.ArrayList;

public class Main {
    private final static int NUMBER_OF_OPERATORS = 2;
    private final static int NUMBER_OF_CLIENTS = 5;

    public static void main(String[] args) {
        ArrayList<Operator> operators = new ArrayList<>();
        for (int i = 1; i <= NUMBER_OF_OPERATORS; i++) {
            operators.add(new Operator(i));
        }

        CallCenter callCenter = new CallCenter(operators);
        for (int i = 1; i <= NUMBER_OF_CLIENTS; i++) {
            Thread thread = new Thread(new Client(callCenter, i));
            thread.start();
        }
    }
}