import java.util.ArrayList;

public class Company {
    public String nameCompany;
    public ArrayList<Employee> arrEmpl = new ArrayList<Employee>();

    public void addNewEmployee(Employee em)
    {
        arrEmpl.add(em);
    }

    public void removeEmployee(Employee em)
    {
        if(arrEmpl.contains(em)) {
            arrEmpl.remove(em);
        }
        else
        {
            System.out.println("Такого сотрудника нет!");
        }
    }

    public String getAllEmployee()
    {
        String sb = "";
        for (var a : arrEmpl) {
            sb += a.name + " ";
            sb += Integer.toString(a.yearExp) + " ";
            sb += Boolean.toString(a.education) + " ";
            sb += "\n";
        }
        return sb;
    }

    public void getEmployeeWithHigherEducation()
    {
        for (var a: arrEmpl) {
            if (a.education) {
                a.toString();
            }
        }
    }

    public void getEmployeeWithWorkExp(int exp)
    {
        for (var a: arrEmpl) {
            if (a.yearExp >= exp) {
                a.toString();
            }
        }
    }
}
