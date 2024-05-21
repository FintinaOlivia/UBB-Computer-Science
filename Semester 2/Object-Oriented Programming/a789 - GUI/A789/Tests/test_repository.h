//
// Created by Th on 31/05/2023.
//

#ifndef A789_TEST_REPOSITORY_H
#define A789_TEST_REPOSITORY_H

#include <cassert>
#include "../Repository/repository.h"

class Test_Repository {


public:
    void Test_init_repository();

    void TestGetSize();

    void TestAddRepo();

    void TestCheckExistenceCoat();

    void TestDeleteEntireProductRepo();

    void TestDeleteSoldOutProductRepo();

    void TestUpdatePriceRepo();

    void TestUpdateQuantityRepo();

    void TestAllRepository();
};



#endif //A789_TEST_REPOSITORY_H
