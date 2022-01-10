#include "./App.h"

int main() {

    ArrayList<Position> unprocessedJobs = ArrayList<Position>();
    ArrayList<Position> processedJobs = ArrayList<Position>();
    ArrayList<Applicant> applicants = ArrayList<Applicant>();
    ArrayList<Applicant> hired = ArrayList<Applicant>();
    ArrayList<Company> companies = ArrayList<Company>();


    Applicant a;
    a.fullName = "Alex R. Jones";
    a.jobType = IT;
    a.possibleJobs = ArrayList<Job>();
    a.possibleJobs.add(JAVA_D3);
    a.possibleJobs.add(JAVA_D4);
    a.possibleJobs.add(PROJECT_MANAGER);
    a.experience = 5;
    a.desiredSalary = 300000;
    applicants.add(a);
    
    Applicant a2;
    a2.fullName = "Michael S. Smith";
    a2.jobType = IT;
    a2.possibleJobs = ArrayList<Job>();
    a2.possibleJobs.add(JAVA_D4);
    a2.possibleJobs.add(PROJECT_MANAGER);
    a2.experience = 6;
    a2.desiredSalary = 350000;
    applicants.add(a2);    

    Company c;
    c.name = "Epam Systems";
    c.jobType = IT;
    c.address = "Spb, Zastavskaya Ulitsa, 22/2";
    c.phone = "8 (812) 611-10-94";
    companies.add(c);

    Company c2;
    c2.name = "Luxoft Tech.";
    c2.jobType = IT;
    c2.address = "Spb, Polyustrovskiy pr., 140";
    c2.phone = "8 (812) 123-45-67";
    companies.add(c2);

    Position p;
    p.company = c;
    p.job = PROJECT_MANAGER;
    p.jobType = p.company.jobType;
    p.salary = 320000;
    p.desiredExperience = 4;
    unprocessedJobs.add(p);

    Position p2;
    p2.company = c;
    p2.job = JAVA_D4;
    p2.jobType = p2.company.jobType;
    p2.salary = 340000;
    p2.desiredExperience = 3;
    unprocessedJobs.add(p2);

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
                            break;
                        case '6':
                            if (!processedJobs.isEmpty()) {
                                printAllPositions(processedJobs);
                                getche();
                            } else {
                                cout << "\nNo closed positions yet\n\n";
                            }
                            break;
                    }           
                }
            case '4':   
                while(!exit) {         
                    for(auto &p : unprocessedJobs) {
                        for(auto &a : applicants) {
                            if (a.isMatch(p)) {
                                cout << "Candidate " << a.fullName << " matches position " << toString(p.job) <<
                                " from " << p.company.name << "\n";
                                processedJobs.add(p);
                                hired.add(a);                    
                            }
                        }
                        for(auto &a : hired) {
                            if (applicants.getIndex(a) != -1) {
                                applicants.remove(applicants.getIndex(a));
                            }
                        }
                    }                    
                    for(auto &a : processedJobs) {
                        if (unprocessedJobs.getIndex(a) != -1)
                        unprocessedJobs.remove(unprocessedJobs.getIndex(a));
                    }
                    exit = true;
                }

            default:
                exit = false;
        }
    };
}
