#pragma once
#include "./ArrayList.h"
#include "./Utils.h"
// Задание №9. Обеспечить эффективное хранение данных и быстрый поиск информации в бюро по трудоустройству. 
// Должна быть представлена информация о: 
//  работодателях (название, сфера деятельности, адрес, телефон и т.п.);
//  предлагаемых ими вакансиях (наименование должности, график работы, оклад, 
// требования по образованию и квалификации, предложения и заявки работодателей и т.д.);
//  соискателях (фамилия, имя, отчество, возможные должности, сфера деятельности, 
// стаж работы, ожидаемый оклад и т.д.).
// Соискатель должен получать список подходящих по его желаниям 
// предложений от работодателей, работодатель должен получать список всех 
// подходящих под его требования работников. Должны добавляться новые соискатели, 
// работодатели, вакансии. В случае совпадения интересов работодателя и соискателя 
// вакансия должна быть занята и перемещена в список удовлетворённых заявок
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

    friend ostream& operator<< (ostream& os, const Applicant &c) {
        return os << c.fullName;
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

    ifstream infile(filename);
    
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