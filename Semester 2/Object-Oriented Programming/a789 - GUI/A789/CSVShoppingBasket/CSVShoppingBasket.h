//
// Created by Th on 30/05/2023.
//


#pragma once
#include <string>
#include <vector>
#include "../AbstractShoppingBasket/AbstractShoppingBasket.h"
#include "../Domain/domain.h"


class CSVShoppingBasket: public AbstractShoppingBasket {
private:
    std::vector<Coat> elements;
    std::string FileName;
public:
    CSVShoppingBasket();
    void write() override;
    void open() override;
    void set_data(std::vector<Coat> elements) override;
    ~CSVShoppingBasket() override = default;

};

