//
// Created by Th on 14/06/2023.
//

#ifndef EXAMPREP914_DEPARTMENT_H
#define EXAMPREP914_DEPARTMENT_H


#include <string>

class Department {
private:
    std::string name;
    std::string description;

public:
    Department();

    Department(const std::string &name, const std::string &description);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const std::string &getDescription() const;

    friend std::istream &operator>>(std::istream &is, Department &department);

    friend std::ostream &operator<<(std::ostream &os, const Department &department);

    ~Department() = default;
};


#endif //EXAMPREP914_DEPARTMENT_H
