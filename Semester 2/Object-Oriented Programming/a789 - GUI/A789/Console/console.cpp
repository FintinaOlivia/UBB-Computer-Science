//
// Created by Th on 30/05/2023.
//

#include "console.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "../CSVShoppingBasket/CSVShoppingBasket.h"
#include "../HTMLShoppingBasket/HTMLShoppingBasket.h"
#include <algorithm>
#include "../Exceptions/Exceptions.h"

Console::Console(Service& service):
        service{service}
{

}

void Console::AddAdminConsole() {
    std::string size;
    std::string color;
    std::string str_price;
    int price;
    std::string str_quantity;
    int quantity;
    std::string photograph;
    std::cout<<"Type in the size: ";
    std::cin>>size;
    std::cout<<"\nType in the color: ";
//    std::cin>>color;
    std::cin.ignore();
    getline(std::cin, color);
    std::cout<<"\nType in the price: ";
    std::cin>>str_price;
    std::cout<<"\nType in the quantity: ";
    std::cin>>str_quantity;
    std::cout<<"\nType in the photograph: ";
    std::cin>>photograph;
    price = Validator::validate_price_product(str_price);
    quantity = Validator::validate_quantity_product(str_quantity);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) || price == -1
       || quantity == -1 || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.AddService(size, color, price, quantity, photograph);
        std::cout<<"The product was added successfully!\n";
    }
}

void Console::DisplayProductsAdmin() {

    int count=0;
    for(const auto& i: this->service.GetRepository())
    {
        std::cout << count + 1 << ")  ""Size: " << i.GetSize() << " Color: " << i.GetColor() << " Price: " << i.GetPrice()
             << " Quantity: " << i.GetQuantity() << "\nLink Photo: "
             << i.GetPhotograph() << "\n" << "\n";
        count++;
    }
}


void Console::UpdateProductsPriceAdmin() {
    std::string size;
    std::string color;
    std::string str_price;
    int price;
    std::string photograph;
    std::cout<<"Type in the size: ";
    std::cin>>size;
    std::cout<<"\nType in the color: ";
    std::cin.ignore();
    std::cin>>color;
    std::cout<<"\nType in the price: ";
    std::cin>>str_price;
    std::cout<<"\nType in the photograph: ";
    std::cin.ignore();
    std::cin>>photograph;
    price = Validator::validate_price_product(str_price);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) || price == -1
       || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.UpdatePriceService(size, color, photograph, price);
        std::cout<<"The product was updated successfully!\n";
    }

}

void Console::UpdateProductsQuantityAdmin() {
    std::string size;
    std::string color;
    std::string str_quantity;
    int quantity;
    std::string photograph;
    std::cout<<"Type in the size: ";
    std::cin>>size;
    std::cout<<"\nType in the color: ";
    std::cin.ignore();
    std::cin>>color;
    std::cout<<"\nType in the quantity: ";
    std::cin>>str_quantity;
    std::cout<<"\nType in the photograph: ";
    std::cin.ignore();
    std::cin>>photograph;
    quantity = Validator::validate_quantity_product(str_quantity);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       quantity == -1 || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.UpdateQuantityService(size, color, photograph, quantity);
        std::cout<<"The product was updated successfully!\n";
    }
}

void Console::DeleteSoldOutProductAdmin() {
    std::string size;
    std::string color;
    std::string photograph;
    std::cout<<"Type in the size: ";
    std::cin>>size;
    std::cout<<"\nType in the color: ";
    std::cin>>color;
    std::cout<<"\nType in the photograph: ";
    std::cin>>photograph;

    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.DeleteService(size, color, photograph, 2);
        std::cout<<"The product was deleted successfully!\n";
    }
}

