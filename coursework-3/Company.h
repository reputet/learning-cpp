#pragma once
#include "./Utils.h"

using namespace std;
struct Company {
    string name;
    Scope jobType;
    string address;
    string phone;
};

void printAllCompanies(ArrayList<Company> companies) {
    int i = 1;
    for(auto &company : companies) {
        cout << i << ". " << company.name << "\t" << toString(company.jobType) << "\n";
        cout << "\tAddress: " << company.address << "\n";
        cout << "\tPhone: " << company.phone << "\n";
        i++;
    }
    getche();
}

Company createCompany() {
    Company result = Company();
    result.name = getInput("Please enter the company name:\n");
    printAllScopes();
    result.jobType = static_cast<Scope>(stoi(getInput("Please select scope:\n")) - 1);
    result.address = getInput("Please enter the company address:\n");
    result.phone = getInput("Please enter the phone:\n");
    return result;
}