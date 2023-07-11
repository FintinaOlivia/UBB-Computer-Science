//
// Created by Th on 15/06/2023.
//

#ifndef MV_STUDENT_H
#define MV_STUDENT_H


#include <string>
#include <sstream>
#include <vector>

class Student {
private:
    std::string name;
    std::string group;
    double labGrade;
    double seminarGrade;
public:
    Student() {};
    Student(const std::string& name, const std::string& group, double labGrade, double seminarGrade) :
        name(name),
        group(group),
        labGrade(labGrade),
        seminarGrade(seminarGrade) {};

    std::string getName() const { return this->name;    };
    std::string getGroup() const { return this->group;  };
    double getLabGrade() const { return this->labGrade; };
    double getSeminarGrade() const { return this->seminarGrade; };

    void setName(const std::string& name) { this->name = name; };
    void setGroup(const std::string& group) { this->group = group; };
    void setLabGrade(double labGrade) { this->labGrade = labGrade; };
    void setSeminarGrade(double seminarGrade) { this->seminarGrade = seminarGrade; };

    bool operator==(const Student& student) const {
        return this->name == student.name;
    }

    friend std::istream& operator>>(std::istream& is, Student& student) {
        std::string line;
        getline(is, line);

        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 4) {
            return is;
        }


        student.name = tokens[0];
        student.group = tokens[1];
        student.labGrade = std::stod(tokens[2]);
        student.seminarGrade = std::stod(tokens[3]);

        return is;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const Student& student) {
        outputStream << student.getName() << " " << student.getGroup() << "" << student.getLabGrade() << " " << student.getSeminarGrade() << std::endl;
        return outputStream;
    }

};


#endif //MV_STUDENT_H
