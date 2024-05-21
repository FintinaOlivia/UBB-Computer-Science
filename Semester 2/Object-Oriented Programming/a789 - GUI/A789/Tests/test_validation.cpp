//
// Created by Th on 31/05/2023.
//

#include "test_validation.h"
#include "../Validation/validation.h"
#include <string>
#include <cassert>

using namespace std;

void Test_Validation::test_validate_color_product() {
    Validator* validator = new Validator();
    string color = "Blue";
    string color2 = "16Pinksa1";
    assert(validator->validate_color_product(color));
    assert(!validator->validate_color_product(color2));
    delete validator;

}

void Test_Validation::test_validate_size_product() {
    Validator* validator = new Validator();
    assert(validator->validate_size_product("L"));
    assert(!validator->validate_size_product("small"));
    delete validator;
}

void Test_Validation::test_validate_price_product() {
    Validator* validator = new Validator();
    assert(validator->validate_price_product("100") == 100);
    assert(validator->validate_price_product("16gs") == -1);
    delete validator;
}

void Test_Validation::test_validate_quantity_product() {
    Validator* validator = new Validator();
    assert(validator->validate_quantity_product("145sgahj") == -1);
    assert(validator->validate_quantity_product("100") == 100);
    delete validator;
}

void Test_Validation::test_validate_photograph_product() {
    Validator* validator = new Validator();
    assert(!validator->validate_photograph_product("safgh"));
    assert(!validator->validate_photograph_product("saghsajdgfgahjkhgahj"));
    assert(!validator->validate_photograph_product("https://sagsahjksahsagfgsahj"));
    assert(validator->validate_photograph_product("https://sagahj.jpg"));
    delete validator;
}

void Test_Validation::TestAllValidation() {
    test_validate_color_product();
    test_validate_size_product();
    test_validate_price_product();
    test_validate_photograph_product();
    test_validate_quantity_product();
}