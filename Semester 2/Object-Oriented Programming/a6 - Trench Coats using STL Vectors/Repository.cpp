#include "Repository.h"
#include <string>
#include <fstream>

Repository::Repository(std::string FileName) {
    this->FileName = std::move(FileName);
    this->readFromFile();
}

bool Repository::addTrenchCoat(int id,
                               int sizeOfTrench,
                               const std::string& colourOfTrench,
                               float priceOfTrench,
                               int quantityOfTrench,
                               const std::string& photography_linkOfTrench) {
    TrenchCoat trenchCoat(id, sizeOfTrench, colourOfTrench, priceOfTrench, quantityOfTrench, photography_linkOfTrench);
    this->trenchCoats.push_back(trenchCoat);
    if(this->validID(id)) {
        return true;
    }
    return false;
}

bool Repository::removeTrenchCoat(int trenchID) {
    for (int i = 0; i < this->trenchCoats.size(); i++) {
        if (this->trenchCoats[i].getTrenchID() == trenchID) {
            this->trenchCoats.erase(this->trenchCoats.begin() + i);
            return true;
        }
    }

    return false;
}

bool Repository::updateTrenchCoat(int trenchID,
                                  int newID,
                                  int newSizeOfTrench,
                                  const std::string& newColourOfTrench,
                                  float newPriceOfTrench,
                                  int newQuantityOfTrench,
                                  const std::string& newPhotography_linkOfTrench) {
    for (auto & trenchCoat : this->trenchCoats) {
        if (trenchCoat.getTrenchID() == trenchID) {
            trenchCoat.setTrenchID(newID);
            trenchCoat.setTrenchSize(newSizeOfTrench);
            trenchCoat.setTrenchColour(newColourOfTrench);
            trenchCoat.setTrenchPrice(newPriceOfTrench);
            trenchCoat.setTrenchQuantity(newQuantityOfTrench);
            trenchCoat.setTrenchPhotographyLink(newPhotography_linkOfTrench);
            return true;
        }
    }
    return false;
}

bool Repository::validID(int trenchID) {
    for (auto & trenchCoat : this->trenchCoats) {
        if (trenchCoat.getTrenchID() == trenchID) {
            return true;
        }
    }
    return false;
}

TrenchCoat Repository::getTrenchCoat(int trenchID) {
    for (auto & trenchCoat : this->trenchCoats) {
        if (trenchCoat.getTrenchID() == trenchID) {
            return trenchCoat;
        }
    }
    return TrenchCoat(-1, -1, "", -1, -1, "");
}

std::vector<TrenchCoat> Repository::getAllTrenchCoats() {
    return this->trenchCoats;
}

unsigned long int Repository::getSize() {
    return this->trenchCoats.size();
}

void Repository::setFileName(std::string newFileName) {
    this->FileName = std::move(newFileName);
}

std::string Repository::getFileName() const {
    return this->FileName;
}

void Repository::writeToFile() {
    std::ofstream file(this->FileName);
    for (auto &trenchCoat: this->trenchCoats) {
        file << trenchCoat.getTrenchID() << " "
             << trenchCoat.getTrenchSize() << " "
             << trenchCoat.getTrenchColour() << " "
             << trenchCoat.getTrenchPrice() << " "
             << trenchCoat.getTrenchQuantity() << " "
             << trenchCoat.getTrenchPhotographyLink() << " ";
    }
    file.close();
}

void Repository::readFromFile() {
    std::ifstream file(this->FileName);
    int id, sizeOfTrench, quantityOfTrench;
    float priceOfTrench;
    std::string colourOfTrench, photography_linkOfTrench;
    while (file >> id >> sizeOfTrench
                >> colourOfTrench
                >> priceOfTrench
                >> quantityOfTrench
                >> photography_linkOfTrench){
        this->addTrenchCoat(id,
                            sizeOfTrench,
                            colourOfTrench,
                            priceOfTrench,
                            quantityOfTrench,
                            photography_linkOfTrench);
    }
    file.close();
}

Repository::Repository() {
    this->FileName = "default.txt";
}
