#include "Set.h"
#include <cassert>
#include "ExtendedTest.h"
#include "SetIterator.h"
#include <iostream>

using namespace std;

//
//void printSet(Set& m){
//    SetIterator im = m.iterator();
//    while (im.valid()){
//        std::cout << im.element() << " ";
//        im.next();
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//}

void testIteratorSteps(Set& s) {
    int count = 0;
    SetIterator si = s.iterator();
    while (si.valid()) {
        count++;
        si.next();
    }
    assert(count == s.size());
}


void testCreate() {
    cout << "Test Create" << endl;
    Set m;
    assert(m.size() == 0);
    assert(m.isEmpty() == true);

    for (int i = -10; i < 10; i++) {
        assert(m.search(i) == false);
    }
    for (int i = -10; i < 10; i++) {
        assert(m.remove(i) == false);
    }

    SetIterator im = m.iterator();
    assert(im.valid() == false);
}

void testAdd() {
    cout << "Test Add" << endl;
    Set s;
    for (int i = 0; i < 10; i++) {
        s.add(i);
    }
    //printM(m);
    assert(s.isEmpty() == false);
    assert(s.size() == 10);
    for (int i = -10; i < 20; i++) { //add more elements [-10, 20)
        s.add(i);
    }
    //printM(m);
    assert(s.isEmpty() == false);
    assert(s.size() == 30);
    for (int i = -100; i < 100; i++) { //add more elements [-100, 100)
        s.add(i);
    }
    //printM(m);
    assert(s.isEmpty() == false);
    assert(s.size() == 200);
    for (int i = -200; i < 200; i++) {
        if (i < -100) {
            assert(s.search(i) == false);
        }
        else if (i < 0) {
            assert(s.search(i) == true);
        }
        else if (i < 100) {
            assert(s.search(i) == true);
        }
        else {
            assert(s.search(i) == false);
        }
    }
    testIteratorSteps(s);
    for (int i = 10000; i > -10000; i--) { //add larger values first
        s.add(i);
    }
    testIteratorSteps(s);
    assert(s.size()==20000);
}

void testRemove() {
    cout << "Test Remove" << endl;
    Set m;
    for (int i = -100; i < 100; i++) { //delete from the emtpy set
        assert(m.remove(i) == false);
    }
    assert(m.size() == 0);
    //printM(m);
    for (int i = -100; i < 100; i = i + 2) {
        m.add(i);
    }
    for (int i = -100; i < 100; i++) { //delete everything (including inexistent elements)
        if (i % 2 == 0) {
            assert(m.remove(i) == true);
        }
        else {
            assert(m.remove(i) == false);
        }
    }
    assert(m.size() == 0);
    //printM(m);

    for (int i = -100; i <= 100; i = i + 2) {
        m.add(i);
    }
    //printM(m);
    for (int i = 100; i > -100; i--) { //delete in descending order (reverse order compared to the adding)
        if (i % 2 == 0) {
            assert(m.remove(i) == true);
        }
        else {
            assert(m.remove(i) == false);
        }
    }

    assert(m.size() == 1);
    //printM(m);

    m.remove(-100);
    assert(m.size() == 0);

    for (int i = -100; i < 100; i++) { //add each element five times
        m.add(i);
        m.add(i);
        m.add(i);
        m.add(i);
        m.add(i);
    }
    //printM(m);
    assert(m.size() == 200);
    for (int i = -200; i < 200; i++) { //delete existing and inexistent elements
        if (i < -100 || i >= 100) {
            assert(m.remove(i) == false);
        }
        else {
            assert(m.remove(i) == true);
            assert(m.remove(i) == false);
        }
        testIteratorSteps(m);
    }
    assert(m.size() == 0);

}

void testIterator() {
    cout << "Test Iterator" << endl;
    Set m;
    SetIterator im = m.iterator();
    assert(im.valid() == false);

    for (int i = 0; i < 100; i++) {
        m.add(33);
    }

    SetIterator im2 = m.iterator();
    assert(im2.valid() == true);
    TElem elem = im2.element();
    assert(elem == 33);
    im2.next();
    assert(im2.valid() == false);

    im2.first();
    assert(im2.valid() == true);

    Set m2;
    for (int i = -100; i < 100; i++) {
        m2.add(i);
        m2.add(i);
        m2.add(i);
    }

    SetIterator im3 = m2.iterator();
    assert(im3.valid() == true);
    for (int i = 0; i < 200; i++) {
        im3.next();
    }
    assert(im3.valid() == false);
    im3.first();
    assert(im3.valid() == true);


    Set m3;
    for (int i = 0; i < 200; i= i + 4) {
        m3.add(i);
    }


    SetIterator im4 = m3.iterator();
    assert(im4.valid() == true);
    int count = 0;
    while (im4.valid()) {
        TElem e = im4.element();
        assert(e % 4 == 0);
        im4.next();
        count++;
    }
    assert(count == 50);

}

void testMix()
{
    cout << "Test Mix" << endl;
    Set s;
    int first = 11;
    int last = 11;
    int count = 3;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < count; j++) {
            s.add(last);
            last = (last + 7) % 11111;
        }
        assert(s.search(first) == true);
        assert(s.remove(first) == true);
        first = (first + 7) % 11111;
        if (i % 10 == 0) {
            count++;
        }
    }
    while (s.isEmpty() == false) {
        assert(s.search(first) == true);
        assert(s.remove(first) == true);
        first = (first + 7) % 11111;

    }
}


void testQuantity() {
    cout << "Test Quantity" << endl;
    Set m;
    for (int i = 10; i >= 1; i--) {
        for (int j = -30000; j < 30000; j = j + i) {
            m.add(j);
        }
    }
    assert(m.size() == 60000);
    SetIterator im = m.iterator();
    assert(im.valid() == true);
    for (int i = 0; i < m.size(); i++) {
        im.next();
    }
    im.first();
    while (im.valid()) {
        TElem e = im.element();
        assert(m.search(e) == true);
        im.next();
    }
    assert(im.valid() == false);
    for (int i = 0; i < 10; i++) {
        for (int j = 40000; j >= -40000; j--) {
            m.remove(j);
        }
    }
    assert(m.size() == 0);
}

void testAllExtended() {
    testCreate();
    testAdd();
    testRemove();
    testIterator();
    testMix();
    testQuantity();
}