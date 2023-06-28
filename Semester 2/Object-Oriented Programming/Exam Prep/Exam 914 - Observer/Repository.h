//
// Created by Th on 14/06/2023.
//

#ifndef EXAMPREP914_REPOSITORY_H
#define EXAMPREP914_REPOSITORY_H


#include <vector>
#include "Department.h"
#include "Observer.h"
#include "Volunteer.h"

class Repository {
private:
    std::vector<Department> departments;
    std::vector<Volunteer> volunteers;
    std::vector<Observer*> observers;
public:
    Repository();

    void loadDepartments();

    void loadVolunteers();

    std::vector<Department> getDepartments();

    std::vector<Volunteer> getVolunteers();

    static void sortByName(std::vector<Volunteer> &volunteers);

    void addVolunteer(const Volunteer& volunteer);

    void deleteVolunteer(const Volunteer& volunteer);

    void registerObserver(Observer* observer);

    void saveToFile();

    void notify();
};


#endif //EXAMPREP914_REPOSITORY_H
