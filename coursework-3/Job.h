#pragma once
enum Job {JAVA_D2, JAVA_D3, JAVA_D4, PROJECT_MANAGER, LAWYER, MATH_TEACHER, THERAPYST};

inline const char* toString(Job v) {
    switch (v)
    {
        case JAVA_D2: return "Middle Java Developer";
        case JAVA_D3: return "Senior Java Developer";
        case JAVA_D4: return "Java Team Lead";
        case PROJECT_MANAGER: return "Project Manager";
        case LAWYER: return "Lawyer";
        case MATH_TEACHER: return "Math Teacher";
        case THERAPYST: return "Therapyst";
        default: return "[Unknown job name]";
    }
}

void printAllJobNames() {
    for (int i = JAVA_D2; i <= THERAPYST; i++ ) {
        Job job = static_cast<Job>(i);
        cout << i << ". " << toString(job) << "\n";
   }
}