/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.List;

public abstract class Observer {
    protected Manager manager;

    public abstract void total(double price);     //to store total price for each order

    public abstract List<String> getItems();      // to get all food items

    public abstract double getTotal();            //get total price

    public abstract String getRestaurantName();    //get restaurant name
}
