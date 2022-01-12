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

void write_to_file(string filename, ArrayList<Applicant> applicants) {
    ofstream to_file(filename);
    string content;
    int i = 1;
    for(auto &applicant : applicants) {
        content.append(applicant.fullName + ",");
        content.append(to_string(applicant.jobType) + ',');
        string job_content;
        for(auto &job : applicant.possibleJobs) {
            job_content.append(to_string(job) + ' ');
        }
        content.append(job_content.substr(0, job_content.length() - 1));
        content.append(",");
        content.append(to_string(applicant.experience) + ",");
        content.append(to_string(applicant.desiredSalary));
        content.append("\n");
        i++;
    }
    content.append("\n");
    to_file << content;
}
