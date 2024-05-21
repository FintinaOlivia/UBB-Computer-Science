//
// Created by Th on 30/05/2023.
//

#pragma once
#include <string>

class Validator
{
public:
    /// With this function we validate the color of the product
    /// \param color the color of the product
    /// \return returns true if the color is valid and false otherwise
    static bool validate_color_product(std::string color);

    /// With this function we validate the size of the product
    /// \param size the size of the product
    /// \return it returns true if the size is valid and false otherwise
    static bool validate_size_product(std::string size);

    /// With this function we validate the price of the product
    /// \param price the price of the product
    /// \return it returns the integer form of the price if it is valid or -1 otherwise
    static int validate_price_product(std::string price);

    /// With this function we validate the quantity of the product
    /// \param quantity the quantity of the product
    /// \return it returns the integer form of the quantity if it is valid and -1 otherwise
    static int validate_quantity_product(std::string quantity);

    /// With this function we validate the link of the photograph
    /// \param photograph the link to the photograph of the product
    /// \return it returns true if the link is valid and false otherwise
    static bool validate_photograph_product(std::string photograph);
};