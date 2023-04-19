#pragma once
#include <string>

class TrenchCoat{
    private:
        int id;
        int size;
        std::string colour;
        float price;
        int quantity;
        std::string photographyLink;

    public:
        TrenchCoat();
        TrenchCoat(
                    int id,
                    int sizeOfTrench,
                    const std::string& colourOfTrench,
                    float priceOfTrench,
                    int quantityOfTrench,
                    const std::string& photography_linkOfTrench
                );

        int getTrenchID();
        int getTrenchSize();
        std::string getTrenchColour() const;

        float getTrenchPrice();
        int getTrenchQuantity();
        std::string getTrenchPhotographyLink() const;

        bool operator==(const TrenchCoat& trenchToCompare);

        void setTrenchID(int newID);
        void setTrenchSize(int newSize);
        void setTrenchColour(const std::string& newColour);
        void setTrenchPrice(float newPrice);
        void setTrenchQuantity(int newQuantity);
        void setTrenchPhotographyLink(const std::string& newPhotographyLink);
};
