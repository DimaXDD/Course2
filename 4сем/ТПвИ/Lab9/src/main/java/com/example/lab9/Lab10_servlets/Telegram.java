package com.example.lab9.Lab10_servlets;

public class Telegram {
    public String Title;
    public String Admin;
    public String Genre;
    public int Subscribers;

    public Telegram(String title, String admin, String genre, int subscribers) {
        Title = title;
        Admin = admin;
        Genre = genre;
        Subscribers = subscribers;
    }

    public String getTitle() {
        return Title;
    }

    public void setTitle(String title) {
        Title = title;
    }

    public String getAdmin() {
        return Admin;
    }

    public void setAdmin(String admin) {
        Admin = admin;
    }

    public String getGenre() {
        return Genre;
    }

    public void setGenre(String genre) {
        Genre = genre;
    }

    public int getSubscribers() {
        return Subscribers;
    }

    public void setSubscribers(int subscribers) {
        Subscribers = subscribers;
    }

}
