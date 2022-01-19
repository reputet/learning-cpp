#include "./App.h"

int main() {

    LinkedList<Company>* companies = new LinkedList<Company>();
    // companies = readCompanies("companies.csv", &companies);

    bool exit = false;
    string filename;
    string output_file;
    int choise, i;
    Company company;
    while(!exit) {
        printCompaniesMenu();
        choise = getche();
        cout << "\n";
        switch (choise) { 
            case '0':
                companies->clear();
                exit = true;

                break;
            case '1':
                if (!companies->isEmpty()) {
                    printAllCompanies(companies);
                    getche();
                } else {
                    cout << "\nNo companies yet\n\n";
                }
                break;
            case '2':
                filename = getFilename("Please, enter the filename: ");
                companies = readCompanies(filename, companies);
                break;
            case '3':
                output_file = getInput("Enter the output file name: "); // check for open
                saveCompanies(output_file, companies);
                break;
            case '4':
                company = createCompany();
                companies->add(company);
                break;    
            case '5':
                i = stoi(getInput("Please enter the number of the company to remove:\n"));
                companies->remove(i - 1);
                break;
        };
    };
};
