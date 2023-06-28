//
// Created by Th on 15/06/2023.
//

#ifndef MV_REPOSITORY_H
#define MV_REPOSITORY_H


#include <vector>
#include "../Domain/Student.h"

class Repository {
private:
    std::vector<Student> students;
    std::string fileName;

public:
    Repository(const std::string& filename);

    void add(const Student& student);
    void remove(const Student& student);
    int getSize() const { return students.size(); }
    std::vector<Student>& getStudents() { return this->students; }

private:
    void readFromFile();
    void writeToFile();

};


#endif //MV_REPOSITORY_H
