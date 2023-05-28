#include "Set.h"
#include "SetIterator.h"

#include <iostream>

int Set::hash(TElem e) const {
    //Complexity:
    //BC: theta(1)
    //WC: theta(1)
    //Method hash returns the hash value of an element.
    //The hash value is the absolute value of the element modulo the capacity;
    //it's used to find the position of the element in the array.
    return abs(e) % capacity;
}

Set::Set() {
    //Complexity:
    //
    //AC: O(capacity/nrOfElements)
    //
    //Method Set creates an empty set.
    //Best case: theta(1), when the capacity is 100
    // and the number of elements is 0.
    //Worst case: theta(capacity), when the capacity is 100
    // and the number of elements is 100.

    capacity = 100;
    elements = new TElem[capacity];
    next = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        elements[i] = MAX;
        next[i] = -1;
    }
    firstFree = 0;
    nrOfElements = 0;
}

void Set::resize() {
    //Complexity:
    //BC: theta(1)
    //WC: theta(capacity)
    //Method resize is called when the load/dispersion
    //factor is greater than 70%.
    
    auto* old = new TElem[nrOfElements];
    for (int i = 0; i < nrOfElements; ++i) {
        old[i] = MAX;
    }
    int current = 0;
    for (int i = 0; i < capacity; ++i) {
        if (elements[i] != MAX) {
            old[current++] = elements[i];
        }
    }

    capacity *= 2;
    auto* nou = new TElem[capacity];
    int* nextNew = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        nou[i] = MAX;
        nextNew[i] = -1;
    }
    delete[] elements;
    delete[] next;
    elements = nou;
    next = nextNew;

    firstFree = 0;
    int oldNrOfElements = nrOfElements;
    nrOfElements = 0;
    for (int i = 0; i < oldNrOfElements; ++i) {
        add(old[i]);
    }
    delete[] old;
}

bool Set::add(TElem elem) {
    //Complexity:
    //
    //AC: O(capacity/nrOfElements)
    //
    //Method add adds an element to the set.
    //If the element was already in the set, it returns false.
    //If the element was not in the set, it returns true.
    //If the load factor is greater than 70%, it calls the resize method.

    if ((nrOfElements / capacity) * 100 > 70)
        resize();

    int i = hash(elem);
    // If the element's hash value is max,
    // it means that the element is not in the set.
    // The element is added to the elements array of the first free position.
    if (elements[i] == MAX)
    {
        elements[i] = elem;
        if (i == firstFree) {
            firstFree++;
            while ((firstFree < capacity) && elements[firstFree] != MAX)
                firstFree++;
        }
        nrOfElements++;
        return true;
    }

    // If the element is already in the set, the method returns false.
    int j = -1;
    while (i != -1)
    {
        if (elements[i] == elem)
            return false;
        j = i;
        i = next[i];
    }

    // If the element is not in the set, it is added to the elements array
    // of the first free position. The next array is updated.
    elements[firstFree] = elem;
    next[j] = firstFree;
    firstFree++;
    while ((firstFree < capacity) && elements[firstFree] != MAX)
        firstFree++;
    nrOfElements++;
    return true;
}


bool Set::remove(TElem elem) {
    //Complexity:
    //
    //AC: O(capacity/nrOfElements)
    //
    //Method remove removes an element from the set.

    int i = hash(elem);
    int j = -1;

    while (i != -1 && elements[i] != elem) {
        j = i;
        i = next[i];
    }

    if (i == -1) {
        return false;
    }
    else {
        bool check = false;
        do {
            int current = next[i];
            int previous = i;

            while (current != -1 && hash(elements[current]) != i) {
                previous = current;
                current = next[current];
            }

            if (current == -1) {
                check = true;
            }

            else {
                elements[i] = elements[current];
                i = current;
                j = previous;
            }
        } while (!check);
        //While the element to be removed has a next element,
        // we replace it with the next element.
        //If the element to be removed doesn't have a next element,
        // we replace it with the last element.

        if (j != -1) {
            next[j] = next[i];
        }
        elements[i] = MAX;
        next[i] = -1;
        if (i < firstFree) {
            firstFree = i;
        }
    }
    --nrOfElements;
    return true;
}


bool Set::search(TElem elem) const {
    //Complexity:
    //
    //AC: O(capacity/nrOfElements)
    //
    //Method search returns true if the element is in the set, false otherwise.
    //It uses the hash function to find the position of the element, and then
    // it searches for the element in the list of elements with the same hash.

    int i = hash(elem);
    if (elements[i] == elem)
    {
        return true;
    }

    while (i != -1)
    {
        if (elements[i] == elem)
            return true;
        i = next[i];
    }

    return false;
}


int Set::size() const {
    //Theta(1)
    return nrOfElements;
}

bool Set::isEmpty() const {
    //Theta(1)
    return nrOfElements == 0;
}


Set::~Set() {
    //Theta(1)
    delete[] elements;
    delete[] next;
}



SetIterator Set::iterator() const {
    return SetIterator(*this);
}
