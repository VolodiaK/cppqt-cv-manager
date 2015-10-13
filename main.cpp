#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;
// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV

//enum class JobTitle {junior , middle  , senior };

class JobRecord
{
public:
    JobRecord(int startYear, int endYear, const string &jobTitle, const string &companyName ) :
        mStartYear{startYear}
      , mEndYear{endYear}
      , mJobTitle{jobTitle}
      , mCompanyName{companyName}
    {

    }

    bool isValid() const
    {
        return !mCompanyName.empty()
                && ((mStartYear > 1960) && (mEndYear > 1960));
    }

    void print() const
    {
        cout << mCompanyName << "   " << mJobTitle << "   "
             << mStartYear << " - " << mEndYear << endl;
    }

    int mStartYear;
    int mEndYear;
    string mJobTitle;
    string mCompanyName;
};

class CV
{
public:
    CV(const string &name, int birthYear, const string &skills) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
    {

    }
    bool isValid() const
    {
        bool k = true;
        for(int i=0; i<mPreviousJobs.size();i++)
        {
            if(!mPreviousJobs[i].isValid())
            {
                k=false;
            }
        }
        return !mName.empty()
                && ((mBirthYear > 1963) && (mBirthYear < 1995))
                && !mSkills.empty()
                && k;
    }

    void print() const
    {
        int i=0;
        if (isValid())
        {
            cout << mName << " (" << mBirthYear << ")" << endl;
            cout << "=====================" << endl;
            cout << "Skills: " << mSkills << endl;
            cout << "=====================" << endl;
            cout << "Previous jobs: " << endl;
            JobRecords();
            cout << endl;

        }
    }

    void addJobRecord(const JobRecord &jobRecord)
    {
        mPreviousJobs.push_back(jobRecord);
    }

    void JobRecords() const
    {
        for(unsigned int i=0; i<mPreviousJobs.size();i++)
        {
            cout << mPreviousJobs[i].mCompanyName << "   "
                 << mPreviousJobs[i].mJobTitle << "   "
                 << mPreviousJobs[i].mStartYear << " - "
                 << mPreviousJobs[i].mEndYear << endl;
        }
    }

    bool experience()
    {
        int expJob=0;
        int sizeExperience = mPreviousJobs.size();
        for (int i=0; i<sizeExperience;i++)
        {
            expJob += mPreviousJobs[i].mEndYear - mPreviousJobs[i].mStartYear;
        }
        if (expJob >=5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    vector <JobRecord> mPreviousJobs;

};



int main()
{
    CV johnsCV {"John Jonson", 1978,"C++, Java"};
    JobRecord firstJohnsJob {1985, 1998, "junior", "Globallogic"};
    JobRecord secondJohnsJob {1998, 2001, "middle", "Globallogic"};
    johnsCV.addJobRecord(firstJohnsJob);
    johnsCV.addJobRecord(secondJohnsJob);
//    johnsCV.print()*/;

    CV tomCV {"Tom Tomson", 1994, "C++, C#"};
    JobRecord firstTomsJob {2012, 2014, "junior", "SoftServe"};
    tomCV.addJobRecord(firstTomsJob);
//    tomCV.print();

    vector <CV> list;
    list.push_back(johnsCV);
    list.push_back(tomCV);

    for (int i=0; i<list.size(); i++)
    {
        if(list[i].experience())
        {
            list[i].print();
        }
    }

    return 0;
}

