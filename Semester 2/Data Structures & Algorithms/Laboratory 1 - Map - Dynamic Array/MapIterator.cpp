#include "Map.h"
#include "MapIterator.h"
#include <exception>
#include <iostream>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	//Theta(1) - complexity
	//One assignment operation
	this->current = 0;
}


void MapIterator::first() {
	//Theta(1) - complexity
	//One assignment operation
	this->current = 0;
}


void MapIterator::next() {
	//Theta(1) - complexity
	//One comparison and one assignment operation
	if(!this->valid()){
		throw exception();
	}else{
		this->current++;
	}
}


TElem MapIterator::getCurrent(){
	//Theta(1)
	// One comparison and one return operation
	if(!this->valid()){
		throw exception();
	}else{
		return this->map.elements[this->current];
	}
}


bool MapIterator::valid() const {
	//Theta(1)
	//One comparison and one return operation
	if (this->current < this->map.numberOfPairs)
		return true;
	else 
		return false;
}

void MapIterator::jumpForward(int k)
{
	//Theta(1)
	//One comparison and one assignment operation

	//Checking the validity of the parameter
	if(k <= 0 || !this->valid()){
		throw exception();
		//std :: cout << "Invalid parameter" << std :: endl;
	}else{
		if (this->current + k < this->map.numberOfPairs)
			this->current += k;
		else{
			//Checking if the iterator is still valid or not
			this->current = this->map.numberOfPairs;
		}
	}
}
