//
// Created by Th on 30/05/2023.
//

#pragma once
#include <cstdlib>
#include "../Domain/domain.h"
#include <vector>

class Repository
{
protected:
    std::vector<Coat> elements;

public:

    void init_repository();
    virtual int GetSize() ;
    virtual const std::vector<Coat>& getArray();

    Repository();

    virtual void AddRepo(std::string size, std::string color, int price, int quantity, std::string photograph);
    virtual int CheckExistenceCoat(std::string size, std::string color, std::string photograph);
    virtual void DeleteEntireProductRepo(std::string size, std::string color, std::string photograph);
    virtual void DeleteSoldOutProductRepo(std::string size, std::string color, std::string photograph);
    virtual void UpdatePriceRepo(std::string size, std::string color, std::string photograph, int price);
    virtual void UpdateQuantityRepo(std::string size, std::string color, std::string photograph, int quantity);

};