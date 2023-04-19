#include "Controller.h"

using namespace std;

Controller::Controller()
{
    this->repository = Repository();
}

Controller::Controller(Repository repository)
{
    this->repository = repository;
}

bool Controller::addTrenchCoat(int trenchID, 
                                int trenchSize, 
                                std::string trenchColour, 
                                int trenchPrice, 
                                int trenchQuantity, 
                                std::string trenchPhotograph)
{

    for(int i = 0; i < this->repository.getSize(); i++)
        if(this->repository.getAllTrenchCoats()[i].getTrenchID() == trenchID){
            return false;
        }

    this->repository.addTrenchCoat(trenchID, 
                                    trenchSize, 
                                    trenchColour, 
                                    trenchPrice, 
                                    trenchQuantity, 
                                    trenchPhotograph);
    return true;
   
}

void Controller::removeTrenchCoat(int trenchID)
{
    this->repository.removeTrenchCoat(trenchID);
}

bool Controller::updateTrenchCoat(int trenchID, 
                                    int trenchNewID,
                                    int trenchSize, 
                                    std::string trenchColour, 
                                    int trenchPrice, 
                                    int trenchQuantity, 
                                    std::string trenchPhotograph)
{
    if(!this->trenchCoatExists(trenchID)){
        return false;
    }else{
        this->repository.updateTrenchCoat(trenchID,
                                        trenchNewID,
                                        trenchSize, 
                                        trenchColour, 
                                        trenchPrice, 
                                        trenchQuantity, 
                                        trenchPhotograph);
        return true;
    }
}

int Controller::trenchCoatExists(int trenchID)
{
    int counter = 0;
    for(int i = 0; i < this->repository.getSize(); i++)
        if(this->repository.getAllTrenchCoats()[i].getTrenchID() == trenchID) {
            counter++;
        }
    return counter;
}

TrenchCoat Controller::getTrenchCoat(int trenchID)
{
    return this->repository.getTrenchCoat(trenchID);
    
}

dynamicVector<TrenchCoat> Controller::getAllTrenchCoats()
{
    return this->repository.getAllTrenchCoats();
}

dynamicVector<TrenchCoat> Controller::filterBySize(int trenchSize)
{

    dynamicVector<TrenchCoat> filteredTrenchCoats;
    dynamicVector<TrenchCoat> allTrenchCoats = this->repository.getAllTrenchCoats();

    for(int i = 0; i < this->repository.getSize(); i++)
        if(allTrenchCoats[i].getTrenchSize() == trenchSize)
            filteredTrenchCoats.append(allTrenchCoats[i]);
    
    return filteredTrenchCoats;
}

int Controller::getSize()
{
    return this->repository.getSize();
}

void Controller::setFileName(std::string newFileName)
{
    this->repository.setFileName(newFileName);
}

std::string Controller::getFileName() const
{
    return this->repository.getFileName();
}

void Controller::saveProgress()
{
    this->repository.writeToFile();
}

void Controller::loadFromFile()
{
    this->repository.readFromFile();
}
