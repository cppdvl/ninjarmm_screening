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
    Job::addJob(prog1);
    prog1.setResponsibilities({"Write code", "Test code", "Fix bugs"});
    prog1.setIncomeRange({30000, 50000});

    // Example 2: Mid Python Programmer
    Programmer prog2;
    prog2.setLanguages({"Python"});
    prog2.setSeniority(Programmer::Seniority::MID);
    Job::addJob(prog2);
    prog2.setResponsibilities({"Write code", "Test code", "Fix bugs", "Write documentation"});
    prog2.setIncomeRange({50000, 70000});
    prog2.setRateType(Job::RateType::MONTHLY);


    // Example 3: Senior Java Programmer
    Programmer prog3;
    prog3.setLanguages({"Java"});
    prog3.setSeniority(Programmer::Seniority::SENIOR);
    Job::addJob(prog3);
    prog3.setResponsibilities({"Write code", "Test code", "Fix bugs", "Write documentation", "Write unit tests"});
    prog3.setIncomeRange({70000, 100000});
    prog3.setRateType(Job::RateType::MONTHLY);

    // Example 4: First Officer with 1000 flight hours
    Pilot pilot1;
    pilot1.setRank(Pilot::Rank::FIRST_OFFICER);
    pilot1.setFlightHours(1000);
    Job::addJob(pilot1);
    pilot1.setResponsibilities({"Fly the plane", "Assist the captain"});
    pilot1.setIncomeRange({50000, 70000});

    // Example 5: Captain with ATP License
    Pilot pilot2;
    pilot2.setRank(Pilot::Rank::CAPTAIN);
    pilot2.setLicenseType(Pilot::LicenseType::ATP);
    Job::addJob(pilot2);
    pilot2.setResponsibilities({"Fly the plane", "Manage the crew", "Manage the passengers"});
    pilot2.setIncomeRange({70000, 100000});

    // Examples 6-25: Other Programmers and Pilots with different attributes
    for (int i = 1; i <= 20; ++i) {
        Programmer *prog = new Programmer;
        Pilot *pilot = new Pilot;

        // Assign different attributes based on i
        if (i % 3 == 0) {
            prog->setLanguages({"JavaScript"});
            prog->setSeniority(Programmer::Seniority::JUNIOR);
            prog->setResponsibilities({"Write code", "Test code", "Fix bugs", "Write documentation"});
            prog->setIncomeRange({30000, 50000});

        } else if (i % 3 == 1) {
            prog->setLanguages({"Rust", "Go"});
            prog->setSeniority(Programmer::Seniority::MID);
            prog->setResponsibilities({"Write code", "Test code", "Fix bugs", "Write documentation", "Write unit tests"});
            prog->setIncomeRange({50000, 70000});

        } else {
            prog->setLanguages({"Scala"});
            prog->setSeniority(Programmer::Seniority::SENIOR);
            prog->setResponsibilities({"Write code", "Test code", "Fix bugs", "Write documentation", "Write unit tests", "Manage the team"});
            prog->setIncomeRange({70000, 100000});
        }

        if (i % 2 == 0) {
            pilot->setRank(Pilot::Rank::CAPTAIN);
            pilot->setLicenseType(Pilot::LicenseType::COMMERCIAL);
            pilot->setResponsibilities({"Fly the plane", "Manage the crew", "Manage the passengers"});
            pilot->setIncomeRange({70000, 100000});
            pilot->setFlightHours(i * 100);
        } else {
            pilot->setRank(Pilot::Rank::FIRST_OFFICER);
            pilot->setLicenseType(Pilot::LicenseType::PRIVATE);
            pilot->setResponsibilities({"Fly the plane", "Assist the captain"});
            pilot->setIncomeRange({50000, 70000});
            pilot->setFlightHours(i * 50);
        }

        // Add to the job list
        Job::addJob(prog);
        Job::addJob(pilot);
    }

    // Display all jobs
    Job::displayAllJobs();

    return 0;
}


