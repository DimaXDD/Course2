package entities;

public class telegram {

    private String name;
    private String category;
    private Integer subs;

    public telegram(String name, String category, Integer subs) {
        this.name = name;
        this.category = category;
        this.subs = subs;
    }

    public telegram() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public Integer getSubs() {
        return subs;
    }

    public void setSubs(Integer subs) {
        this.subs = subs;
    }
}