#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    this->head = -1;
    this->prevEmpty = -1;
    this->firstEmpty = 0;
    this->sizeElems = 0;
    this->elements = new TElem[MAXCAP];
    this->frequency = new TElem[MAXCAP];
    this->next = new TElem[MAXCAP];
}


void Bag::add(TElem elem) {
    if (this->isEmpty())
    {
        this->head = firstEmpty;
        if (sizeElems == 0)
        {
            elements[sizeElems]=elem;
            frequency[sizeElems] = 1;
            next[sizeElems++] = -1;
            prevEmpty = firstEmpty;
            firstEmpty++;
        }
        else
        {
            elements[firstEmpty] = elem;
            frequency[firstEmpty] = 1;
            int nextEmpty = next[firstEmpty];
            next[firstEmpty] = -1;
            prevEmpty = firstEmpty;
            firstEmpty = nextEmpty;
        }
    }
    else
    {
        int current = this->head;
        while (current != -1)
        {
            if (elements[current] == elem)
            {
                frequency[current]++;
                return;
            }
            current = next[current];
        }
        if (firstEmpty == sizeElems)
        {
            next[prevEmpty] = firstEmpty;
            elements[sizeElems] = elem;
            frequency[sizeElems] = 1;
            next[sizeElems++] = -1;
            prevEmpty = firstEmpty;
            firstEmpty++;
        }
        else
        {
            elements[firstEmpty] = elem;
            frequency[firstEmpty] = 1;
            next[prevEmpty] = firstEmpty;
            int nextEmpty = next[firstEmpty];
            next[firstEmpty] = -1;
            prevEmpty = firstEmpty;
            firstEmpty = nextEmpty;
        }
    }
}


bool Bag::remove(TElem elem) {
    int current = this->head,prevcurrent=-1;
    while (current != -1)
    {
        if (elements[current] == elem)
        {
            frequency[current]--;
            if (frequency[current] == 0)
            {
                if (current == this->head)
                {
                    this->head = next[current];
                }
                else next[prevcurrent] = next[current];
                next[current] = firstEmpty;
                firstEmpty = current;
            }
            return true;
        }
        prevcurrent = current;
        current = next[current];
    }
    return false;
}


bool Bag::search(TElem elem) const {
    int current = this->head;
    while (current != -1)
    {
        if (elements[current] == elem) return true;
        current = next[current];
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    int current = this->head;
    while (current != -1)
    {
        if (elements[current] == elem)return frequency[current];
        current = next[current];
    }
    return 0;
}


int Bag::size() const {

    int sum = 0, current = this->head;
    while (current != -1)
    {
        sum+=frequency[current];
        current = next[current];
    }
    return sum;

}


bool Bag::isEmpty() const {
    if (this->head == -1)
        return true;
    return false;
}


BagIterator Bag::iterator() const {
    return BagIterator(*this);
}


Bag::~Bag() {
    delete[] elements;
    delete[] frequency;
    delete[] next;
}

