/**
 * @file job.h
 * @brief This file contains the declaration of the Job class and its derived classes. Ninja One Screening Test.
 * @author Julian Andres Guarin Reyes.
 */
#ifndef STEP1_JOB_H
#define STEP1_JOB_H
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <utility>
#include <iostream>


class Job;
/// @brief A helper namespace to help reduce typing
namespace type
{
    //A helper namespace to help reduce typing
    using ul_ul     = std::pair<unsigned long, unsigned long>;
    using vstrings  = std::vector<std::string>;
    using SPJob     = std::shared_ptr<Job>;
    using uid_jobs  = std::map<unsigned long long, Job>;
}


/// @brief The Job class is the base class for all jobs.
class Job {

protected:
    /// @brief A static counter to keep track of the number of jobs created.
    inline static unsigned long long _mID{0};

public:
    /// @brief The default constructor.
    Job() {
        std::cout << "Job @" << std::hex << (unsigned long long) this << " created." << std::endl;
    }

    Job(const Job& other) = default;               /// @brief The default copy constructor.
    Job(Job&& other) = default;                    /// @brief The default move constructor.
    Job& operator=(const Job& other) = default;    /// @brief The default copy assignment operator.
    Job& operator=(Job&& other) = default;         /// @brief The default move assignment operator.

    /// @brief The default destructor.
    virtual ~Job() {
        std::cout << "Job @" << std::hex << (unsigned long long) this << " destroyed." << std::endl;
    }

    /// @brief The type of rate for the job.
    enum class RateType {
        MONTHLY,    /// @brief Monthly rate.
        HOURLY,     /// @brief Hourly rate.
        WEEKLY      /// @brief Weekly rate.
    };

protected:

    /// @brief A static map to keep track of all jobs created.
    inline static type::uid_jobs mJobs{};

    /// @brief A unique identifier for each job.
    unsigned long long mID{_mID++};

    /// @brief A helper function to get the header string for a job.
    unsigned long long  getID() const { return mID; }
    /// @brief A helper function to get the header string for a job.
    std::string         getHeaderString() const;

    RateType mRateType{RateType::MONTHLY};    /// @brief The type of rate for the job.
    type::ul_ul mIncomeRange{0, 0};    /// @brief The income range for the job.
    std::string mPosition{};                  /// @brief The position for the job.
    bool mIsRemotePosition{false};          /// @brief Whether the job is remote or not.
    type::vstrings mResponsibilities{};     /// @brief The responsibilities for the job.
    std::string mCompany{};                 /// @brief The company for the job.
    std::string mContact{"julian.guarin.2010@gmail.com"};                 /// @brief The contact for the job.

public:


    void setRateType(RateType rateType);            /// @brief Setter for the rate type. @sa RateType
    RateType getRateType() const;                   /// @brief Getter for the rate type. @sa RateType
    void setIncomeRange(type::ul_ul incomeRange);   /// @brief Setter for the income range.
    type::ul_ul getIncomeRange() const;             /// @brief Getter for the income range.
    void setPosition(std::string position);         /// @brief Setter for the position.
    std::string getPosition() const;                /// @brief Getter for the position.
    void setIsRemotePosition(bool isRemotePosition);    /// @brief Setter for the remote position.
    bool getIsRemotePosition() const;                   /// @brief Getter for the remote position.
    void setResponsibilities(type::vstrings responsibilities);  /// @brief Setter for the responsibilities.
    type::vstrings getResponsibilities() const;                 /// @brief Getter for the responsibilities.
    void setCompany(std::string company);                       /// @brief Setter for the company.
    std::string getCompany() const;                             /// @brief Getter for the company.
    void setContact(std::string contact);                       /// @brief Setter for the contact.
    std::string getContact() const;                             /// @brief Getter for the contact.

    // The actions.
    static void                 displayAllJobs();   /// @brief Display all jobs.
    virtual void                displayJob() const; /// @brief Display a job.

    static void                 deleteJob(unsigned long long jobId);    /// @brief Delete a job by its id.
    void                        deleteJob() { deleteJob(mID); }    /// @brief Delete a job by its id.

    static auto                 getJobById(unsigned long long jobId);   /// @brief Get a job by its id.

    static unsigned long long   addJob(Job& job);   /// @brief Add a job to the list of jobs.
    static unsigned long long   addJob(Job* pJob)   /// @brief Add a job to the list of jobs.
    {
        auto& rThis = *pJob; return addJob(rThis);
    }
    void                        addJob()            /// @brief Add a job to the list of jobs.
    { auto& rThis = *this; addJob(rThis); }

};

class Programmer : public Job
{
public:
    /// @brief The seniority of the programmer.
    enum class Seniority
    {
        JUNIOR,
        MID,
        SENIOR
    };
    /// @brief A map to convert the seniority to a string.
    inline static const std::map<Programmer::Seniority, std::string> kSeniorityString {
            {Seniority::JUNIOR, "Junior"},
            {Seniority::MID, "Mid"},
            {Seniority::SENIOR, "Senior"}
    };
private:
    /// @brief The languages required by the position.
    type::vstrings   mLanguages{"C++", "C", "C#"};

    /// @brief The seniority required of the programmer.
    Seniority       mSeniority{Seniority::JUNIOR};

public:
    //Getters and Setters

    void setLanguages(type::vstrings languages);    /// @brief Setter for the languages.
    type::vstrings getLanguages() const;            /// @brief Getter for the languages.

    void setSeniority(Seniority seniority);         /// @brief Setter for the seniority. @sa Seniority
    Seniority getSeniority() const;                 /// @brief Getter for the seniority. @sa Seniority

    void displayJob() const;                        /// @brief Display a job.
};

class Pilot: public Job
{
public:
    /// @brief The rank of the pilot.
    enum class Rank
    {
        FIRST_OFFICER,
        SENIOR_FIRST_OFFICER,
        CAPTAIN
    };
    std::map<Rank, std::string> kRankString {
            {Rank::FIRST_OFFICER, "First Officer"},
            {Rank::SENIOR_FIRST_OFFICER, "Senior First Officer"},
            {Rank::CAPTAIN, "Captain"}
    };

    /// @brief The license type of the pilot.
    enum class LicenseType
    {
        ATP,
        COMMERCIAL,
        PRIVATE
    };

    /// @brief A map to convert the rank to a string.
    inline static const std::map<Pilot::LicenseType, std::string> kLicenseTypeString {
            {LicenseType::ATP, "ATP"},
            {LicenseType::COMMERCIAL, "Commercial"},
            {LicenseType::PRIVATE, "Private"}
    };
private:
    Rank mRank{Rank::FIRST_OFFICER};            /// @brief The rank of the pilot.
    LicenseType mLicenseType{LicenseType::ATP}; /// @brief The license type of the pilot.
    unsigned long mFlightHours{0};              /// @brief The flight hours of the pilot.

public:
    //Getters and Setters
    void setRank(Rank rank);                        /// @brief Setter for the rank. @sa Rank
    Rank getRank() const;                           /// @brief Getter for the rank. @sa Rank

    void setFlightHours(unsigned long flightHours); /// @brief Setter for the flight hours.
    unsigned long getFlightHours() const;           /// @brief Getter for the flight hours.

    void setLicenseType(LicenseType licenseType);   /// @brief Setter for the license type. @sa LicenseType
    LicenseType getLicenseType() const;             /// @brief Getter for the license type. @sa LicenseType

    void displayJob() const;                        /// @brief Display a job.
};

#endif //STEP1_JOB_H
