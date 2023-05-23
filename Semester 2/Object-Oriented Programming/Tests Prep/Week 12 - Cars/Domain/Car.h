

#include <string>

class Car {
private:
    std::string manufacturer;
    std::string model;
    int yearOfFabrication;
    std::string colour;

public:
    Car();
    Car(std::string manufacturer, std::string model, int yearOfFabrication, std::string colour);
    ~Car();
    std::string getManufacturer();
    std::string getModel();
    int getYearOfFabrication();
    std::string getColour();
    std::string toString();

    bool operator==(const Car& car);
    friend std::istream& operator>>(std::istream& is, Car& car);
    friend std::ostream& operator<<(std::ostream& os, Car& car);
};