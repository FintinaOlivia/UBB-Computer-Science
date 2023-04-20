#pragma once
#include <string>
#include <vector>
#include "Repository.h"

class Controller{
    private:
        Repository repository;

    public:
        Controller();
        explicit Controller(const Repository& repository);

        bool addTrenchCoat(int trenchID,
                       int trenchSize,
                       const std::string& trenchColour,
                       int trenchPrice,
                       int trenchQuantity,
                       const std::string& trenchPhotograph);

        bool removeTrenchCoat(int trenchID);
        bool updateTrenchCoat(int trenchID, 
                                int trenchNewID,
                                int trenchSize, 
                                const std::string& trenchColour,
                                int trenchPrice, 
                                int trenchQuantity, 
                                const std::string& trenchPhotograph);

        int trenchCoatExists(int trenchID);
        TrenchCoat getTrenchCoat(int trenchID);
        std::vector<TrenchCoat> getAllTrenchCoats();
        std::vector<TrenchCoat> filterBySize(int trenchSize);
        
        int getSize();
        void setFileName(std::string newFileName);
        std::string getFileName() const;
        
        void saveProgress();
        void loadFromFile();
};