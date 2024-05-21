//
// Created by Th on 30/05/2023.
//

#pragma once
#include "../Service/service.h"
#include "../Validation/validation.h"
#include "../AbstractShoppingBasket/AbstractShoppingBasket.h"
#include "../Service/service.h"

class Console
{
private:

    Service& service;
    AbstractShoppingBasket* ASB{};

public:

/// Constructor
    Console();

/// Destructor
    ~Console() = default;

    void Start();

    void OpenApplication();

    void AdministratorMode();

    void UserMode();

    void DisplayShoppingBag();

    static void MenuAdminMode();

    void UpdateProductsPriceAdmin();

    void UpdateProductsQuantityAdmin();

    void DeleteEntireProductAdmin();

    int DisplayProductsUser();

    int DisplayProductsUserWithSize(const std::string& size);

    void DeleteSoldOutProductAdmin();

    void MenuDisplayProductsUser();

    void DisplayProductsAdmin();

    void AddAdminConsole();

    Console(Service &service);
};