#include "./App.h"

int main() {

    ArrayList<Position> unprocessedJobs = ArrayList<Position>();
    ArrayList<Position> processedJobs = ArrayList<Position>();
    ArrayList<Applicant> applicants = ArrayList<Applicant>();
    ArrayList<Applicant> hired = ArrayList<Applicant>();
    ArrayList<Company> companies = ArrayList<Company>();

    bool exit = false;
    string filename;
    string output_file;
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
                            filename = getFilename("Please, enter the filename: ");
                            applicants = readApplicants(filename);
                            break;
                        case '3':
                            output_file = get_input("Enter the output file name: ");
                            write_to_file(output_file, applicants);
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
                            if (a.isMatch(p) && hired.getIndex(a) == -1 && processedJobs.getIndex(p) == -1) {
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

        LinkedList<Applicant> list = LinkedList<Applicant>();
        for (auto &a : applicants) {
            list.add(a);
        }
        list.printAllElements();
}
