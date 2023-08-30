//
// Created by User on 8/28/2023.
//
#include "job.h"

#include <iostream>

int main() {
    // Example 1: Junior C++ Programmer
    Programmer prog1;
    prog1.setLanguages({"C++"});
    prog1.setSeniority(Programmer::Seniority::JUNIOR);
    Job::addJob(&prog1);

    // Example 2: Mid Python Programmer
    Programmer prog2;
    prog2.setLanguages({"Python"});
    prog2.setSeniority(Programmer::Seniority::MID);
    Job::addJob(&prog2);

    // Example 3: Senior Java Programmer
    Programmer prog3;
    prog3.setLanguages({"Java"});
    prog3.setSeniority(Programmer::Seniority::SENIOR);
    Job::addJob(&prog3);

    // Example 4: First Officer with 1000 flight hours
    Pilot pilot1;
    pilot1.setRank(Pilot::Rank::FIRST_OFFICER);
    pilot1.setFlightHours(1000);
    Job::addJob(&pilot1);

    // Example 5: Captain with ATP License
    Pilot pilot2;
    pilot2.setRank(Pilot::Rank::CAPTAIN);
    pilot2.setLicenseType(Pilot::LicenseType::ATP);
    Job::addJob(&pilot2);

    // Examples 6-25: Other Programmers and Pilots with different attributes
    for (int i = 1; i <= 20; ++i) {
        Programmer *prog = new Programmer;
        Pilot *pilot = new Pilot;

        // Assign different attributes based on i
        if (i % 3 == 0) {
            prog->setLanguages({"JavaScript"});
            prog->setSeniority(Programmer::Seniority::JUNIOR);
        } else if (i % 3 == 1) {
            prog->setLanguages({"Rust", "Go"});
            prog->setSeniority(Programmer::Seniority::MID);
        } else {
            prog->setLanguages({"Scala"});
            prog->setSeniority(Programmer::Seniority::SENIOR);
        }

        if (i % 2 == 0) {
            pilot->setRank(Pilot::Rank::CAPTAIN);
            pilot->setLicenseType(Pilot::LicenseType::COMMERCIAL);
        } else {
            pilot->setRank(Pilot::Rank::FIRST_OFFICER);
            pilot->setLicenseType(Pilot::LicenseType::PRIVATE);
        }

        pilot->setFlightHours(i * 50);

        // Add to the job list
        Job::addJob(prog);
        Job::addJob(pilot);
    }

    // Display all jobs
    Job::displayAllJobs();

    return 0;
}


