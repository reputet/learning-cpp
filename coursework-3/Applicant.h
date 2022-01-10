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

