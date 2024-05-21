//
// Created by Th on 30/05/2023.
//

#pragma once
#include <cstring>
#include "../Domain/domain.h"
#include "../AbstractShoppingBasket/AbstractShoppingBasket.h"
#include <vector>


class HTMLShoppingBasket: public AbstractShoppingBasket {
private:
    std::vector<Coat> elements;
    std::string FileName;

public:
    HTMLShoppingBasket();
    void write() override;
    void open() override;
    void set_data(std::vector<Coat> elements) override;
    ~HTMLShoppingBasket() override = default;

};

