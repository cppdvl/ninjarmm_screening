#include "job.h"


//Print Helper
std::ostream& operator<<(std::ostream& os, const type::vstrings& strings)
{
    os << "\""; for (const auto& token : strings) os << token << ", "; os << (char) 0x8 << (char) 0x8 << "\""; return os;
}

//Getters and Setters
void Job::setRateType(RateType rateType) { mRateType = rateType; }
Job::RateType Job::getRateType() const { return mRateType; }

void Job::setIncomeRange(type::ul_ul incomeRange) { mIncomeRange = incomeRange; }
type::ul_ul Job::getIncomeRange() const { return mIncomeRange; }

void Job::setPosition(std::string position) { mPosition = position; }
std::string Job::getPosition() const { return mPosition; }

void Job::setIsRemotePosition(bool isRemotePosition) { mIsRemotePosition = isRemotePosition; }
bool Job::getIsRemotePosition() const { return mIsRemotePosition; }

void Job::setResponsibilities(type::vstrings responsibilities) { mResponsibilities = responsibilities; }
type::vstrings Job::getResponsibilities() const { return mResponsibilities; }

void Job::setCompany(std::string company) { mCompany = company; }
std::string Job::getCompany() const { return mCompany; }

void Job::setContact(std::string contact) { mContact = contact; }
std::string Job::getContact() const { return mContact; }

std::string Job::getHeaderString() const
{
    std::stringstream ss;

    ss << "--- Job Details ---" << std::endl;
    ss << "Company: " << mCompany << " ID: " << mID << std::endl;
    ss << "Position: " << mPosition << std::endl;
    ss << "Income Range: " << mIncomeRange.first << " - " << mIncomeRange.second << std::endl;
    ss << "Rate Type: " << static_cast<int>(mRateType) << std::endl;
    ss << "Remote Position: " << (mIsRemotePosition? "yes" : "no") << std::endl;
    ss << "Responsibilities: " << mResponsibilities << std::endl;
    return ss.str();
}

void Job::displayJob() const
{
    std::cout << getHeaderString();
}

void Job::displayAllJobs()
{
    for (const auto& id_job : mJobs) id_job.second.displayJob();
}

void Job::deleteJob(unsigned long long jobId)
{
    auto jobFound = mJobs.find(jobId);
    if (jobFound != mJobs.end()) mJobs.erase(jobFound);
}

auto Job::getJobById(unsigned long long jobId)
{
    return mJobs.find(jobId);
}

unsigned long long Job::addJob(Job& job)
{
    auto id = job.mID;
    if (mJobs.find(job.mID) == mJobs.end())
        mJobs.insert(std::make_pair(id, std::move(job)));
    return job.mID;
}


void Programmer::setLanguages(type::vstrings languages) { mLanguages = languages; }
type::vstrings Programmer::getLanguages() const { return mLanguages; }

void Programmer::setSeniority(Seniority seniority) { mSeniority = seniority; }
Programmer::Seniority Programmer::getSeniority() const { return mSeniority; }

void Programmer::displayJob() const
{
    std::cout << getHeaderString();
    std::cout << "Required Languages: " << mLanguages << std::endl;
    std::cout << "Seniority: " << kSeniorityString.at(mSeniority) << std::endl;
}

void Pilot::setRank(Rank rank) { mRank = rank; }
Pilot::Rank Pilot::getRank() const { return mRank; }

void Pilot::setFlightHours(unsigned long flightHours) { mFlightHours = flightHours; }
unsigned long Pilot::getFlightHours() const { return mFlightHours; }

void Pilot::setLicenseType(LicenseType licenseType) { mLicenseType = licenseType; }
Pilot::LicenseType Pilot::getLicenseType() const { return mLicenseType; }

void Pilot::displayJob() const
{
    std::cout << getHeaderString();
    std::cout << "Rank: " << static_cast<int>(mRank) << std::endl;
    std::cout << "License Type: " << static_cast<int>(mLicenseType) << std::endl;
    std::cout << "Flight Hours: " << mFlightHours << std::endl;
}







