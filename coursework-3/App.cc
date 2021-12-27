#include "./App.h"

int main() {
    Applicant a;
    a.fullName = "Alex R. Jones";
    a.jobType = IT;
    a.possibleJobs = {JAVA_D3, JAVA_D4, PROJECT_MANAGER, JAVA_D4};
    a.experience = 5;
    a.desiredSalary = 300000;
    
    Company c;
    c.name = "Epam Systems";
    c.jobType = IT;
    c.address = "Spb, Zastavskaya Ulitsa, 22/2";
    c.phone = "8 (812) 611-10-94";

    Position p;
    p.company = c;
    p.job = PROJECT_MANAGER;
    p.jobType = p.company.jobType;
    p.salary = 320000;
    p.desiredExperience = 4;

    cout << isMatch(a, p) << "\n";
    
    p.salary = 290000;
    cout << isMatch(a, p) << "\n";
}

