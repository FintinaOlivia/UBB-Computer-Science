#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

//Complexity: theta(1)
Bag::Bag() {
	this->head = nullptr;
    this->tail = nullptr;
    this->sizeOfBag = 0;
}

//Complexity:
// - Best Case: theta(1)
// - Worst Case: theta(n)
// - Average Case: theta(n)
void Bag::add(TElem elem) {
	if(this->head == nullptr) {
        // If the bag is empty, add the element to the bag
        // and set the head and tail to the new node
        auto* newNode = new Node<TElem>;
        newNode->info = elem;
        newNode->frequency = 1;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        this->head = newNode;
        this->tail = newNode;
        this->sizeOfBag++;
    }else{
        // Search for the element in the bag
        // If it is found, increase the frequency
        Node<TElem>* currentNode = this->head;
        while (currentNode != nullptr) {
            if (currentNode->info == elem) {
                currentNode->frequency++;
                this->sizeOfBag++;
                return;
            }
            currentNode = currentNode->next;
        }

        // If it is not found, add it to the end of the bag
        auto* newNode = new Node<TElem>;

        newNode->info = elem;
        newNode->frequency = 1;
        newNode->next = nullptr;
        newNode->prev = this->tail;

        this->tail->next = newNode;
        this->tail = newNode;
        this->sizeOfBag++;
    }
}

//Complexity:
// - Best Case: theta(1)
// - Worst Case: theta(n)
// - Average Case: theta(n)
bool Bag::remove(TElem elem) {
	if(this->head == nullptr) {
        return false;
    }

    Node<TElem>* currentNode = this->head;
    while (currentNode != nullptr) {
        if (currentNode->info == elem) {
            if (currentNode->frequency > 1) {
                currentNode->frequency--;
                this->sizeOfBag--;
                return true;
            }else{
                if (currentNode == this->head) {
                    this->head = currentNode->next;
                    if (this->head != nullptr) {
                        this->head->prev = nullptr;
                    }
                    delete currentNode;
                    this->sizeOfBag--;
                    return true;
                }else if (currentNode == this->tail) {
                    this->tail = currentNode->prev;
                    if (this->tail != nullptr) {
                        this->tail->next = nullptr;
                    }
                    delete currentNode;
                    this->sizeOfBag--;
                    return true;
                }else{
                    currentNode->prev->next = currentNode->next;
                    currentNode->next->prev = currentNode->prev;
                    delete currentNode;
                    this->sizeOfBag--;
                    return true;
                }
            }
        }
        currentNode = currentNode->next;
    }
	return false; 
}

//Complexity:
// - Best Case: theta(1)
// - Worst Case: theta(n)
// - Average Case: theta(n)
bool Bag::search(TElem elem) const {
	if(this->head == nullptr) {
        return false;
    }

    Node<TElem>* currentNode = this->head;
    while (currentNode != nullptr) {
        if (currentNode->info == elem) {
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}

//Complexity:
// - Best Case: theta(1)
// - Worst Case: theta(n)
// - Average Case: theta(n)
int Bag::nrOccurrences(TElem elem) const {
	if(this->head == nullptr) {
        return 0;
    }

    Node<TElem>* currentNode = this->head;
    while (currentNode != nullptr) {
        if (currentNode->info == elem) {
            return currentNode->frequency;
        }
        currentNode = currentNode->next;
    }

    return 0;
}

//Complexity: theta(1)
//Best Case == Worst Case == Average Case == theta(1)
int Bag::size() const {
	return this->sizeOfBag;
}

//Complexity: theta(1)
//Best Case == Worst Case == Average Case == theta(1)
bool Bag::isEmpty() const {
	return this->sizeOfBag == 0;
}

//Complexity: theta(1)
//Best Case == Worst Case == Average Case == theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//Complexity: theta(n)
//Best Case == Worst Case == Average Case == theta(n)
Bag::~Bag() {
    Node<TElem>* currentNode = this->head;
    while (currentNode != nullptr) {
        Node<TElem>* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    delete currentNode;
}

