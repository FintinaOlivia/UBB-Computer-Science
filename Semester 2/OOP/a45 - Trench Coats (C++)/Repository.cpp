#include "Repository.h"
#include <fstream>
#include <iostream>
#include <string>

void Repository::addTrenchCoat(int id,
                                int sizeOfTrench,
                                const std::string& colourOfTrench,
                                float priceOfTrench,
                                int quantityOfTrench,
                                const std::string& photography_linkOfTrench)
{
    TrenchCoat trenchToAdd = TrenchCoat(id,
                                        sizeOfTrench,
                                        colourOfTrench,
                                        priceOfTrench,
                                        quantityOfTrench,
                                        photography_linkOfTrench);

   
    this->trenchCoats.append(trenchToAdd);
}

void Repository::removeTrenchCoat(int trenchID)
{
    for (int i = 0; i < this->trenchCoats.getSize(); i++)
    {
        if (this->trenchCoats[i].getTrenchID() == trenchID)
        {
            this->trenchCoats.remove(i);
            return;
        }
    }
}

void Repository::updateTrenchCoat(int trenchID, 
                                    int newID,
                                    int newSizeOfTrench, 
                                    const std::string& newColourOfTrench, 
                                    float newPriceOfTrench, 
                                    int newQuantityOfTrench, 
                                    const std::string& newPhotography_linkOfTrench)
{
    this->removeTrenchCoat(trenchID);
    this->addTrenchCoat(newID,
                        newSizeOfTrench,
                        newColourOfTrench,
                        newPriceOfTrench, 
                        newQuantityOfTrench, 
                        newPhotography_linkOfTrench);
    /*
    TrenchCoat trenchToUpdate(newID,
                            newSizeOfTrench,
                            newColourOfTrench,
                            newPriceOfTrench,
                            newQuantityOfTrench,
                            newPhotography_linkOfTrench);

    for (int i = 0; i < this->trenchCoats.getSize(); i++)
    {
        if (this->trenchCoats[i].getTrenchID() == trenchID)
        {
            this->trenchCoats[i].setTrenchID(newID);
            this->trenchCoats[i].setTrenchSize(newSizeOfTrench);
            this->trenchCoats[i].setTrenchColour(newColourOfTrench);
            this->trenchCoats[i].setTrenchPrice(newPriceOfTrench);
            this->trenchCoats[i].setTrenchQuantity(newQuantityOfTrench);
            this->trenchCoats[i].setTrenchPhotographyLink(newPhotography_linkOfTrench);
            return;
        }
    }
    */
}

bool Repository::validID(int trenchID)
{
    for (int i = 0; i < this->trenchCoats.getSize(); i++)
    {
        if (this->trenchCoats[i].getTrenchID() == trenchID)
        {
            return true;
        }
    }
    return false;
}

TrenchCoat Repository::getTrenchCoat(int trenchID)
{
    for (int i = 0; i < this->trenchCoats.getSize(); i++)
    {
        if (this->trenchCoats[i].getTrenchID() == trenchID)
        {
            return this->trenchCoats[i];
        }
    }
    return TrenchCoat(-1,-1, "", -1, -1, "");
}

dynamicVector<TrenchCoat> Repository::getAllTrenchCoats()
{
    return this->trenchCoats;
}

int Repository::getSize()
{
    return this->trenchCoats.getSize();
}

void Repository::setFileName(std::string newFileName)
{
    this->FileName = newFileName;
}

std::string Repository::getFileName() const
{
    return this->FileName;
}

void Repository::writeToFile()
{
    ofstream file(this->FileName);
    if (file.is_open())
    {
        for (int i = 0; i < this->trenchCoats.getSize(); i++)
        {
            file << this->trenchCoats[i].getTrenchID() << " ";
            file << this->trenchCoats[i].getTrenchSize() << " ";
            file << this->trenchCoats[i].getTrenchColour() << " ";
            file << this->trenchCoats[i].getTrenchPrice() << " ";
            file << this->trenchCoats[i].getTrenchQuantity() << " ";
            file << this->trenchCoats[i].getTrenchPhotographyLink() << " ";
            file << endl;
        }
    }
    file.close();
}

void Repository::readFromFile()
{
    ifstream file(this->FileName);
    if (file.is_open())
    {
        int id, size, quantity;
        float price;
        std::string colour, photographyLink;
        while (file >> id >> size >> colour >> price >> quantity >> photographyLink)
        {
            TrenchCoat trenchToAdd(id, size, colour, price, quantity, photographyLink);
            this->trenchCoats.append(trenchToAdd);
        }
    }
    file.close();
}

Repository::Repository()
{
    this->FileName = "default.txt";
}

Repository::Repository(std::string FileName)
{
    this->FileName = FileName;
    this->readFromFile();
}


