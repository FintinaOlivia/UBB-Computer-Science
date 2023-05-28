#pragma once

class Set;
typedef int TElem;

class SetIterator
{
    friend class Set;
private:
    explicit SetIterator(const Set& mul);
    const Set& Set;

    //Representation
    int current;
    void displacement();

public:
    void first();
    void next();
    void previous();
    bool valid() const;
    TElem element() const;
};