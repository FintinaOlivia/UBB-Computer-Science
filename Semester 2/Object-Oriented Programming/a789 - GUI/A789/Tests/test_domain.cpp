//
// Created by Th on 31/05/2023.
//

#include "test_domain.h"


using namespace std;
#include "test_domain.h"
#include "../Domain/domain.h"
#include <cassert>

void Test_Domain::TestSetQuantity() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    c.SetQuantity(999);
    assert(c.GetQuantity() == 999);
}

void Test_Domain::TestSetPrice() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    c.SetPrice(999);
    assert(c.GetPrice() == 999);

}

void Test_Domain::TestGetSize() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    assert(c.GetSize() == "XL");
}

void Test_Domain::TestGetColor() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    assert(c.GetColor() == "Pink");
}

void Test_Domain::TestGetPrice() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    assert(c.GetPrice() == 100);
}

void Test_Domain::TestGetQuantity() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    assert(c.GetQuantity() == 10);
}

void Test_Domain::TestGetPhotograph() {
    Coat c("XL", "Pink", 100, 10, "https://asgh.jpg/asgh");
    assert(c.GetPhotograph() == "https://asgh.jpg/asgh");
}

void Test_Domain::TestAllDomain() {
    TestGetColor();
    TestGetPhotograph();
    TestGetPrice();
    TestGetQuantity();
    TestGetSize();
    TestSetPrice();
    TestSetQuantity();

}