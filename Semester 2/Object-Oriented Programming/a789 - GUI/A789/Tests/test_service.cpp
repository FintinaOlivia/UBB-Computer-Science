
//
// Created by Th on 31/05/2023.
//

#include "test_service.h"
#include "../Repository/repository.h"
#include "../Service/service.h"
#include "../Exceptions/Exceptions.h"
#include <cassert>

void Test_Service::TestAddService() {
    Repository UserRepo;
    Repository repo;
    repo.init_repository();
    Service service(repo, UserRepo);
    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    try {
        service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
        assert(false);
    }
    catch(ExceptionsRepository&) {
        assert(true);
    }
}

void Test_Service::TestDeleteService() {
    Repository UserRepo;
    Repository repo;
    repo.init_repository();
    Service service(repo, UserRepo);

    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    service.DeleteService("XL", "Pink", "https://abcd.com", 1);
    try{
        service.DeleteService("XL", "Pink", "https://abcd.com", 1);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }

    service.AddService("XL", "Pink", 100, 0, "https://abcd.com");
    service.DeleteService("XL", "Pink", "https://abcd.com", 2);
    try{
        service.DeleteService("XL", "Pink", "https://abcd.com", 2);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }

}

void Test_Service::TestUpdatePriceService() {
    Repository UserRepo;
    Repository repo;
    repo.init_repository();
    Service service(repo, UserRepo);

    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    service.UpdatePriceService("XL", "Pink", "https://abcd.com", 200);
    assert(service.GetRepository()[10].GetPrice() == 200);
    try{
        service.UpdatePriceService("XL", "Purple", "https://abcdaadsd.com", 200);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }

}

void Test_Service::TestUpdateQuantityService() {
    Repository UserRepo;
    Repository repo;
    repo.init_repository();
    Service service(repo, UserRepo);

    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    service.UpdateQuantityService("XL", "Pink", "https://abcd.com", 200);
    try{
        service.UpdateQuantityService("XL", "Purple", "https://abcdaadsd.com", 200);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }

}

void Test_Service::TestGetSize() {
    Repository UserRepo;
    Repository repo;
    Service service(repo, UserRepo);

    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    assert(service.GetSize() == 1);

}

void Test_Service::TestAddUserService() {
    Repository UserRepo;
    Repository repo;
    Service service(repo, UserRepo);

    service.AddService("XL", "Pink", 100, 10, "https://abcd.com");
    Coat c("XL", "Pink", 100, 3, "https://abcd.com");
    Coat cUser("XL", "Pink", 100, 1, "https://abcd.com");
    assert(service.AddUserService(c, cUser) == 0);
    assert(service.GetUserRepository()[0].GetSize() == "XL");
    assert(service.GetUserRepository()[0].GetColor() == "Pink");
    assert(service.GetUserRepository()[0].GetPrice() == 100);
    assert(service.GetUserRepository()[0].GetQuantity() == 1);
    assert(service.GetUserRepository()[0].GetPhotograph() == "https://abcd.com");
    assert(service.AddUserService(c, cUser) == 0);
    assert(UserRepo.getArray()[0].GetQuantity() == 2);
    service.AddService("XL", "Purple", 100, 0, "https://sag.com");
    Coat cc("XL", "Purple", 100, 0, "https://sag.com");
    assert(service.AddUserService(cc, cUser) == 1);

}

void Test_Service::TestGetTotalPrice() {
    Repository UserRepo;
    Repository repo;
    repo.init_repository();
    Service service(repo, UserRepo);

    assert(service.GetTotalPrice() == 0);
}


void Test_Service::TestAllService() {
    TestAddService();
    TestDeleteService();
    TestUpdatePriceService();
    TestUpdateQuantityService();
    TestGetSize();
    TestAddUserService();
    TestGetTotalPrice();
}
