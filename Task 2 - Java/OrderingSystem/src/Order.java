/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.List;

public class Order extends Observer {
    private String RestaurantName; // Restaurant name
    private String type; // type <delivery|take away>
    private CustomLinkedList<String> items; // food items
    private double total_price;

    public Order(Manager manager) {                //it puts and observer for every order list
        items = new CustomLinkedList<String>();        //such that it does all the processing for all the orders
        this.manager = manager;
        this.manager.attach(this);
    }

    public void setRestaurantName(String name) {        //All setters and getters or Accessors and Mutators in the Class Below
        this.RestaurantName = name;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void addFood(String item) {
        items.add(item);
    }

    public String getType() {
        return type;
    }

    @Override
    public String getRestaurantName() {
        return RestaurantName;
    }


    @Override
    public List<String> getItems() {
        return items.toList();
    }

    @Override
    public void total(double price) {
        this.total_price = price;
    }

    @Override
    public double getTotal() {
        return total_price;
    }
}
