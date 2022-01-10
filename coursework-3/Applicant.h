#pragma once
#include "./ArrayList.h"
#include "./Utils.h"
struct Applicant {
    string fullName;
    Scope jobType;
    ArrayList<Job> possibleJobs;
    int experience;
    int desiredSalary;

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
        cout << i << ". " << applicant.fullName << "\t" << ToString(applicant.jobType) << "\n";
        cout << "\tPossible jobs:\n";
        for(auto &job : applicant.possibleJobs) {
            cout << "\t\t" << ToString(job) << "\n";
        }
        cout << "\tExperience: " << applicant.experience << "\n";
        cout << "\tDesired salary: " << applicant.desiredSalary << "\n";
        i++;
    }
    getche();
}

Applicant createApplicant() {
    Applicant a;
    a.fullName = getInput("Please enter the full name:\n");
    printAllScopes();
    int scope = stoi(getInput("Please select scope:\n"));
    a.jobType = static_cast<Scope>(scope);
    printAllJobNames();
    string jobNumbers = getInput("Please select all possible jobs (f.e. 135):\n");
    for(int i = 0; i < jobNumbers.length(); i++) {
        a.possibleJobs.add(static_cast<Job>(jobNumbers[i] - '0'));
    }
    a.desiredSalary = stoi(getInput("Please enter the desired salary:\n"));
    a.experience = stoi(getInput("Please enter experience in years:\n"));
    return a;
}

