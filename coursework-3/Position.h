#pragma once
#include "./Utils.h"

struct Position {
    Company company;
    Job job;
    Scope jobType;
    int salary;
    int desiredExperience; 
    
    friend bool operator!= (const Position &c1, const Position &c2) {
        return (c1.company.name != c2.company.name || 
        c1.salary != c2.salary ||
        c1.desiredExperience != c2.desiredExperience ||
        c1.jobType != c2.jobType);
    }  
};

void printAllPositions(ArrayList<Position> positions) {
    int i = 1;
    for(auto &position : positions) {
        cout << i << ". " << position.company.name << "\t" << toString(position.job) << "\n";
        cout << "\tJob type: " << toString(position.jobType) << " Salary: " << position.salary << "\n";
        cout << "\tDesired experience: " << position.desiredExperience << "\n";
        i++;
    }
}

Position createPosition(ArrayList<Company> companies) {
    Position p;
    printAllScopes();
    p.jobType = static_cast<Scope>(stoi(getInput("Please select scope:\n")) - 1);
    printAllJobNames();
    p.job = static_cast<Job>(stoi(getInput("Please enter job:\n")) - 1);
    printAllCompanies(companies);
    p.company = companies.get(stoi(getInput("Please choose the company:\n")) - 1);
    p.salary = stoi(getInput("Please enter the salary:\n"));
    p.desiredExperience = stoi(getInput("Please enter desired experience in years:\n"));
    return p;
}