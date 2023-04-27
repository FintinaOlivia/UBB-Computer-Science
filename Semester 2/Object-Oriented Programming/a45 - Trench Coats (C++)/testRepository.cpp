#include <assert.h>
#include <iostream>
#include <string>
#include "Repository.h"
#include "Domain.h"
#include "TestAll.h"

void testAddTrenchCoat()
{
    Repository repository("test.txt");

    TrenchCoat trenchToAdd(1, 2, "red", 3, 4, "link");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    assert(repository.getSize() == 1);
    assert(repository.getAllTrenchCoats()[0] == trenchToAdd);

    repository.addTrenchCoat(1, 5, "blue", 2, 4, "link");
    TrenchCoat trenchToUpdate(1, 5, "blue", 2, 4, "link");
    assert(repository.getSize() == 2);
    assert(repository.getAllTrenchCoats()[1] == trenchToUpdate);
    
    std :: cout << "AddTrenchCoat test passed!" << std :: endl;
}

void testRemoveTrenchCoat()
{
    Repository repository("test.txt");
    TrenchCoat trenchToAdd(1, 2, "red", 3, 4, "link");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    repository.removeTrenchCoat(-1);
    assert(repository.getSize() == 1);
    repository.removeTrenchCoat(1);
    assert(repository.getSize() == 0);
    std :: cout << "RemoveTrenchCoat test passed!" << std :: endl;
}

void testUpdateTrenchCoat()
{
    Repository repository("test.txt");

    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    repository.updateTrenchCoat(1, 1, 3, "blue", 4, 5, "link2");
    TrenchCoat trenchToUpdate( 1, 3, "blue", 4, 5, "link2");
    assert(repository.getSize() == 1);
    assert(repository.getAllTrenchCoats()[0] == trenchToUpdate);
    std :: cout << "UpdateTrenchCoat test passed!" << std :: endl;
}

void testGetTrenchCoat()
{
    Repository repository("test.txt");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    TrenchCoat trenchToAdd(1, 2, "red", 3, 4, "link");
    assert(repository.getTrenchCoat(1) == trenchToAdd);
    repository.removeTrenchCoat(1);

    assert(repository.getTrenchCoat(100) == TrenchCoat(-1, -1, "", -1, -1, ""));
    std :: cout << "GetTrenchCoat test passed!" << std :: endl;
}

void testGetAllTrenchCoats()
{
    Repository repository("test.txt");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    TrenchCoat trenchToAdd(1, 2, "red", 3, 4, "link");
    assert(repository.getAllTrenchCoats()[0] == trenchToAdd);
    repository.removeTrenchCoat(1);
    std :: cout << "GetAllTrench coats test passed!" << std :: endl;
}

void testGetSize()
{
    Repository repository("test.txt");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    assert(repository.getSize() == 1);
    repository.removeTrenchCoat(1);
    std :: cout << "GetSize test passed!" << std :: endl;
}

void testSetFileName()
{
    Repository repository("test.txt");
    repository.setFileName("test2.txt");
    assert(repository.getFileName() == "test2.txt");
    std :: cout << "SetFile name test passed!" << std :: endl;
}

void testWriteToFile()
{
    Repository repository("test.txt");
    TrenchCoat trenchToAdd(1, 2, "red", 3, 4, "link");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    repository.writeToFile();
    repository.removeTrenchCoat(1);
    assert(repository.getSize() == 0);
    repository.readFromFile();
    assert(repository.getSize() == 1);
    assert(repository.getAllTrenchCoats()[0] == trenchToAdd);
    repository.removeTrenchCoat(1);
    repository.writeToFile();
    std :: cout << "WriteToFile test passed!" << std :: endl;
}

void testValidID()
{
    Repository repository("test.txt");
    repository.addTrenchCoat(1, 2, "red", 3, 4, "link");
    assert(repository.validID(1) == true);
    assert(repository.validID(2) == false);
    repository.removeTrenchCoat(1);
    std :: cout << "ValidID test passed!" << std :: endl;
}


void testRepository()
{
    testAddTrenchCoat();
    testRemoveTrenchCoat();
    testUpdateTrenchCoat();
    testGetTrenchCoat();
    testGetAllTrenchCoats();
    testGetSize();
    testSetFileName();
    testWriteToFile();
    testValidID();
}
