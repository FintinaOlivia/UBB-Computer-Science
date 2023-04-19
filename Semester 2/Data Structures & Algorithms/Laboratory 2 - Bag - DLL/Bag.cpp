#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;



Bag::Bag() {
	head = NULL;
	tail = NULL;
	length = 0;
}


void Bag::add(TElem elem) {
	
	Node<TElem>* newNode = new Node<TElem>;
	newNode->info = elem;
	newNode->frequency = 0;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		newNode->frequency += 1;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	length++;
}


bool Bag::remove(TElem elem) {
	
	Node<TElem>* currentNode = head;

	while (currentNode != NULL) {
		if (currentNode->info == elem) {
			if (currentNode == head) {
				head = currentNode->next;
				if (head != NULL) {
					head->prev = NULL;
				}
				else {
					tail = NULL;
				}
			}
			else if (currentNode == tail) {
				tail = currentNode->prev;
				tail->next = NULL;
			}
			else {
				currentNode->prev->next = currentNode->next;
				currentNode->next->prev = currentNode->prev;
			}
			delete currentNode;
			length--;
			return true;
		}
		currentNode = currentNode->next;
	}
	return false; 
}


bool Bag::search(TElem elem) const {

	Node<TElem>* currentNode = head;
	while (currentNode != NULL) {
		if (currentNode->info == elem) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	
	Node<TElem>* currentNode = head;
	int count = 0;
	while (currentNode != NULL) {
		if (currentNode->info == elem) {
			count++;
		}
		currentNode = currentNode->next;
	}
	return count;
}


int Bag::size() const {

	return length;
}


bool Bag::isEmpty() const {
	
	if (length == 0) {
		return true;
	}
	return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	
	Node<TElem>* currentNode = head;
	while (currentNode != NULL) {
		Node<TElem>* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
}

