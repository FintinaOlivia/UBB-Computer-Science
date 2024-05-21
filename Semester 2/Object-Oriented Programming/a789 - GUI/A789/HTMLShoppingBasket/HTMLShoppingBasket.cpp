//
// Created by Th on 30/05/2023.
//

#include "HTMLShoppingBasket.h"
#include <fstream>
#include <windows.h>

void HTMLShoppingBasket::write() {
    std::ofstream outFile(this->FileName);
    outFile<<"<!DOCTYPE html>\n";
    outFile<<"<html>\n";
    outFile<<"<head>\n";
    outFile<<"\t<title>ShoppingBasket</title>\n";
    outFile<<"</head>\n";
    outFile<<"<body>\n";
    outFile<<"<table border=\"1\">\n";
    outFile<<"\t<tr>\n";
    outFile<<"\t\t<td><strong>SIZE</strong></td>\n";
    outFile<<"\t\t<td><strong>COLOR</strong></td>\n";
    outFile<<"\t\t<td><strong>PRICE</strong></td>\n";
    outFile<<"\t\t<td><strong>QUANTITY</strong></td>\n";
    outFile<<"\t\t<td><strong>PHOTOGRAPH</strong></td>\n";
    outFile<<"\t</tr>\n";
    for(auto CurrentElement: this->elements)
    {
        outFile<<"<tr>\n";
        outFile<<"\t<td>"<<CurrentElement.GetSize()<<"</td>\n";
        outFile<<"\t<td>"<<CurrentElement.GetColor()<<"</td>\n";
        outFile<<"\t<td>"<<CurrentElement.GetPrice()<<"</td>\n";
        outFile<<"\t<td>"<<CurrentElement.GetQuantity()<<"</td>\n";
        outFile<<"\t<td>"<<CurrentElement.GetPhotograph()<<"</td>\n";
        outFile<<"</tr>\n";
    }
    outFile<<"</table>\n";
    outFile<<"</body>\n";
    outFile<<"</html>\n";
}

void HTMLShoppingBasket::open() {
    std::ifstream  inFile(this->FileName);

    ShellExecute(nullptr, nullptr,
                 reinterpret_cast<LPCWSTR>(R"(C:\Users\Th\CLionProjects\A789\ShoppingBasket.html)"),
                 nullptr, nullptr, SW_SHOWNORMAL);
}


HTMLShoppingBasket::HTMLShoppingBasket() {
    this->FileName = R"(C:\Users\Th\CLionProjects\A789\ShoppingBasket.html)";
}

void HTMLShoppingBasket::set_data(std::vector<Coat> data) {
    this->elements = std::move(data);
}