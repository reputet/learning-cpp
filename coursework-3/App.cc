#include "./App.h"

int main() {
    bool exit = false;
    int choise;
    while (!exit) {
        printCommonMenu();
        choise = getche();
        cout << "\n";
        switch (choise) {            
            case '0':
                exit = true;
                break;
            case '1':    
                while(!exit) {
                    printApplicantsMenu();
                    choise = getche();
                    cout << "\n";
                    switch (choise) { 
                        case '0':
                            exit = true;
                            break;
                    }           
                }
            case '2':    
                while(!exit) {
                    printCompaniesMenu();
                    choise = getche();
                    cout << "\n";
                    switch (choise) { 
                        case '0':
                            exit = true;
                            break;
                    }           
                }
            case '3':    
                while(!exit) {
                    printPositionsMenu();
                    choise = getche();
                    cout << "\n";
                    switch (choise) { 
                        case '0':
                            exit = true;
                            break;
                    }           
                }
            case '4':
                while(!exit) {
                    cout << "\nTO BE IMPLEMENTED\n";                            
                    getche();
                    exit = true;
                }
            default:
                exit = false;
        }
    };
    
    

    Applicant a;
    a.fullName = "Alex R. Jones";
    a.jobType = IT;
    a.possibleJobs = ArrayList<Job>();
    a.possibleJobs.add(JAVA_D3);
    a.possibleJobs.add(JAVA_D4);
    a.possibleJobs.add(JAVA_D4);
    a.possibleJobs.add(PROJECT_MANAGER);
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

    cout << "is match: " << a.isMatch(p) << "\n";
    
    p.salary = 290000;
    cout << "second match is " << a.isMatch(p) << "\n";
    
    a.possibleJobs.add(PROJECT_MANAGER, 1);

    cout << "index of pm is " << a.possibleJobs.getIndex(PROJECT_MANAGER) << "\n";

    a.possibleJobs.remove(1);
    cout << "index of pm is " << a.possibleJobs.getIndex(PROJECT_MANAGER) << "\n";
    cout << "size is " << a.possibleJobs.getSize() << "\n";


}

