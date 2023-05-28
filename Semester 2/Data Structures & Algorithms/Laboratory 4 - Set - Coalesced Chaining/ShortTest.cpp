#include "ShortTest.h"
#include <cassert>
#include <iostream>
#include "Set.h"
#include "SetIterator.h"

void test_previous(){
    Set s;
    s.add(1);
    s.add(2);
    s.add(3);
    s.add(4);
    s.add(5);
    SetIterator it = s.iterator();
    it.first();
    assert(it.element() == 1);
    it.next();
    assert(it.element() == 2);
    it.next();
    assert(it.element() == 3);
    it.previous();
    assert(it.element() == 2);
    it.previous();
    assert(it.element() == 1);
    it.previous();
    assert(it.valid() == false);
    std:: cout << "Previous Test passed" << std :: endl;
}

void testAll() {
    test_previous();
    Set m;
    assert(m.isEmpty() == true);
    assert(m.size() == 0);
    assert(m.add(5)==true);
    assert(m.add(1)==true);
    assert(m.add(10)==true);
    assert(m.add(7)==true);
    assert(m.add(1)==false);
    assert(m.add(10)==false);
    assert(m.add(-3)==true);
    assert(m.size() == 5);
    assert(m.search(10) == true);
    assert(m.search(16) == false);
    assert(m.remove(1) == true);
    assert(m.remove(6) == false);
    assert(m.size() == 4);


    SetIterator im = m.iterator();
    im.first();
    int s = 0;
    while (im.valid()) {
        TElem e = im.element();
        s += e;
        im.next();
    }
    assert(s == 19);

}