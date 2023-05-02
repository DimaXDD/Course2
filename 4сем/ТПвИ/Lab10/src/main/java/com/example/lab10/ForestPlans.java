package com.example.lab10;

public class ForestPlans {
    private int id;
    private String type;
    private String name;
    public void setId(int id)
    {
        this.id = id;
    }
    public int getId()
    {
        return this.id;
    }
    public void setType(String type)
    {
        this.type = type;
    }
    public String getType()
    {
        return type;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public String getName()
    {
        return name;
    }
    public ForestPlans(int id, String type, String name) {
        this.id = id;
        this.type = type;
        this.name = name;
    }


}
