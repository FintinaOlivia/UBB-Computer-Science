//
// Created by Th on 14/06/2023.
//

#ifndef EXAMPREP914_VOLUNTEER_H
#define EXAMPREP914_VOLUNTEER_H


#include <string>

class Volunteer {
private:
    std::string name;
    std::string email;
    std::vector<std::string> interests;
    std::string departament;
public:
    Volunteer();

    explicit Volunteer(const std::string &name, const std::string &email, const std::vector<std::string> &interests,
              const std::string &departament);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const std::string &getEmail() const;

    [[nodiscard]] const std::string &getInterests() const;

    [[nodiscard]] std::string getDepartament() const {
        return this->departament;
    }

    void setDepartament(const std::string& newDepartament) {
        this->departament = newDepartament;
    }

    friend std::istream &operator>>(std::istream &is, Volunteer &volunteer);

    std::string getDepartment();

    void setDepartment(const std::string &basicString);

    std::string toString();
};


#endif //EXAMPREP914_VOLUNTEER_H
