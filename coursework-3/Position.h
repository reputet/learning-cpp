#pragma once
#include "./Utils.h"

struct Position {
    Company company;
    Job job;
    Scope jobType;
    int salary;
    int desiredExperience;   
};

void printAllPositions(ArrayList<Position> positions) {
    int i = 1;
    for(auto &position : positions) {
        cout << i << ". " << position.company.name << "\t" << toString(position.job) << "\n";
        cout << "\tJob type: " << toString(position.jobType) << " Salary: " << position.salary << "\n";
        cout << "\tDesired experience: " << position.desiredExperience << "\n";
        i++;
    }
    getche();
}

Position createPosition(ArrayList<Company> companies) {
    Position p;
    printAllScopes();
    p.jobType = static_cast<Scope>(stoi(getInput("Please select scope:\n")) - 1);
    printAllJobNames();
    p.job = static_cast<Job>(stoi(getInput("Please enter job:\n")) - 1);
    printAllCompanies(companies);
    p.salary = stoi(getInput("Please enter the salary:\n"));
    p.desiredExperience = stoi(getInput("Please enter desired experience in years:\n"));
    return p;
}