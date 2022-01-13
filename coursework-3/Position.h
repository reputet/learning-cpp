#pragma once
#include "./Utils.h"

struct Position {
    Company* company;
    Job job;
    Scope jobType;
    int salary;
    int desiredExperience; 
    
    friend bool operator!= (const Position &c1, const Position &c2) {
        return (c1.company->name != c2.company->name || 
        c1.salary != c2.salary ||
        c1.desiredExperience != c2.desiredExperience ||
        c1.jobType != c2.jobType ||
        c1.job != c2.job);
    }  

    friend bool operator< (const Position &c1, const Position &c2) {
        return (c1.salary > c2.salary);
    }

    friend ostream& operator<< (ostream& os, const Position &c) {
        return os << "Scope: " << toString(c.company->jobType) << ", position: " << toString(c.job) 
            << ", company: " << c.company->name << ", desired experience: " << c.desiredExperience 
            << ", salary: " << c.salary;
    }
};

void printAllPositions(ArrayList<Position> positions) {
    int i = 1;
    for(auto &position : positions) {
        cout << i << ". " << position;
        i++;
    }
}

Position createPosition(ArrayList<Company> *companies) {
    Position p;
    printAllScopes();
    p.jobType = static_cast<Scope>(stoi(getInput("Please select scope:\n")) - 1);
    printAllJobNames();
    p.job = static_cast<Job>(stoi(getInput("Please enter job:\n")) - 1);
    printAllCompanies(companies);
    Company c = companies->get(stoi(getInput("Please choose the company:\n")) - 1);
    p.company = &c;
    p.salary = stoi(getInput("Please enter the salary:\n"));
    p.desiredExperience = stoi(getInput("Please enter desired experience in years:\n"));
    return p;
}

ArrayList<Position> readPositions(string filename, ArrayList<Company> *companies) {
    string line;
    ArrayList<Position> positionsList;
    ArrayList<string> split;

    ifstream infile(filename);
    
    while (getline(infile, line)) {
        Position pos = *(new Position());
        split = splitString(line, ",");
        pos.job = static_cast<Job>(stoi(split.get(1)));
        pos.jobType = static_cast<Scope>(stoi(split.get(2)));
        pos.salary = stoi(split.get(3));
        pos.desiredExperience = stoi(split.get(4));
        
        for(auto &c : *companies) {
            if (c.name == split.get(0)) {
                pos.company = &c;             
            }
        }
        if (pos.company == 0) {
            cout << "Creating company " << split.get(0) << endl;
            Company* com = createCompany(split.get(0), pos.jobType);
            pos.company = com;        
            companies->add(*com);
        }
        positionsList.add(pos);
    }

    return positionsList;
}