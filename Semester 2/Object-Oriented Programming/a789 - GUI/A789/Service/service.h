//
// Created by Th on 30/05/2023.
//

#pragma once
#include <cstdlib>
#include <algorithm>
#include "../Domain/domain.h"
#include "../Repository/repository.h"

class Service
{
private:
    Repository& repository;
    Repository& user_repository;
    int total_price;
public:

///Construct
//Service();
///Destructor
//~Service();

    [[nodiscard]] int GetTotalPrice() const;

    Service(Repository& repository, Repository& user_repository);

    int AddUserService(Coat coat, Coat cUser);

    void AddService(std::string size, std::string color, int price, int quantity, std::string photograph);

    const std::vector<Coat>& GetRepository();

    std::vector<Coat> GetFilteredRepository(std::string size);

    std::vector<Coat> GetUserRepository();

    void DeleteService(const std::string& size, const std::string& color, const std::string& photograph, int criteria);

    void UpdatePriceService(std::string size, std::string color, std::string photograph, int price);

    void UpdateQuantityService(std::string size, std::string color, std::string photograph, int quantity);

    int GetSize();


};