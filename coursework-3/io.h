ArrayList<Applicant> readApplicants(string filename) {
    string line;
    string jobNumbers;
    int scope;
    ArrayList<Applicant> applicantsList;
    ArrayList<string> split;
    ArrayList<string> splittedNumbers;

    ifstream infile(filename);
    Applicant applicant;
    while (getline(infile, line)) {
        split = splitString(line, ",");
        applicant.fullName = split.get(0);
        scope = stoi(split.get(1));
        applicant.jobType = static_cast<Scope>(scope);
        jobNumbers = split.get(2);
        splittedNumbers = splitString(jobNumbers, " ");
        for(auto &number : splittedNumbers) {
            applicant.possibleJobs.add(static_cast<Job>(stoi(number)));
        }
        applicant.experience = stoi(split.get(3));
        applicant.desiredSalary = stoi(split.get(4));
        applicantsList.add(applicant);
    }

    return applicantsList;
}