void Console::DeleteEntireProductAdmin() {
    std::string size;
    std::string color;
    std::string photograph;
    std::cout<<"Type in the size: ";
    std::cin>>size;
    std::cout<<"\nType in the color: ";
    std::cin>>color;
    std::cout<<"\nType in the photograph: ";
    std::cin>>photograph;
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.DeleteService(size, color, photograph, 1);
        std::cout<<"The product was deleted successfully!\n";
    }
}

void Console::MenuAdminMode() {

    std::cout<<"Type 1 for adding a product!\n";
    std::cout<<"Type 2 for displaying the products!\n";
    std::cout<<"Type 3 for deleting a product!\n";
    std::cout<<"Type 4 for deleting a sold out product!\n";
    std::cout<<"Type 5 for updating the price of a product!\n";
    std::cout<<"Type 6 for updating the quantity of a product!\n";
    std::cout<<"Type H for displaying the menu!\n";
    std::cout<<"Type E in order to exit the program!\n";
}

void Console::AdministratorMode() {
    bool Administrator_Mode = false;
    MenuAdminMode();
    while(!Administrator_Mode) {
        try{
            std::string command;
            std::cout << "\nCommand> ";
            std::cin >> command;
            if (command != "1" && command != "2" && command != "3" && command != "4" && command != "5" && command != "6" &&
                command != "E" && command != "H")
                std::cout << "Invalid command!\n";
            else
                switch (command[0]) {

                    case '1':
                        AddAdminConsole();
                        break;

                    case '2':
                        DisplayProductsAdmin();
                        break;

                    case '3':
                        DeleteEntireProductAdmin();
                        break;

                    case '4':
                        DeleteSoldOutProductAdmin();
                        break;

                    case '5':
                        UpdateProductsPriceAdmin();
                        break;

                    case '6':
                        UpdateProductsQuantityAdmin();
                        break;

                    case 'H':
                        MenuAdminMode();
                        break;

                    case 'E':
                        Administrator_Mode = true;
                        break;
                }
        }
        catch(ExceptionsValidator& message)
        {
            std::cout<<message.what();
        }
        catch(ExceptionsRepository& message)
        {
            std::cout<<message.what();
        }
    }
}

void MenuUserMode()
{
    std::cout<<"Type 1 for buying products!\n";
    std::cout<<"Type 2 for displaying the shopping basket!\n";
    std::cout<<"Type 3 for opening the application!\n";
    std::cout<<"Type E for exit!\n";
}

int Console::DisplayProductsUser() {
    int i = 0;
    if(i < this->service.GetSize())
    {
        std::cout<<"Size: "<<this->service.GetRepository()[i].GetSize()<<" Color: " <<
            this->service.GetRepository()[i].GetColor() << " Price: " << this->service.GetRepository()[i].GetPrice()
            <<" Quantity: " << this->service.GetRepository()[i].GetQuantity()<<"\nLink Photo: "
            << this->service.GetRepository()[i].GetPhotograph()<<"\n"<<"\n";
        ShellExecute(nullptr, reinterpret_cast<LPCWSTR>("open"),
                     reinterpret_cast<LPCWSTR>(this->service.GetRepository()[i].GetPhotograph().c_str()), nullptr, nullptr, SW_SHOWNORMAL);
        std::cout << "Buy, go Next or go Pay\n";
        while(i < this->service.GetSize())
        {
            std::string command;
            std::cout<<"\nCommand> ";
            std::cin>>command;
            if(command != "Buy" && command != "Next" && command != "Pay")
                std::cout<<"Invalid command!";
            else
            {
                if(command == "Buy")
                {
                    this->service.UpdateQuantityService(this->service.GetRepository()[i].GetSize(),
                                                        this->service.GetRepository()[i].GetColor(), this->service.GetRepository()[i].GetPhotograph(),
                                                        this->service.GetRepository()[i].GetQuantity() - 1);
                    Coat c(this->service.GetRepository()[i].GetSize(),this->service.GetRepository()[i].GetColor(),
                           this->service.GetRepository()[i].GetPrice(), 1, this->service.GetRepository()[i].GetPhotograph());
                    if( this->service.AddUserService(this->service.GetRepository()[i], c) == 1)
//                        i--;
                        std::cout << "Buy, go Next or go Pay\n";
                }
                if(command == "Next")
                {
                    i++;
                    if(i < this->service.GetSize()) {
                        std::cout << "Size: " << this->service.GetRepository()[i].GetSize() << " Color: " <<
                             this->service.GetRepository()[i].GetColor() << " Price: "
                             << this->service.GetRepository()[i].GetPrice()
                             << " Quantity: " << this->service.GetRepository()[i].GetQuantity() << "\nLink Photo: "
                             << this->service.GetRepository()[i].GetPhotograph() << "\n" << "\n";
                        ShellExecute(nullptr, reinterpret_cast<LPCWSTR>("open"),
                                     reinterpret_cast<LPCWSTR>(this->service.GetRepository()[i].GetPhotograph().c_str()), nullptr,
                                     nullptr, SW_SHOWNORMAL);
                        std::cout << "Buy, go Next or go Pay\n";
                    }
                    else
                        return 0;
                }
                if(command == "Pay")
                {
                    return -1;
                }
            }
        }
    }
    return 1;
}

