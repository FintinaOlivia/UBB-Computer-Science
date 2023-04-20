//
// Created by theo on 20.04.2023.
//

#include "TestAll.h"
#include <cassert>
#include <iostream>
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"

void testController(){
    Repository repository;
    Controller controller(repository);
    assert(controller.addTrenchCoat(1, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(1, 2, "red", 3, 4, "photo") == false);
    assert(controller.addTrenchCoat(2, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(3, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(4, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(5, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(6, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(7, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(8, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(9, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(10, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(11, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(12, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(13, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(14, 2, "red", 3, 4, "photo") == true);
    assert(controller.addTrenchCoat(15, 2, "red", 3, 4, "photo") == true);

    assert(controller.removeTrenchCoat(1) == true);
    assert(controller.removeTrenchCoat(1) == false);
    assert(controller.removeTrenchCoat(2) == true);
    assert(controller.updateTrenchCoat(3, 2, 5, "blue", 6, 7, "photo2") == true);
    assert(controller.updateTrenchCoat(3, 2, 5, "blue", 6, 7, "photo2") == false);
    assert(controller.updateTrenchCoat(2, 3, 5, "blue", 6, 7, "photo2") == true);

    assert(controller.trenchCoatExists(3));

    assert(controller.getTrenchCoat(3).getTrenchID() == 3);

    assert(controller.getSize() == 13);

    controller.setFileName("test.txt");
    assert(controller.getFileName() == "test.txt");

    std::vector<TrenchCoat> trenchCoats = controller.getAllTrenchCoats();
    assert(trenchCoats.size() == 13);

    std::vector<TrenchCoat> filteredTrenchCoats = controller.filterBySize(2);
    assert(filteredTrenchCoats.size() == 12);

    controller.saveProgress();

    for(auto &trenchCoat : trenchCoats)
        controller.removeTrenchCoat(trenchCoat.getTrenchID());
    assert(controller.getSize() == 0);

    controller.loadFromFile();
    assert(controller.getSize() == 13);
    std::cout << "Controller tests passed!" << std::endl;
}

