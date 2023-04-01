import org.testng.annotations.*;

import static org.testng.Assert.*;

public class TestCompany {
    private Company testCompany;
    private Employee testEmployee1;
    private Employee testEmployee2;

    @BeforeMethod
    public void setUp() {
        testCompany = new Company();
        testEmployee1 = new Employee("Dima", 10, true);
        testEmployee2 = new Employee("Ilya", 2, false);
    }

    @AfterSuite
    public void End() {
        testCompany = null;
        testEmployee1 = null;
        testEmployee2 = null;
        System.out.println("Тест закончен!");
    }

    @Test (enabled = false) // enabled = false - тест не будет запущен
    public void addNewEmployee() {
        testCompany.addNewEmployee(testEmployee1);
        assertTrue(testCompany.arrEmpl.contains(testEmployee1));
    }

    @Test(timeOut = 1100)
    public void removeEmployee() throws InterruptedException {
        testCompany.arrEmpl.add(testEmployee1);
        testCompany.removeEmployee(testEmployee1);
        Thread.sleep(1000); // эмуляция затраты времения для тайм аута
        assertFalse(testCompany.arrEmpl.contains(testEmployee1));
    }

    @Test
    public void removeNonexistentEmployee() {
        testCompany.removeEmployee(testEmployee1);
        assertFalse(testCompany.arrEmpl.contains(testEmployee1));
    }


    @Test
    public void testGetAllEmployee() {
        testCompany.addNewEmployee(testEmployee1);
        // testCompany.addNewEmployee(testEmployee2);
        String str = "Dima 10 true \n";
        assertEquals(str, testCompany.getAllEmployee());
    }
}
