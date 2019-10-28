import java.io.*;

public class FoodOrderSystem {

    Restaurant restaurant;
    Order order;

    Manager manager = new Manager();

    private void parserFile(String filename) throws Exception {
        File inputFile = new File(filename);

        //If input file doesn't exist
        if (!inputFile.exists()) {
            output("Input File is not exist !");
            return;
        }

        //If exists, file is read
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        String line = null;

        while ((line = reader.readLine()) != null) {
            if (line.startsWith("BeginRestaurant")) {   //If Token = BeginRestaurant
                restaurant = new Restaurant();
                String[] split = line.split(" ");
                String restName = split[1].trim();  //First string = restName
                String typeName = split[2].trim();  //Second string - typeName
                restaurant.setName(restName);
                restaurant.setType(typeName);
                RestaurantManager.restaurant_manager.put(restName, restaurant); //Saves Restaurant in LinkedHashMap
            }

            if (line.startsWith("Item")) {             //If Token = Item
                String[] split = line.split(" ");
                String foodName = split[1].trim();
                double price = Double.parseDouble(split[2].trim());
                restaurant.setItems(foodName, price);
            }

            if (line.startsWith("BeginOrderList")) {   //If Token = BeginOrderList
                continue;
            }

            if (line.startsWith("BeginOrder")) {       //If Token = BeginOrder
                order = new Order(manager);
                String[] split = line.split(" ");
                String restName = split[1].trim();
                String typeName = split[2].trim();
                order.setRestaurantName(restName);     //Set restName and typeName for order
                order.setType(typeName);
            }

            if (line.startsWith("OrderItem")) {       //Token = OrderItem
                String[] split = line.split(" ");
                String foodName = split[1].trim();
                order.addFood(foodName);          //Add food in CustomLinkedList
            }
        }
    }

    public void output(String str) {

        System.out.println(str);
    }

    public void menu() {
        output("|||||||||||||||||||||||||||||||||||||||||||||||");
        output("||                                           ||");
        output("||            Food Ordering System           ||");
        output("||                                           ||");
        output("|||||||||||||||||||||||||||||||||||||||||||||||");

    }

    public void startSystem(String testFile) {
        menu();  //Menu

        try {      //Try to open the text file
            parserFile("test.txt");
        } catch (Exception e) {
            e.printStackTrace();
        }

        //If successful
        manager.processAllOrders();
        manager.getHighestRevenue();

        double total = manager.getTotal();
        double highestPrice = manager.getHighestPrice();
        String highestRestaurant = manager.getHighestRestaurant();

        //Printing Results
        output("Total Price : " + total + "$");
        output("Restaurant with highest revenue : " + highestRestaurant);
        output("Highest Total Price : " + highestPrice + "$");

        //Writes output in Receipt.txt
        try (Writer writer = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream("Receipt.txt"), "utf-8"))){
            writer.write("Total price: " +total + "$\n");
            ((BufferedWriter) writer).newLine();
             writer.write("Restaurant with highest revenue: " +highestRestaurant);
             ((BufferedWriter) writer).newLine();
             writer.write("Highest total price: " +highestPrice + "$");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        //No arguments for test file
        if (args.length != 1) {
            System.out.println("No test file was inputted.");
            return;
        }

        //Text file doesn't exist
        if (!new File(args[0]).exists()) {
            System.out.println("Test file does not exist.");
            return;
        }

        //If successful, system starts
        new FoodOrderSystem().startSystem(args[0]);
    }
}
