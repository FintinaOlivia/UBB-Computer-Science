#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//Complexity: theta(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->currentNode = c.head;
    this->currentFrequency = 1;
}

//Complexity: theta(1)
void BagIterator::first() {
	this->currentNode = this->bag.head;
}

//Complexity: theta(1)
//Best Case == Worst Case == Average Case
void BagIterator::next() {
	if (this->currentNode == nullptr) {
        throw exception();
    }else{
        if (this->currentFrequency < this->currentNode->frequency) {
            this->currentFrequency++;
        }else{
            this->currentNode = this->currentNode->next;
            this->currentFrequency = 1;
        }
    }
}

//Complexity: theta(1)
//Best Case == Worst Case == Average Case
bool BagIterator::valid() const {
	if (this->currentNode == nullptr) {
        return false;
    }
    return true;
}


//Complexity: theta(1)
//Best Case == Worst Case == Average Case
TElem BagIterator::getCurrent() const
{
	if (this->currentNode == nullptr) {
        throw exception();
    }
    return this->currentNode->info;
}
