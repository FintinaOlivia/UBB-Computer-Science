#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    int currentFreq;
    int currentIndex;

    BagIterator(const Bag& c);
public:
    // Complexity: WC=BC=AC=Theta(1)
    void first();

    // Complexity: WC=BC=AC=Theta(1)
    // Throws exception if the current element is not valid
    void next();

    // Complexity: WC=BC=AC=Theta(1)
    // Throws exception if the current element is not valid
    TElem getCurrent() const;

    // Complexity: WC=BC=AC=Theta(1)
    bool valid() const;
};