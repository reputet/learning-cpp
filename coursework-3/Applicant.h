#pragma once
#include "./ArrayList.h"
#include "./Utils.h"

struct Applicant {
    string fullName;
    Scope jobType;
    ArrayList<Job> possibleJobs;
    int experience;
    int desiredSalary;
    friend bool operator!= (const Applicant &c1, const Applicant &c2) {
        return (c1.fullName != c2.fullName || 
        c1.desiredSalary != c2.desiredSalary ||
        c1.experience != c2.experience ||
        c1.jobType != c2.jobType);
    }
    bool isMatch(Position p) {
        for(auto &job : possibleJobs) {
            if (job == p.job) {
                if (p.jobType == jobType &&
                p.salary >= desiredSalary &&
                p.desiredExperience <= experience) return true;
            }
        };
    return false;
    }
    
};

void printAllAplicants(ArrayList<Applicant> applicants) {
    int i = 1;
    for(auto &applicant : applicants) {
        cout << i << ". " << applicant.fullName << "\t" << toString(applicant.jobType) << "\n";
        cout << "\tPossible jobs:\n";
        for(auto &job : applicant.possibleJobs) {
            cout << "\t\t" << toString(job) << "\n";
        }
        cout << "\tExperience: " << applicant.experience << "\n";
        cout << "\tDesired salary: " << applicant.desiredSalary << "\n";
        i++;
    }
}

Applicant createApplicant() {
    Applicant a;
    a.fullName = getInput("Please enter the full name:\n");
    printAllScopes();
    int scope = stoi(getInput("Please select scope:\n"));
    a.jobType = static_cast<Scope>(scope);
    printAllJobNames();
    string jobNumbers = getInput("Please select all possible jobs divided by space (f.e. 1 3 5):\n");
    ArrayList<string> splittedNumbers = splitString(jobNumbers, " ");
    for(auto &number : splittedNumbers) {
        a.possibleJobs.add(static_cast<Job>(stoi(number)));
    }
    a.desiredSalary = stoi(getInput("Please enter the desired salary:\n"));
    a.experience = stoi(getInput("Please enter experience in years:\n"));
    return a;
}

ArrayList<Applicant> readFromFile(string fileName) {
    ArrayList<Applicant> result = ArrayList<Applicant>();

    return result;
}