int Console::DisplayProductsUserWithSize(const std::string& size) {
    int i = 0;
    std::vector<Coat> elements(this->service.GetRepository().size());
    auto it = copy_if(this->service.GetRepository().begin(), this->service.GetRepository().end(), elements.begin(),
                      [size](const Coat& coat){ return coat.GetSize()==size;});
    elements.resize(it - elements.begin());
    int size1 = elements.size();
//    for(auto j: this->service.GetRepository())
//        if(j.GetSize() == size)
//            count++;
    if(!elements.empty())
    {
        if (i < elements.size())
        {
            std::cout << "Size: " << elements[i].GetSize() << " Color: " << elements[i].GetColor() << " Price: "
                 << elements[i].GetPrice()
                 << " Quantity: " << elements[i].GetQuantity() << "\nLink Photo: "
                 << elements[i].GetPhotograph() << "\n" << "\n";
            ShellExecute(NULL, reinterpret_cast<LPCWSTR>("open"),
                         reinterpret_cast<LPCWSTR>(elements[i].GetPhotograph().c_str()), NULL, NULL,
                         SW_SHOWNORMAL);
            std::cout << "Buy, go Next or go Pay\n";
            while (i < elements.size()) {

                std::string command;
                std::cout << "\nCommand> ";
                std::cin >> command;
                if (command != "Buy" && command != "Next" && command != "Pay")
                    std::cout << "Invalid command!";
                else {
                    if (command == "Buy") {
                        int new_quantity = elements[i].GetQuantity() - 1;
                        this->service.UpdateQuantityService(elements[i].GetSize(),
                                                            elements[i].GetColor(),
                                                            elements[i].GetPhotograph(),
                                                            new_quantity);
                        elements[i].SetQuantity(new_quantity);
                        Coat c(elements[i].GetSize(),
                               elements[i].GetColor(),
                               elements[i].GetPrice(), 1,
                               elements[i].GetPhotograph());
                        if(this->service.AddUserService(elements[i], c) == 1)
                            elements.erase(elements.begin() + i);
//                            i--;
                        std::cout << "Buy, go Next or go Pay\n";
                    }
                    if (command == "Next") {
                        i++;
                        if (i < elements.size())
                        {
                            std::cout << "Size: " << elements[i].GetSize() << " Color: " <<
                                 elements[i].GetColor() << " Price: "
                                 << elements[i].GetPrice()
                                 << " Quantity: " << elements[i].GetQuantity()
                                 << "\nLink Photo: "
                                 << elements[i].GetPhotograph() << "\n" << "\n";
                            ShellExecute(NULL, reinterpret_cast<LPCWSTR>("open"),
                                         reinterpret_cast<LPCWSTR>(elements[i].GetPhotograph().c_str()),
                                         NULL,
                                         NULL, SW_SHOWNORMAL);
                            std::cout << "Buy, go Next or go Pay\n";
                        }
                        else
                            return 0;
                    }
                    if (command == "Pay") {
                        return -1;
                    }
                }
            }
        }
        return 1;
    }
    return 2;
}

