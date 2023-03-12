package task1;

import java.util.ArrayList;

public class CallCenter {
    private final static int ATTEMPTS = 5; // число попыток
    ArrayList<Operator> operators;

    public CallCenter(ArrayList<Operator> operators) {
        this.operators = operators;
    }

    public synchronized Operator tryCall(Client client, int waitingTime) {
        int attempts = 0;
        boolean success = false; // флаг успешного звонка

        while (!success) {
            for (var operator : operators) {
                if (searchFreeOperator(operator, client)) {
                    return operator;
                }
            }

            if (!success) {
                try {
                    attempts++;
                    if (checkAttempts(attempts, waitingTime, client)) {
                        return null;
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        return null;
    }

    public synchronized void endCall(Operator operator) { // завершение разговора
        operator.setClient(null); // удаляем клиента у оператора
        operators.add(operator); // добавляем оператора в список свободных операторов
        notify(); // уведомляем о завершении разговора
    }

    public synchronized boolean checkAttempts(int attempts, int waitingTime, Client client) throws InterruptedException {
        if (attempts == ATTEMPTS) {
            System.out.println("Клиент " + client.getId() + " не дождался свободного оператора");
            wait(waitingTime);
            return true;
        } else {
            System.out.println("Клиент " + client.getId() + " ждет свободного оператора");
            wait(waitingTime);
        }
        return false;
    }

    private boolean searchFreeOperator(Operator operator, Client client) { // поиск свободного оператора
        if (operator.getClient() == null) {
            operator.setClient(client);
            operators.remove(operator); // удаляем оператора из списка свободных операторов
            return true;
        }
        return false;
    }
}
