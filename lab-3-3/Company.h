#pragma once
#include "./Utils.h"
#include "./LinkedList.h"

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

void printAllCompanies(LinkedList<Company> *companies) { // why array list?
    int i = 1;
    Node<Company>* tmp = companies->head;
    while (tmp) {
        cout << i << "' " << tmp->_data << "\n";
        tmp = tmp->next;
        i++;
    }
}
// inpout Conpany From Console
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

LinkedList<Company>* readCompanies(string filename, LinkedList<Company> *companies) { // why array list
    string line;    
    LinkedList<string> split;
    Node<Company>* tmp;

    ifstream infile(filename); // check for open

    while (getline(infile, line)) {
        tmp = companies->head;
        Company com;
        split = splitStringFoo(line, ",");
        com.name = split.get(0);
        com.jobType = static_cast<Scope>(stoi(split.get(1)));
        com.address = split.get(2);
        com.phone = split.get(3);
        bool companyExists = false;
        while (tmp != 0) {            
            if (tmp->_data.name == com.name) {
                tmp->_data = com;
                companyExists = true; 
            }
            tmp = tmp->next;
        };        
        if (!companyExists) {
            cout << "Creating company " << com.name << endl;
            companies->add(com);
        } else {
            cout << "Company " << com.name << " already exists" << endl;
        }
    }
    return companies;
}

void saveCompanies(string filename, LinkedList<Company> *companies) { // why array list
ofstream to_file(filename); 
    if (!to_file)
    {
        cout << "Error creating file" << endl;
        return;
    }
    string content;    
    Node<Company>* tmp = companies->head;

    while (tmp != 0) {            
        content.append(tmp->_data.name + ",");
        content.append(to_string(tmp->_data.jobType) + ',');
        content.append(tmp->_data.address + ",");
        content.append(tmp->_data.phone);
        content.append("\n");
        tmp = tmp->next;
    }
    to_file << content;
}