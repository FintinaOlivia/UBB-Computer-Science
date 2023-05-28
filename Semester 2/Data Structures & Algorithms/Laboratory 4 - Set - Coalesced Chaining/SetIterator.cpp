#include <exception>
#include "SetIterator.h"
#include "Set.h"


void SetIterator::displacement() {
    // if the current element reached the end of the array
    // or the current element is MAX, then we move to the next element
    while ((current < Set.capacity) && Set.elements[current] == MAX )
        current++;
}

SetIterator::SetIterator(const class Set& m) : Set(m){
    current = 0;
    displacement();
}


void SetIterator::first() {
    current = 0;
    displacement();
}

void SetIterator::next() {
    if(!valid())
        throw std::exception();
    current++;
    displacement();
}

void SetIterator::previous() {
    if(!valid())
        throw std::exception();
    current--;
    while ((current >= 0) && Set.elements[current] == MAX)
        current--;
}

TElem SetIterator::element() const {
    return Set.elements[current];
}

bool SetIterator::valid() const {
    return (current < Set.capacity && current >= 0);
}