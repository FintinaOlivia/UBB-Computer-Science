#include "Controller.h"

using namespace std;

Controller::Controller()
{
    this->repository = Repository();
}

Controller::Controller(const Repository& repository)
{
    this->repository = repository;
}

bool Controller::addTrenchCoat(int trenchID,
                               int trenchSize,
                               const std::string& trenchColour,
                               int trenchPrice,
                               int trenchQuantity,
                               const std::string& trenchPhotograph)
{
    if(this->repository.validID(trenchID))
        return false;

    return this->repository.addTrenchCoat(trenchID,
                                          trenchSize,
                                          trenchColour,
                                          trenchPrice,
                                          trenchQuantity,
                                          trenchPhotograph);
}

bool Controller::removeTrenchCoat(int trenchID)
{
    return this->repository.removeTrenchCoat(trenchID);
}

bool Controller::updateTrenchCoat(int trenchID,
                                  int trenchNewID,
                                  int trenchSize,
                                  const std::string& trenchColour,
                                  int trenchPrice,
                                  int trenchQuantity,
                                  const std::string& trenchPhotograph)
{
    return this->repository.updateTrenchCoat(trenchID,
                                             trenchNewID,
                                             trenchSize,
                                             trenchColour,
                                             trenchPrice,
                                             trenchQuantity,
                                             trenchPhotograph);
}

int Controller::trenchCoatExists(int trenchID)
{
    return this->repository.validID(trenchID);
}

TrenchCoat Controller::getTrenchCoat(int trenchID)
{
    return this->repository.getTrenchCoat(trenchID);
}

std::vector<TrenchCoat> Controller::getAllTrenchCoats()
{
    return this->repository.getAllTrenchCoats();
}

std::vector<TrenchCoat> Controller::filterBySize(int trenchSize)
{
    std::vector<TrenchCoat> filteredTrenchCoats;
    std::vector<TrenchCoat> allTrenchCoats = this->repository.getAllTrenchCoats();
    for (auto& trenchCoat : allTrenchCoats)
    {
        if (trenchCoat.getTrenchSize() == trenchSize)
        {
            filteredTrenchCoats.push_back(trenchCoat);
        }
    }
    return filteredTrenchCoats;
}

int Controller::getSize()
{
    return this->repository.getSize();
}

void Controller::setFileName(std::string newFileName)
{
    this->repository.setFileName(std::move(newFileName));
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

