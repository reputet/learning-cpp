#pragma once
#include "./ArrayList.h"
#include "./LinkedList.h"
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

    friend bool operator< (const Applicant &c1, const Applicant &c2) {
        return (c1.desiredSalary < c2.desiredSalary) ||
        (c1.desiredSalary == c2.desiredSalary && c1.fullName < c2.fullName);
    }

    friend ostream& operator<< (ostream& os, const Applicant &c) {
        return os << "Applicant: " << c.fullName << ", experience: " << c.experience << ", desired salary: " 
            <<  c.desiredSalary;
    }

    bool isMatch(Position p) {
        for(auto &job : possibleJobs) {
            if (job == p.job &&
                p.jobType == jobType &&
                p.salary >= desiredSalary &&
                p.desiredExperience <= experience) return true;    
        };
    return false;
    }
    
};

void printAllAplicants(ArrayList<Applicant> applicants) { // why array list?
    int i = 1;
    for(auto &applicant : applicants) {
        cout << i << ". " << applicant << endl;
        cout << "\tPossible jobs: ";
        for(auto &job : applicant.possibleJobs) {
            cout << toString(job) << ", ";
        }
        cout << "\b\b \n";
        i++;
    }
}

Applicant createApplicant() {
    Applicant a;
    a.fullName = getInput("Please enter the full name:\n");
    printAllScopes();
    int scope = stoi(getInput("Please select scope:\n")) - 1;
    a.jobType = static_cast<Scope>(scope);
    printAllJobNames();
    string jobNumbers = getInput("Please select all possible jobs divided by space (f.e. 1 3 5):\n");
    ArrayList<string> splittedNumbers = splitString(jobNumbers, " ");
    for(auto &number : splittedNumbers) {
        a.possibleJobs.add(static_cast<Job>(stoi(number) - 1));
    }
    a.desiredSalary = stoi(getInput("Please enter the desired salary:\n"));
    a.experience = stoi(getInput("Please enter experience in years:\n"));
    return a;
}

ArrayList<Applicant> readApplicants(string filename) {
    string line;
    string jobNumbers;
    int scope;
    ArrayList<Applicant> applicantsList;
    ArrayList<string> split;
    ArrayList<string> splittedNumbers;

    ifstream infile(filename); // check for open
    
    while (getline(infile, line)) {
        Applicant applicant = Applicant();
        split = splitString(line, ",");
        applicant.fullName = split.get(0);
        scope = stoi(split.get(1));
        applicant.jobType = static_cast<Scope>(scope);
        jobNumbers = split.get(2);
        splittedNumbers = splitString(jobNumbers, " ");
        for(auto &number : splittedNumbers) {
            applicant.possibleJobs.add(static_cast<Job>(stoi(number)));
        }
        applicant.experience = stoi(split.get(3));
        applicant.desiredSalary = stoi(split.get(4));
        applicantsList.add(applicant);
    }

    return applicantsList;
}

void saveApplicants(string filename, ArrayList<Applicant> applicants) {
    ofstream to_file(filename); 
    if (!to_file)
    {
        cout << "Error creating file" << endl;
        return;
    }

    string content;
    for(auto &applicant : applicants) {
        content.append(applicant.fullName + ",");
        content.append(to_string(applicant.jobType) + ',');
        string job_content;
        for(auto &job : applicant.possibleJobs) {
            job_content.append(to_string(job) + ' ');
        }
        content.append(job_content.substr(0, job_content.length() - 1));
        content.append(",");
        content.append(to_string(applicant.experience) + ",");
        content.append(to_string(applicant.desiredSalary));
        content.append("\n");
    }
    content.append("\n");
    to_file << content;
}

LinkedList<Position> findPositions(Applicant* applicant, ArrayList<Position>* allJobs) {
    LinkedList<Position> result = LinkedList<Position>();
    for(auto &a : *allJobs) {        
        if (applicant->isMatch(a)) {
            result.add(a);                    
        }
    }
    result.sort();
    return result;
}

