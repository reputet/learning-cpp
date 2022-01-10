#include "./App.h"

int main() {

    ArrayList<Job> unprocessedJobs = ArrayList<Job>();
    ArrayList<Job> processedJobs = ArrayList<Job>();
    ArrayList<Applicant> applicants = ArrayList<Applicant>();
    ArrayList<Company> companies = ArrayList<Company>();

    bool exit = false;
    int choise, i;
    Applicant applicant;
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
                        case '1':
                            if (!applicants.isEmpty()) {
                                printAllAplicants(applicants);
                            } else {
                                cout << "\nNo candidates yet\n\n";
                            }
                            break;
                        case '4':
                            applicant = createApplicant();
                            applicants.add(applicant);
                            break;    
                        case '5':
                            i = stoi(getInput("Please enter the number of the candidate to remove:\n"));
                            applicants.remove(i - 1);
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

    applicants.add(a);
    printAllAplicants(applicants);

}

