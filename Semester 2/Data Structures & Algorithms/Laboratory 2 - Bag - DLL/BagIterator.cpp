#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//Complexity: Theta(1)

	currentNode = bag.head;
}

void BagIterator::first() {
	//Complexity: Theta(1)

	currentNode = bag.head;
}


void BagIterator::next() {
	//Complexity: Theta(1)

	if (valid()) {
		currentNode = currentNode->next;
	}
	else {
		throw exception();
	}
}


bool BagIterator::valid() const {
	//Complexity: Theta(1)
	
	if (currentNode != nullptr) {
		return true;
	}
	return false;
}



TElem BagIterator::getCurrent() const
{
	//Complexity: Theta(1)

	if (valid()) {
		return currentNode->info;
	}
	else {
		throw exception();
	}
}
