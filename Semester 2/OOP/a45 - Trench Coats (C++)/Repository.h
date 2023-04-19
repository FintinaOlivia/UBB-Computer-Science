#pragma once
#include <string>
#include "Domain.h"
#include "DynamicArray.h"

class Repository{
    private:
        dynamicVector<TrenchCoat> trenchCoats;
        std::string FileName;
        
        public:
            Repository();
            Repository(std::string FileName);

            void addTrenchCoat(int id,
                    int sizeOfTrench,
                    const std::string& colourOfTrench,
                    float priceOfTrench,
                    int quantityOfTrench,
                    const std::string& photography_linkOfTrench);

            void removeTrenchCoat(int trenchID);
            void updateTrenchCoat(int trenchID, 
                                    int newID,
                                    int newSizeOfTrench, 
                                    const std::string& newColourOfTrench, 
                                    float newPriceOfTrench, 
                                    int newQuantityOfTrench, 
                                    const std::string& newPhotography_linkOfTrench);

            bool validID(int trenchID);
            TrenchCoat getTrenchCoat(int trenchID);
            dynamicVector<TrenchCoat> getAllTrenchCoats();

            int getSize();
            void setFileName(std::string newFileName);
            std::string getFileName() const;
            void writeToFile();
            void readFromFile();

};