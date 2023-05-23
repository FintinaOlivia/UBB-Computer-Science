#pragma once
#include <exception>
#include <numeric>
//DO NOT INCLUDE BAGITERATOR

using namespace std;

//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111
#define MAXCAP 9999999
typedef int TElem;
class BagIterator;

class Bag {
private:
    TElem* elements;
    int* frequency;
    int* next;
    int sizeElems;
    int head;
    int firstEmpty;
    int prevEmpty;

    //DO NOT CHANGE THIS PART
    friend class BagIterator;
public:
    //constructor
    // Complexity: WC=BC=AC=Theta(1)
    Bag();

    //adds an element to the bag
    // Complexity: AC=WC=O(length of map) - WC when the bag isn't empty and the element doesn't exist
    //             BC=O(1) when the element is the first one
    void add(TElem e);

    //removes one occurrence of an element from a bag
    //returns true if an element was removed, false otherwise (if e was not part of the bag)
    // Complexity: AC=WC=O(length of map) - WC when the bag isn't empty and the element to be removed is the last one/doesn't exist
    //             BC=O(1) when the element to be removed is the first one in the bag/the bag is empty
    bool remove(TElem e);

    //checks if an element appearch is the bag
    // Complexity: AC=WC=O(length of map) when the element searched is the last one in the bag/doesn't exist
    //             BC=O(1) when the element searched is the first one in the bag/the bag is empty
    bool search(TElem e) const;

    //returns the number of occurrences for an element in the bag
    // Complexity: AC=WC=O(length of map) when the element searched is the last one in the bag/doesn't exist
    //             BC=O(1) when the element searched is the first one in the bag/the bag is empty
    int nrOccurrences(TElem e) const;

    //returns the number of elements from the bag
    // Complexity: AC=BC=WC=Theta(1)
    int size() const;

    //returns an iterator for this bag
    // Complexity: AC=BC=WC=Theta(1)
    BagIterator iterator() const;

    //checks if the bag is empty
    // Complexity: AC=BC=WC=Theta(1)
    bool isEmpty() const;

    //destructor
    // Complexity: AC=BC=WC=Theta(1)
    ~Bag();
};