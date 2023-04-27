#include "DynamicArray.h"
#include "Domain.h"
#include "TestAll.h"
#include <iostream>
#include <assert.h>

using namespace std;

void testDynamicArray()
{
    dynamicVector<TrenchCoat> dynamicVector{1};

    TrenchCoat trenchCoat1(1, 2, "red", 3, 4, "link");
    TrenchCoat trenchCoat2(2, 3, "blue", 4, 5, "link2");
    TrenchCoat trenchCoat3(3, 4, "green", 5, 6, "link3");
    TrenchCoat trenchCoat4(4, 5, "yellow", 6, 7, "link4");
    TrenchCoat trenchCoat5(5, 6, "black", 7, 8, "link5");
    TrenchCoat trenchCoat6(6, 7, "white", 8, 9, "link6");
    TrenchCoat trenchCoat7(7, 8, "purple", 9, 10, "link7");
    TrenchCoat trenchCoat8(8, 9, "orange", 10, 11, "link8");
    TrenchCoat trenchCoat9(9, 10, "brown", 11, 12, "link9");
    TrenchCoat trenchCoat10(10, 11, "grey", 12, 13, "link10");
    TrenchCoat trenchCoat11(11, 12, "pink", 13, 14, "link11");
    TrenchCoat trenchCoat12(12, 13, "cyan", 14, 15, "link12");
    TrenchCoat trenchCoat13(13, 14, "magenta", 15, 16, "link13");
    TrenchCoat trenchCoat14(14, 15, "lime", 16, 17, "link14");
    TrenchCoat trenchCoat15(15, 16, "maroon", 17, 18, "link15");
    TrenchCoat trenchCoat16(16, 17, "olive", 18, 19, "link16");
    TrenchCoat trenchCoat17(17, 18, "navy", 19, 20, "link17");
    
    dynamicVector.append(trenchCoat1);
    dynamicVector.append(trenchCoat2);
    dynamicVector.append(trenchCoat3);
    dynamicVector.append(trenchCoat4);
    dynamicVector.append(trenchCoat5);
    dynamicVector.append(trenchCoat6);
    dynamicVector.append(trenchCoat7);
    dynamicVector.append(trenchCoat8);
    dynamicVector.append(trenchCoat9);
    dynamicVector.append(trenchCoat10);
    dynamicVector.append(trenchCoat11);
    dynamicVector.append(trenchCoat12);
    dynamicVector.append(trenchCoat13);
    dynamicVector.append(trenchCoat14);
    dynamicVector.append(trenchCoat15);
    dynamicVector.append(trenchCoat16);
    dynamicVector.append(trenchCoat17);

    assert(dynamicVector.getSize() == 17);
    assert(dynamicVector.getCapacity() == 32);

    dynamicVector.remove(0);
    assert(dynamicVector.getSize() == 16);
    assert(dynamicVector.getCapacity() == 32);

    dynamicVector.remove(15);
    assert(dynamicVector.getSize() == 15);
    assert(dynamicVector.getCapacity() == 32);

    dynamicVector.update(0, trenchCoat1);
    assert(dynamicVector[0] == trenchCoat1);

    dynamicVector.update(-1, trenchCoat1);
    dynamicVector.remove(-1);
    assert(dynamicVector.getSize() == 15);
    std::cout << "Dynamic array tests passed!" << std::endl;
}
