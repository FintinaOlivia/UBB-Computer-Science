#include "Domain.h"
#include <cassert>
#include <string>
#include <iostream>
#include "TestAll.h"

void testDomain()
{
    TrenchCoat auxTrenchCoat = TrenchCoat();
    assert(auxTrenchCoat.getTrenchID() == 0);
    if(auxTrenchCoat == TrenchCoat())
        assert(true);

    TrenchCoat trenchCoat(1, 2, "red", 3, 4, "link");
    assert((trenchCoat == TrenchCoat(1, 6, "red", 3, 4, "link") == false));
    assert(trenchCoat.getTrenchID() == 1);
    assert(trenchCoat.getTrenchSize() == 2);
    assert(trenchCoat.getTrenchColour() == "red");
    assert(trenchCoat.getTrenchPrice() == 3);
    assert(trenchCoat.getTrenchQuantity() == 4);
    assert(trenchCoat.getTrenchPhotographyLink() == "link");

    trenchCoat.setTrenchID(5);
    assert(trenchCoat.getTrenchID() == 5);

    trenchCoat.setTrenchSize(6);
    assert(trenchCoat.getTrenchSize() == 6);

    trenchCoat.setTrenchColour("blue");
    assert(trenchCoat.getTrenchColour() == "blue");

    trenchCoat.setTrenchPrice(7);
    assert(trenchCoat.getTrenchPrice() == 7);

    trenchCoat.setTrenchQuantity(8);
    assert(trenchCoat.getTrenchQuantity() == 8);
    
    trenchCoat.setTrenchPhotographyLink("link2");
    assert(trenchCoat.getTrenchPhotographyLink() == "link2");

    std::cout << "Domain tests passed!" << std::endl;
}
