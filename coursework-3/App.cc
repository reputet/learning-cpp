#include "./App.h"

int main() {

    ArrayList<Position> unprocessedJobs = ArrayList<Position>();
    ArrayList<Position> processedJobs = ArrayList<Position>();
    ArrayList<Applicant> applicants = ArrayList<Applicant>();
    ArrayList<Company> companies = ArrayList<Company>();

    bool exit = false;
    string filename;
    int choise, i;
    Applicant applicant;
    Company company;
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
                                getche();
                            } else {
                                cout << "\nNo candidates yet\n\n";
                            }
                            break;
                        case '2':
                            filename = get_filename("Please, enter the filename: ");
                            applicants = readApplicants(filename);
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
                        case '1':
                            if (!companies.isEmpty()) {
                                printAllCompanies(companies);
                                getche();
                            } else {
                                cout << "\nNo companies yet\n\n";
                            }
                            break;
                        case '4':
                            company = createCompany();
                            companies.add(company);
                            break;    
                        case '5':
                            i = stoi(getInput("Please enter the number of the company to remove:\n"));
                            companies.remove(i - 1);
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
                        case '1':
                            if (!unprocessedJobs.isEmpty()) {
                                printAllPositions(unprocessedJobs);
                                getche();
                            } else {
                                cout << "\nNo positions yet\n\n";
                            }
                            break;
                        case '4':
                            unprocessedJobs.add(createPosition(companies));
                            break;    
                        case '5':
                            i = stoi(getInput("Please enter the number of the position to remove:\n"));
                            unprocessedJobs.remove(i - 1);
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

