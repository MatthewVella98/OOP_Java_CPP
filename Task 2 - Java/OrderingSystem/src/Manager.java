/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.List;


public class Manager {
    private List<Observer> observers = new ArrayList<Observer>();  //List of observers
    private double total;

    private String highestRestaurant;
    private double highest_price = 0;

    public void attach(Observer observer) {   //Adding an observer
        this.observers.add(observer);
    }

    private void calculatePrice(Observer order) {
        Restaurant restaurant = RestaurantManager.restaurant_manager.get(order.getRestaurantName());
        List<String> items = order.getItems();
        double total_price = 0;
        for (String item : items) {   //For each item in items, price is calculated
            double price = restaurant.getPrice(item);
            if (price != -1) {
                total_price += price;    //Total_price = accumulated price
            }
        }
        order.total(total_price);   //Total price is set
    }

    public void processAllOrders() {
        for (Observer order : observers) {   //Foreach order, the price is calculated
            calculatePrice(order);
        }
        for (Observer order : observers) {  //For all orders, total price is set
            total += order.getTotal();
        }
    }

    public double getTotal() {     //Total price is returned
        return total;
    }

    //find restaurant with highest revenue
    public void getHighestRevenue() {
        for (Observer order : observers) {    //For all orders, Total price is calculcated
            double total = order.getTotal();
            if (highest_price < total) {      //The highest priced order is saved in highest_price
                highest_price = total;
                highestRestaurant = order.getRestaurantName();   //The name of the restaurant with the highest order
            }
        }
    }

    public double getHighestPrice() {       //Highest priced order is returned
        return highest_price;
    }

    public String getHighestRestaurant() {     //Highest priced restaurant is returned
        return highestRestaurant;
    }
}
