#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	// Complexity: 
	//      - Theta(1)
	// we start with the initial capacity of 1, the resize being made by doubling it
	this->capacity = 1;
	this->numberOfPairs = 0;
	this->elements = new TElem[this->capacity];
}

Map::~Map() {
	// Complexity: Theta(1)
	delete[] this->elements;
}

TValue Map::add(TKey c, TValue v){
	// Complexity:
	//		- BC : Theta(1)
	//      - WC : Theta(nrPairs) + Theta(nrPairs) = Theta(nrPairs)
	//				=> total: O(nrPairs)
	// if there is not enough space to introduce new values, we resize the capacity 
	
	if (this->numberOfPairs == this->capacity)
	{
		// double the capacity
		this->capacity *= 2;

		// copy the elements in a new array in the new memory space
		TElem* newElements = new TElem[this->capacity];

		//
		for (int i = 0; i < this->numberOfPairs; i++)
		{
			newElements[i] = this->elements[i];
		}

		// we free the memory space of the old array
		delete[] this->elements;

		// we update the pointer to the new array
		this->elements = newElements;
	}

	// check if the key already exists in the map
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		if (this->elements[i].first == c)
		{
			TValue oldValue = this->elements[i].second;
			this->elements[i].second = v;
			return oldValue;
		}
	}
	
	this->elements[this->numberOfPairs].first = c;
	this->elements[this->numberOfPairs].second = v;
	this->numberOfPairs++;
	return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
	// Complexity:
	//		- BC : Theta(1)
	//      - WC : Theta(nrPairs)
	//			=> total: O(nrPairs)

	
	for(int i = 0; i < this->numberOfPairs; i++){
		if(this->elements[i].first == c){
			return this->elements[i].second;
		}
	}
	
	// Binary search complexity: O(log(nrPairs))
	//       - BC : Theta(1)
	//       - WC : Theta(log(nrPairs))
	//			=> total: O(log(nrPairs))


	/*

	int left = 0, right = this->numberOfPairs - 1, mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
 
		// Check if x is present at the mid-point
		if (this->elements[mid].first == c){
			return this->elements[mid].second;
		}

		// If x is greater, ignore the left half

		if (this->elements[mid].first < c){
			left = mid + 1;
		}

		// If x is smaller, ignore the right half
		else{
			right = mid - 1;
		}
	}

	*/

	// if we reach here, then element was
	// not presents
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	// Complexity:
	//		- BC : Theta(1)
	//      - WC : Theta(nrPairs)
	//			=> total: O(nrPairs)

	for(int i = 0; i < this->numberOfPairs; i++){
		if(this->elements[i].first == c){
			TValue oldValue = this->elements[i].second;
			for(int j = i; j < this->numberOfPairs - 1; j++){
				this->elements[j] = this->elements[j + 1];
			}
			this->numberOfPairs--;
			return oldValue;
		}
	}
	return NULL_TVALUE;
}


int Map::size() const {
	// Complexity: Theta(1)
	return this->numberOfPairs;
}

bool Map::isEmpty() const{
	// Complexity: Theta(1)	
	if(this->numberOfPairs == 0){
		return true;
	}else{
		return false;
	}
}

MapIterator Map::iterator() const {
	// Complexity: Theta(1)
	return MapIterator(*this);
}



