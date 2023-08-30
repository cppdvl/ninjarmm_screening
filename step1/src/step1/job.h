//
// Created by User on 8/28/2023.
//

#ifndef STEP1_JOB_H
#define STEP1_JOB_H
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>

class Job;
namespace type
{
    //A helper namespace to help reduce typing
    using ul_ul     = std::pair<unsigned long, unsigned long>;
    using vstrings   = std::vector<std::string>;
    using uid_jobs  = std::map<unsigned long long, Job*>;
}



class Job {

protected:

    inline static unsigned long long _mID{0};

public:

    Job() {}

    virtual ~Job() = default;

protected:

    inline static type::uid_jobs mJobs{};
    unsigned long long mID{_mID++};

    unsigned long long  getID() const { return mID; }
    std::string         getHeaderString() const;

    enum class RateType {
        MONTHLY,
        HOURLY,
        WEEKLY
    };

    RateType mRateType{RateType::MONTHLY};
    type::ul_ul mIncomeRange{0, 0};
    std::string mPosition{};
    bool mIsRemotePosition{false};
    type::vstrings mResponsibilities{};
    std::string mCompany{};
    std::string mContact{};
public:

    void setRateType(RateType rateType);
    RateType getRateType() const;
    void setIncomeRange(type::ul_ul incomeRange);
    type::ul_ul getIncomeRange() const;
    void setPosition(std::string position);
    std::string getPosition() const;
    void setIsRemotePosition(bool isRemotePosition);
    bool getIsRemotePosition() const;
    void setResponsibilities(type::vstrings responsibilities);
    type::vstrings getResponsibilities() const;
    void setCompany(std::string company);
    std::string getCompany() const;
    void setContact(std::string contact);
    std::string getContact() const;

    static void                 displayAllJobs();
    static void                 deleteJob(unsigned long long jobId);
    static auto                 getJobById(unsigned long long jobId);
    static unsigned long long   addJob(Job* job);
    virtual void                displayJob() const = 0;

};

class Programmer : public Job
{
public:
    enum class Seniority
    {
        JUNIOR,
        MID,
        SENIOR
    };
    inline static const std::map<Programmer::Seniority, std::string> kSeniorityString {
            {Seniority::JUNIOR, "Junior"},
            {Seniority::MID, "Mid"},
            {Seniority::SENIOR, "Senior"}
    };
private:
    type::vstrings   mLanguages{"C++", "C", "C#"};
    Seniority       mSeniority{Seniority::JUNIOR};

public:
    //Getters and Setters
    void setLanguages(type::vstrings languages);
    type::vstrings getLanguages() const;

    void setSeniority(Seniority seniority);
    Seniority getSeniority() const;

    void displayJob() const override;
};

class Pilot: public Job
{
public:
    enum class Rank
    {
        FIRST_OFFICER,
        SENIOR_FIRST_OFFICER,
        CAPTAIN
    };
    enum class LicenseType
    {
        ATP,
        COMMERCIAL,
        PRIVATE
    };

private:
    Rank mRank{Rank::FIRST_OFFICER};
    LicenseType mLicenseType{LicenseType::ATP};
    unsigned long mFlightHours{0};

public:
    //Getters and Setters
    void setRank(Rank rank);
    Rank getRank() const;

    void setFlightHours(unsigned long flightHours);
    unsigned long getFlightHours() const;

    void setLicenseType(LicenseType licenseType);
    LicenseType getLicenseType() const;

    void displayJob() const override;
};

#endif //STEP1_JOB_H
