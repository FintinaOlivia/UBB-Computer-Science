#pragma once
//DO NOT INCLUDE SETITERATOR
#define MAX 100000
//DO NOT CHANGE THIS PART
#define NULL_TELEM (-1)
typedef int TElem;

class SetIterator;

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    //Representation
    int capacity;
    int nrOfElements;
    TElem* elements;
    int* next;
    int firstFree;

    int hash(TElem e) const;
    void resize();

public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator() const;

    // destructor
    ~Set();
};



