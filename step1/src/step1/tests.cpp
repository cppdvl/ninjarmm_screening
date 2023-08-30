//
// Created by Julian Guarin on 30/08/23.
//

#include <gtest/gtest.h>
#include "job.h"

// Test fixtures
class JobTest : public ::testing::Test {
 protected:
    void SetUp() override {}

    void TearDown() override {}
};

class ProgrammerTest : public ::testing::Test {
 protected:

    void SetUp() override {}

    void TearDown() override {}
};

class PilotTest : public ::testing::Test {
 protected:
    void SetUp() override {}

    void TearDown() override {}
};

// Test cases for the Job class
TEST_F(JobTest, SetAndGetRateType) {
Job job;
job.setRateType(Job::RateType::HOURLY);
EXPECT_EQ(job.getRateType(), Job::RateType::HOURLY);
}

TEST_F(JobTest, AddAndGetResponsibilities) {
Job job;
type::vstrings responsibilities = {"Task 1", "Task 2"};
job.setResponsibilities(responsibilities);
EXPECT_EQ(job.getResponsibilities(), responsibilities);
}

TEST_F(JobTest, SetAndGetCompany) {
Job job;
job.setCompany("Acme Inc.");
EXPECT_EQ(job.getCompany(), "Acme Inc.");
}

TEST_F(JobTest, SetAndGetContact) {
Job job;
job.setContact("John Doe");
EXPECT_EQ(job.getContact(), "John Doe");
}

// Test cases for the Programmer class
TEST_F(ProgrammerTest, SetAndGetLanguages) {
Programmer programmer;
type::vstrings languages = {"Python", "Java"};
programmer.setLanguages(languages);
EXPECT_EQ(programmer.getLanguages(), languages);
}

TEST_F(ProgrammerTest, SetAndGetSeniority) {
Programmer programmer;
programmer.setSeniority(Programmer::Seniority::SENIOR);
EXPECT_EQ(programmer.getSeniority(), Programmer::Seniority::SENIOR);
}


// Test cases for the Pilot class
TEST_F(PilotTest, SetAndGetRank) {
Pilot pilot;
pilot.setRank(Pilot::Rank::CAPTAIN);
EXPECT_EQ(pilot.getRank(), Pilot::Rank::CAPTAIN);
}

TEST_F(PilotTest, SetAndGetFlightHours) {
Pilot pilot;
pilot.setFlightHours(1500);
EXPECT_EQ(pilot.getFlightHours(), 1500);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

