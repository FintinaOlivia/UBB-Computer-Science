//
// Created by Th on 30/05/2023.
//

#include "CSVShoppingBasket.h"
#include "../Domain/domain.h"
#include <string>
#include <fstream>
#include <windows.h>


void CSVShoppingBasket::write() {
    std::ofstream outFile(this->FileName);
    for(const auto& CurrentElement: this->elements)
    {
        outFile << CurrentElement.GetSize()<<','<<CurrentElement.GetColor()<<','<<CurrentElement.GetPrice()<<','
                <<CurrentElement.GetQuantity()<<','<<CurrentElement.GetPhotograph()<<'\n';
    }
    outFile.close();
    this->elements.clear();
}

void CSVShoppingBasket::open() {
    std::ifstream  inFile(this->FileName);

    ShellExecute(nullptr, nullptr,
                 reinterpret_cast<LPCWSTR>(R"(C:\Users\Th\CLionProjects\A789\ShoppingBasket.csv)"),
                 nullptr, nullptr, SW_SHOWNORMAL);
}

CSVShoppingBasket::CSVShoppingBasket() {
    this->FileName = R"(C:\Users\Th\CLionProjects\A789\ShoppingBasket.csv)";
}

void CSVShoppingBasket::set_data(std::vector<Coat> data) {
    this->elements = data;
}
