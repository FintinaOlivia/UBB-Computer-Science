//
// Created by theo on 26.04.2023.
//

#ifndef T1_913_FINTINA_OLIVIA_1_DOMAIN_H
#define T1_913_FINTINA_OLIVIA_1_DOMAIN_H


#include <string>

class Player {
private:
    std::string nameOfPlayer;
    std::string nationalityOfPlayer;
    std::string teamOfPlayer;
    int numberOfGoals;
public:
    Player();
    explicit Player(const std::string& nameOfPlayer,
           const std::string& nationalityOfPlayer,
           const std::string& teamOfPlayer,
           int numberOfGoals);
    ~Player();

    std::string getNameOfPlayer() const;
    std::string getTeamOfPlayer() const;
    int getNumberOfGoals() const;

    std::string toString();
};


#endif //T1_913_FINTINA_OLIVIA_1_DOMAIN_H
