#pragma once
#include "./ArrayList.h"

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
    }
}

