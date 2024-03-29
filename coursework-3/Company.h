#pragma once
#include "./Utils.h"

using namespace std;
struct Company {
    string name;
    Scope jobType;
    string address;
    string phone;

    friend ostream& operator<< (ostream& os, const Company &c) {
        return os << c.name << ", scope: " << toString(c.jobType) << ", address: " << c.address 
            << ", phone: " << c.phone;
    }
    
    friend bool operator< (const Company &c1, const Company &c2) {
        return (c1.name < c2.name);
    }

    friend bool operator!= (const Company &c1, const Company &c2) {
        return (c1.name != c2.name);
    }
    
    Company() {}
    Company(string _name) {
        name = _name;
    }
};

void printAllCompanies(ArrayList<Company> *companies) { // why array list?
    int i = 1;
    for(auto company : *companies) {
        cout << i << ". " <<  company << "\n";
        i++;
    }
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

Company createCompany(string name, Scope scope) { 
    Company result;
    result.name = name;    
    result.jobType = scope;
    result.address = "Not present yet";
    result.phone = "Not present yet";
    return result;
}

ArrayList<Company> readCompanies(string filename, ArrayList<Company> *companies) { // why array list
    string line;    
    ArrayList<string> split;

    ifstream infile(filename); // check for open

    while (getline(infile, line)) {
        Company com;
        split = splitString(line, ",");
        com.name = split.get(0);
        com.jobType = static_cast<Scope>(stoi(split.get(1)));
        com.address = split.get(2);
        com.phone = split.get(3);
        bool companyExists = false;
        for(auto &c : *companies) {
            if (c.name == com.name) {
                c = com; // recopy         
                companyExists = true; 
            }
        }
        if (!companyExists) {
            cout << "Creating company " << com.name << endl;
            companies->add(com);
        }        
    }
    return *companies;
}

void saveCompanies(string filename, ArrayList<Company> *companies) { // why array list
ofstream to_file(filename); 
    if (!to_file)
    {
        cout << "Error creating file" << endl;
        return;
    }
    string content;    
    for(auto &company : *companies) {
        content.append(company.name + ",");
        content.append(to_string(company.jobType) + ',');
        content.append(company.address + ",");
        content.append(company.phone);
        content.append("\n");
    }
    content.append("\n");
    to_file << content;
}
