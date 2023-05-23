#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->currentIndex = this->bag.head;
    this->currentFreq = 0;
}

void BagIterator::first() {
    this->currentIndex = this->bag.head;
    this->currentFreq = 0;
}


void BagIterator::next() {
    exception exception;
    if (!this->valid()) { throw exception; }

    this->currentFreq++;
    if (this->currentFreq == this->bag.frequency[this->currentIndex])
    {
        this->currentIndex = this->bag.next[this->currentIndex];
        this->currentFreq = 0;
    }

}


bool BagIterator::valid() const {
    if (this->currentIndex == -1) return false;
    return true;
}

TElem BagIterator::getCurrent() const
{
    exception exception;
    if (!this->valid()) throw exception;
    return this->bag.elements[this->currentIndex];
}