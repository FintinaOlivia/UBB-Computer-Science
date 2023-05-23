//
// Created by Th on 20/05/2023.
//

#ifndef W12_TEST_ATTEMPT_BILLS_BILL_H
#define W12_TEST_ATTEMPT_BILLS_BILL_H


#include <string>

class Bill {
private:
    std::string companyName;
    std::string code;
    double sum;
    bool isPaid;

public:
    Bill();
    Bill(std::string companyName, std::string code, double sum, bool isPaid);
    ~Bill();
    std::string getCompanyName();
    std::string getCode();
    double getSum();
    bool getIsPaid();
    bool operator==(const Bill& bill);
    friend std::istream& operator>>(std::istream& is, Bill& bill);
    friend std::ostream& operator<<(std::ostream& os, Bill& bill);

};


#endif //W12_TEST_ATTEMPT_BILLS_BILL_H
