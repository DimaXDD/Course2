package com.example.lab10.classes;

public class Telegram {
    private int id;
    private String name;
    private String category;
    private Integer subs;

    public Telegram() { }

    public Telegram(int id, String name, String category, Integer subs) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.subs = subs;
    }
    //Getters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getCategory() {
        return category;
    }

    public Integer getSubs() {
        return subs;
    }
    //Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void setSubs(Integer subs) {
        this.subs = subs;
    }
}

