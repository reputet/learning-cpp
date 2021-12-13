#include "./App.h"

enum Scope {IT, MEDIA, MEDICINE, LAW, EDUCATION, GOVERNMENT};

inline const char* ToString(Scope v)
{
    switch (v)
    {
        case IT: return "IT";
        case MEDIA: return "Media";
        case MEDICINE: return "Medicine";
        case LAW: return "Law";
        case EDUCATION: return "Education";
        case GOVERNMENT: return "Government";
        default: return "[Unknown job scope]";
    }
}

enum Job {JAVA_D2, JAVA_D3, JAVA_D4, PROJECT_MANAGER, LAWYER, MATH_TEACHER, THERAPYST};

inline const char* ToString(Job v)
{
    switch (v)
    {
        case JAVA_D2: return "Middle Java Developer";
        case JAVA_D3: return "Senior Java Developer";
        case JAVA_D4: return "Java Team Lead";
        case PROJECT_MANAGER: return "Project Manager";
        case LAWYER: return "Lawyer";
        case MATH_TEACHER: return "Math Teacher";
        case THERAPYST: return "Therapyst";
        default: return "[Unknown job name]";
    }
}
struct Applicant {
    string fullName;
    Scope jobType;
    set<Job> possibleJobs;
    int experience;
    int desiredSalary;
};

struct Company {
    string name;
    Scope jobType;
    string address;
    string phone;
};

struct Position {
    Company company;
    Job job;
    Scope jobType;
    int salary;
    int desiredExperience;   
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

