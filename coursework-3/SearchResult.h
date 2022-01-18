#include "./App.h"

struct SearchResult {
    Applicant* applicant;
    LinkedList<Position> positions;

    friend bool operator< (const SearchResult &c1, const SearchResult &c2) {
        return (c1.applicant->desiredSalary < c2.applicant->desiredSalary) ||
        (c1.applicant->desiredSalary == c2.applicant->desiredSalary && 
        c1.applicant->fullName < c2.applicant->fullName);
    }

    friend ostream& operator<< (ostream& os, const SearchResult &c) {
        string s;
        for (Node<Position>* n = c.positions.head; n != 0; n = n->next) {
            s.append(toString(n->_data.job));
            s.append(", ");
        }
        s.append("\b\b ");
        return os << *c.applicant << endl << s << endl;
    }
};

LinkedList<SearchResult> findCandidates(ArrayList<Applicant> *applicants, Company *c, 
    ArrayList<Position> *allJobs) { // why array list?
    LinkedList<SearchResult> result = LinkedList<SearchResult>();
    LinkedList<Position> jobs = LinkedList<Position>();
    for(auto &a : *allJobs) {                
        if (a.company->name == c->name) {
            jobs.add(a);
        }
    }
    cout << "Company " << c->name << " has placed " << jobs.getSize() << " positions. \n";
    if (jobs.getSize() > 0) {
        for (auto &a : *applicants) {
            SearchResult sr = SearchResult();            
            for (Node<Position>* n = jobs.head; n != 0; n = n->next) {                
                if (a.isMatch(n->_data)) {
                    sr.applicant = &a;
                    sr.positions.add(n->_data);
                    
                }                
            }
            if (!sr.positions.isEmpty()) {
                result.add(sr);
            }
        }
    }
    result.sort();
    return result;
}

void printSearchResults(LinkedList<SearchResult> *results) {
    if (results->getSize() > 0) {
        results->printAllElements();
    } else {
        cout << "No candidates found.\n";
    }
}
