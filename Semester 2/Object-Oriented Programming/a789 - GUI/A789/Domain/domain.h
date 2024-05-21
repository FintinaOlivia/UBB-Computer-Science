//
// Created by Th on 30/05/2023.
//


#pragma once
#include <string>
#include <vector>

class Coat{
private:
    std::string size;
    std::string color;
    int price;
    int quantity;
    std::string photograph;

public:

/// Constructor
    Coat();

/// With this function we initialize the coat
/// \param size the size of the coat
/// \param color the color of the coat
/// \param price the price of the coat
/// \param quantity the quantity of the coat
/// \param photograph the link to the photograph of the coat
    Coat(std::string size, std::string color, int price, int quantity, std::string photograph);

//void SetSize(std::string size);

/// With this function we set the quantity of the coat
/// \param quantity the quantity we want to set
    void SetQuantity(int quantity);

/// With this function we set the price of the coat
/// \param price the price we want to set
    void SetPrice(int price);

/// With this function we get the size of the coat
/// \return returns the size of the coat
    const std::string& GetSize() const;

/// With this function we get the color of the coat
/// \return returns the color of the coat
    const std::string& GetColor() const;

/// With this function we get the price of the coat
/// \return returns the price of the coat
    const int& GetPrice() const;

/// With this function we get the quantity of the coat
/// \return returns the quantity of the goat
    int GetQuantity() const;

    static std::vector<std::string> tokenize(std::string str, char delimiter);

/// With this function we get the link to the photograph of the coat
/// \return returns the the link to the photograph of the coat
    [[nodiscard]] const std::string& GetPhotograph() const;

    friend std::ostream& operator<<(std::ostream&, const Coat&);

    friend std::istream& operator>>(std::istream&, Coat&);

    Coat& operator=(const Coat &coat);

};