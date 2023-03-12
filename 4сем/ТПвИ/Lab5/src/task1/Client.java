package task1;

public class Client implements Runnable{
    private final static int WAITING_TIME = 200;
    private final int id;
    private final CallCenter callCenter;

    public Client(CallCenter callCenter, int id) {
        this.callCenter = callCenter;
        this.id = id;
    }

    public int getId() {
        return id;
    }

    @Override
    public void run() {
        Operator operator = null;
        try {
            while (operator == null) {
                System.out.println("Клиент " + id + " пытается позвонить");
                operator = callCenter.tryCall(this, WAITING_TIME);
            }
            System.out.println("Клиент " + id + " позвонил оператору " + operator.getId());
            operator.talk();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (operator != null) {
                System.out.println("Клиент " + id + " завершил разговор с оператором " + operator.getId());
                callCenter.endCall(operator);
            }
        }
    }
}
