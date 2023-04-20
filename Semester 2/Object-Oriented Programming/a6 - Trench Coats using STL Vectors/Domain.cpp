#include <string>
#include "Domain.h"

TrenchCoat::TrenchCoat(){
    this->id = 0;
    this->size = 0;
    this->colour = "0";
    this->price = 0;
    this->quantity = 0;
    this->photographyLink = "0";
};

TrenchCoat::TrenchCoat(int id, 
                    int sizeOfTrench, 
                    const std::string &colourOfTrench, 
                    float priceOfTrench, 
                    int quantityOfTrench, 
                    const std::string &photographyLinkOfTrench) {

    this->id = id;
    this->size = sizeOfTrench;
    this->colour = colourOfTrench;
    this->price = priceOfTrench;
    this->quantity = quantityOfTrench;
    this->photographyLink = photographyLinkOfTrench;

    // size{sizeOfTrench}; 
    // colour{colourOfTrench}; 
    // price{priceOfTrench};
    // quantity{quantityOfTrench};
    // photographyLink{photographyLinkOfTrench};

}

// TrenchCoat::TrenchCoat(int id, 
//                     int sizeOfTrench, 
//                     const std::string &colourOfTrench, 
//                     float priceOfTrench, 
//                     int quantityOfTrench, 
//                     const std::string &photographyLinkOfTrench) {

//     id = (id);
//     size = (sizeOfTrench);
//     colour = (colourOfTrench);
//     price = (priceOfTrench);
//     quantity = (quantityOfTrench);
//     photographyLink = (photographyLinkOfTrench);

//     // size{sizeOfTrench}; 
//     // colour{colourOfTrench}; 
//     // price{priceOfTrench};
//     // quantity{quantityOfTrench};
//     // photographyLink{photographyLinkOfTrench};

// }

//Getters
int TrenchCoat::getTrenchID() const {
    return this->id;
}

int TrenchCoat::getTrenchSize()
{
    return this->size;
}

std::string TrenchCoat::getTrenchColour() const
{
    return this->colour;
}

float TrenchCoat::getTrenchPrice()
{
    return this->price;
}

int TrenchCoat::getTrenchQuantity()
{
    return this->quantity;
}

std::string TrenchCoat::getTrenchPhotographyLink() const
{
    return this->photographyLink;
}

//Operator overloading
bool TrenchCoat::operator==(const TrenchCoat &trenchToCompare)
{
    if(this->id == trenchToCompare.id &&
        this->size == trenchToCompare.size &&
        this->colour == trenchToCompare.colour &&
        this->price == trenchToCompare.price &&
        this->quantity == trenchToCompare.quantity &&
        this->photographyLink == trenchToCompare.photographyLink)
    {
        return true;
    }else{
        return false;
    }
}

//Setters
void TrenchCoat::setTrenchID(int newID)
{
    this->id = newID;
}

void TrenchCoat::setTrenchSize(int newSize)
{
    this->size = newSize;
}

void TrenchCoat::setTrenchColour(const std::string &newColour)
{
    this->colour = newColour;
}

void TrenchCoat::setTrenchPrice(float newPrice)
{
    this->price = newPrice;
}

void TrenchCoat::setTrenchQuantity(int newQuantity)
{
    this->quantity = newQuantity;
}

void TrenchCoat::setTrenchPhotographyLink(const std::string &newPhotographyLink)
{
    this->photographyLink = newPhotographyLink;
}

