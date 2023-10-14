package view;

import controller.Controller;
import module.Cube;
import module.Cylinder;
import module.Object;
import module.Sphere;

import java.util.List;
import java.util.Scanner;

public class View {
    Controller controller;

    public View(Controller ctrl){
        this.controller = ctrl;
    }

    public View() {
        this.controller = new Controller();
    }

    public void printMenu(){
        System.out.println("Welcome to the geometric visualization app!");
        System.out.println("Please choose an option:");

        System.out.println("1 - Display All");
        System.out.println("2 - Add Item");
        System.out.println("3 - Filter By Volume");
        System.out.println("4 - Remove Item");
        System.out.println("0 - exit");
    }

    public void run(){

        //Populating list with some items
        this.controller.addItem(new Cube(10));
        this.controller.addItem(new Sphere(5));
        this.controller.addItem(new Cylinder(10));
        this.controller.addItem(new Cube(2));

        while(true){
            printMenu();

            Scanner scanner = new Scanner(System.in);
            String option = scanner.nextLine();

            switch(option) {
                case "0":
                    System.exit(0);
                    break;

                case "1":
                    //System.out.println("The Items are: ");
                    int count = 0;
                    for(Object i : this.controller.getAll())
                        System.out.println(++count + " " + i.toString());
                    if(count == 0)
                        System.out.println("No items to display!");
                    break;

                case "2":
                    System.out.println("Please specify the type of the item (cube/sphere/cylinder): ");
                    String type = scanner.nextLine();

                    if(!type.equals("cube") && !type.equals("sphere") && !type.equals("cylinder")){
                        System.out.println("Invalid type!");
                        break;
                    }

                    System.out.println("Please specify the edge of the item: ");
                    float edge = Float.parseFloat(scanner.nextLine());

                    try {
                        if(type.equals("cube"))
                            this.controller.addItem(new Cube(edge));
                        else if(type.equals("sphere"))
                            this.controller.addItem(new Sphere(edge));
                        else this.controller.addItem(new Cylinder(edge));
                    } catch (Exception e) {
                        System.out.println("Invalid type!");
                    }
                    break;

                case "3":
                    if(this.controller.getAll().isEmpty()){
                        System.out.println("No items to display!");
                        break;
                    }
                    System.out.println("Please specify the filtering volume: ");
                    float volume = Float.parseFloat(scanner.nextLine());
                    List<Object> filteredItems = this.controller.filter(volume);

                    System.out.println("Filtering... ");
                    for(Object i : filteredItems)
                        System.out.println(i.toString());

                    if(filteredItems.isEmpty())
                        System.out.println("No items to display!");

                    break;

                case "4":
                    System.out.println("Please specify the index of the item to be removed: ");
                    int index = Integer.parseInt(scanner.nextLine());

                    Object itemToRemove = null;
                    try {
                        itemToRemove = this.controller.getAll().get(index - 1);
                        this.controller.removeItem(itemToRemove);
                    } catch (Exception e) {
                        System.out.println("Invalid index!");
                    }
                    System.out.println("Item removed!");
                    break;
            }
        }
    }
}
