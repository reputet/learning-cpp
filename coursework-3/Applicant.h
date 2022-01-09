#include "./ArrayList.h"
using namespace std;

struct Applicant {
    string fullName;
    Scope jobType;
    ArrayList<Job> possibleJobs;
    int experience;
    int desiredSalary;
};

bool isMatch(Applicant a, Position p) {
    for(auto & job : a.possibleJobs) {
        if (job == p.job) {
            if (a.jobType == p.jobType &&
            p.salary >= a.desiredSalary &&
            p.desiredExperience <= a.experience) return true;
        }
    };
    return false;
}