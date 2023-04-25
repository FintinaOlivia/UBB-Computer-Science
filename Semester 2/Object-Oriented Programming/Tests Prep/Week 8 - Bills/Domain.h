//
// Created by theo on 25.04.2023.
//

#ifndef WEEK_8___TEST_PREP_DOMAIN_H
#define WEEK_8___TEST_PREP_DOMAIN_H

#include <cstring>
#include <string>

class Bill{
private:
    std::string companyName;
    std::string serialNumber;
    double sum;
    bool isPaid;
public:
    Bill();
    Bill(std::string companyName, std::string serialNumber, double sum, bool isPaid);
    Bill(const Bill& bill);
    ~Bill();

    //Getters
    std::string getCompanyName();
    std::string getSerialNumber();
    double getSum();
    bool isBillPaid();

    //Setters
    void setCompanyName(std::string companyName);
    void setSerialNumber(std::string serialNumber);
    void setSum(double sum);
    void setIsPaid(bool isPaid);

    //__str__()
    std::string toString();

    //__eq__()
    bool equals(Bill bill);
};

#endif //WEEK_8___TEST_PREP_DOMAIN_H
