/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Map;
import java.util.LinkedHashMap;


public class Restaurant {
    private String name; // Restaurant name
    private String type; // type <Delivery|take away|both>
    private Map<String, Double> items; // restaurant items <food name, price>

    public Restaurant() {
        items = new LinkedHashMap<String, Double>();  //items is linked hash map
    }

    public void setItems(String name, double price) {     //items are stored in linked hash map

        items.put(name, price);
    }

    public void setName(String name) {                   //name is set
        this.name = name;
    }

    public void setType(String type) {                   //type is set
        this.type = type;
    }

    public String getName() {                           //Name is returned
        return name;
    }

    public String getType() {                          //Type is returned
        return type;
    }

    public double getPrice(String item) {            //Calculates price for a particular item
        if (items.containsKey(item)) {
            return items.get(item);
        } else return -1; //item not found
    }
}
