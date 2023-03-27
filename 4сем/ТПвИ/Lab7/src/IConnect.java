import java.sql.Connection;
import java.util.ArrayList;
public interface IConnect {
    public ArrayList<String> getProperties();
    public Boolean getConnection();
    public void closeConnection();
}
