//
// Created by Th on 30/05/2023.
//

#include <cstring>
#include "repository.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Repository::Repository() {
}

void Repository::AddRepo(std::string size, std::string color, int price, int quantity, std::string photograph) {
    int position;
    position = CheckExistenceCoat(size, color, photograph);
    if(position == -1)
    {
        Coat c(size, color, price, quantity, photograph);
        this->elements.push_back(c);
    }
    else
        throw ExceptionsRepository("The given product already exists!");
}

int Repository::CheckExistenceCoat(std::string size, std::string color, std::string photograph) {

    for(int i = 0; i < this->elements.size(); i++)
//        if(elements[i].GetSize() == size && elements[i].GetColor() == color &&
//        elements[i].GetPhotograph() == photograph)
        if(elements[i].GetColor() == color)
            return i;
    return -1;
}

const std::vector<Coat>& Repository::getArray() {
    return this->elements;
}

int Repository::GetSize() {
    return this->elements.size();
}

void Repository::init_repository() {
    AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    AddRepo("L", "Red", 150, 5,
            "https://res.cloudinary.com/wolfandbadger/image/upload/s--6lJSlYAP--/q_auto:eco/products/f8mgtgse6mnpsegyxrxo");
    AddRepo("S", "Pink", 200, 3, "https://images-na.ssl-images-amazon.com/images/I/71IismvKi3L._AC_UL1447_.jpg");
    AddRepo("S", "Yellow", 175, 10, "https://i.pinimg.com/originals/36/34/57/363457f4a8f758c43fab554e04de1038.jpg");
    AddRepo("M", "Orange", 242, 2, "https://n.nordstrommedia.com/ImageGallery/store/product/Zoom/10/_107638010.jpg?h=365&w=240&dpr=2");
    AddRepo("L", "Black", 305, 2, "https://media.mauvetree.com/wp-content/uploads/2018/04/Black-trench-coat-for-men.jpg");
    AddRepo("XL", "Grey", 100, 4, "https://cdn.shopify.com/s/files/1/0024/0697/3485/products/407A7456.jpg?v=1604310704");
    AddRepo("XS", "Magenta", 400, 1, "https://i.pinimg.com/originals/6e/b1/a9/6eb1a9282acc0aeef06dd693ae0301d9.jpg");
    AddRepo("XS", "Green", 135, 3, "https://i.etsystatic.com/6811060/r/il/f9e28e/1977783236/il_570xN.1977783236_4xx9.jpg");
    AddRepo("XL", "Purple", 243, 10, "https://images-na.ssl-images-amazon.com/images/I/51W49L9WQ8L._AC_UX385_.jpg");

}

void Repository::DeleteEntireProductRepo(std::string size, std::string color, std::string photograph) {
    int position;
    position = CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        this->elements.erase(this->elements.begin() + position);
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}

void Repository::DeleteSoldOutProductRepo(std::string size, std::string color, std::string photograph) {
    int position;
    position = CheckExistenceCoat(size, color, photograph);
    int quantity  = this->elements[position].GetQuantity();
    if(position != -1 && quantity == 0)
    {
        this->elements.erase(this->elements.begin() + position);
    }
    else
        throw ExceptionsRepository("The given product isn't sold out or it doesn't exist!");
}

void Repository::UpdateQuantityRepo(std::string size, std::string color, std::string photograph, int quantity) {
    int position;
    position = CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        double price = this->elements[position].GetPrice();
        Coat c(size, color, price, quantity, photograph);
        this->elements[position] = c;
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}

void Repository::UpdatePriceRepo(std::string size, std::string color, std::string photograph, int price) {
    int position;
    position = CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        int quantity = this->elements[position].GetQuantity();
        Coat c(size, color, price, quantity, photograph);
        this->elements[position] = c;
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}