void Console::MenuDisplayProductsUser() {
    std::string size;
    int done = 0;
    if (this->service.GetSize() == 0)
        std::cout << "There are no products on stock!";
    else {
        std::cout << "Type in the size: ";
        std::cin.ignore();
        getline(std::cin, size);
        if (size != "S" && size != "M" && size != "XS" && size != "XL" && size != "XL" && !size.empty() && size != "XXL") {
            std::cout << "Invalid size!";
        } else {
            while (done == 0) {
                if (size.empty())
                    done = DisplayProductsUser();
                else
                    done = DisplayProductsUserWithSize(size);
            }

            if (done == 1)
                throw ExceptionsRepository("There are no products left on stock!");
            else if (done == 2)
                throw ExceptionsRepository("There are no products with the given size!");
        }
    }
    this->ASB->set_data(this->service.GetUserRepository());
    this->ASB->write();
}

void Console::DisplayShoppingBag() {
    int count=0;
    for(auto i: this->service.GetUserRepository()) {
        std::cout << count + 1 << ")  ""Size: " << i.GetSize() << " Color: " << i.GetColor() << " Price: "
             << i.GetPrice() << " Quantity: " << i.GetQuantity() << "\nLink Photo: "
             << i.GetPhotograph() << "\n" << "\n";
        count++;
    }
    std::cout << "Total price of the items: " << this->service.GetTotalPrice() << '\n';
}

void Console::OpenApplication()
{
    this->ASB->set_data(this->service.GetUserRepository());
    this->ASB->write();
    this->ASB->open();
}

void Console::UserMode() {
    bool User_Mode = false;

    while(!User_Mode)
    {
        try {
            std::string command;
            std::cout << '\n';
            MenuUserMode();
            std::cout << '\n';
            std::cin >> command;
            if (command != "1" && command != "2" && command != "3" && command != "E" && command != "H")
                std::cout << "Invalid command!\n";
            else
                switch (command[0]) {

                    case '1':
                        MenuDisplayProductsUser();
                        break;
                    case '2':
                        DisplayShoppingBag();
                        break;

                    case '3':
                        OpenApplication();
                        break;

                    case 'H':
                        MenuUserMode();
                        break;

                    case 'E':
                        User_Mode = true;
                        break;
                }
        }
        catch(ExceptionsRepository& message)
        {
            std::cout<<message.what();
        }
    }
}


void Console::Start() {

    bool Done = false;
    bool DoneChoosingFile = false;
    while(!DoneChoosingFile)
    {
        std::string FileType;
        std::cout<<"Type 1 for CSV file or type 2 for HTML file: ";
        std::cin>>FileType;
        if ( FileType != "1" && FileType != "2")
            std::cout << "Invalid file type!";
        else
            switch (FileType[0])
            {
                case '1':
                    this->ASB = new CSVShoppingBasket();
                    DoneChoosingFile = true;
                    break;
                case '2':
                    this->ASB = new HTMLShoppingBasket();
                    DoneChoosingFile = true;
                    break;
            }
    }
    while(!Done)
    {
        try {
            std::string command;
            std::cout << "Type 1 for Administrator Mode or type 2 for User Mode:  ";
            std::cin >> command;
            std::cout << '\n';
            if (command != "1" && command != "2" && command != "E")
                std::cout << "Invalid command!\n";
            else
                switch (command[0]) {
                    case '1':
                        AdministratorMode();
                        break;

                    case '2':
                        UserMode();
                        break;


                    case 'E':
                        Done = true;
                        delete this->ASB;
                        break;
                }
        }
        catch(ExceptionsValidator)
        {

        }
    }
}


