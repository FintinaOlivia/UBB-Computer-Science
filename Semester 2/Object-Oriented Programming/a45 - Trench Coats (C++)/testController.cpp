#include <assert.h>
#include "Controller.h"
#include "TestAll.h"

void testController()
{
    std :: cout << "Testing controller..." << std :: endl;
    Repository repository;
    Controller controller(repository);
    controller.setFileName("trenchCoats.txt");
    //std :: cout << "First test passed!" << std :: endl;

    controller.addTrenchCoat(1, 2, "red", 3, 4, "photo");
    assert(controller.getSize() == 1);
    assert(controller.trenchCoatExists(1) == true);
    //std :: cout << "Second test passed!" << std :: endl;

    controller.removeTrenchCoat(1);
    assert(controller.getSize() == 0);
    //std :: cout << "Third test passed!" << std :: endl;

    controller.addTrenchCoat(1, 2, "red", 3, 4, "photo");
    assert(controller.getTrenchCoat(1).getTrenchColour() == "red");
    controller.updateTrenchCoat(1, 3, 2, "blue", 3, 4, "photo");
    assert(controller.getTrenchCoat(3).getTrenchColour() == "blue");
    //std :: cout << "Fourth test passed!" << std :: endl;

    controller.updateTrenchCoat(3, 3, 2, "blue", 3, 4, "photo");
    assert(controller.getSize() == 1);
    assert(controller.updateTrenchCoat(5, 3, 2, "blue", 3, 4, "photo") == false);



    assert(controller.getSize() == 1);
    assert(controller.getFileName() == "trenchCoats.txt");

    controller.saveProgress();
    controller.setFileName("trenchCoats.txt");
    controller.loadFromFile();

    //Testing FilterBySize
    controller.addTrenchCoat(2, 3, "red", 3, 4, "photo");
    controller.addTrenchCoat(3, 4, "red", 3, 4, "photo");
    controller.addTrenchCoat(4, 4, "red", 3, 4, "photo");
    controller.addTrenchCoat(5, 6, "red", 3, 4, "photo");
    controller.addTrenchCoat(6, 6, "red", 3, 4, "photo");
    controller.addTrenchCoat(7, 6, "red", 3, 4, "photo");
    assert(controller.addTrenchCoat(7, 6, "red", 3, 4, "photo") == false);

    dynamicVector<TrenchCoat> filteredTrenchCoats = controller.filterBySize(6);
    assert(filteredTrenchCoats.getSize() == 3);

    dynamicVector<TrenchCoat> allTrenchCoats = controller.getAllTrenchCoats();
    assert(allTrenchCoats.getSize() == 7);
}

void testTrenchCoatExists()
{
    Repository repository;
    Controller controller(repository);
    controller.setFileName("trenchCoats.txt");

    controller.addTrenchCoat(1, 2, "red", 3, 4, "photo");
    assert(controller.trenchCoatExists(1) == true);
    assert(controller.trenchCoatExists(2) == false);

    std :: cout << "Controller tests passed!" << std::endl;
}