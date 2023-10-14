#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n;

struct Stu
{
    string id;
    bool gender;
    int basicgrade;
    int trainingtimes;
    int runsecond;
};

inline int getSecond(string x)
{
    
}

struct RunningRecord
{

};

inline string gradeJudge(int score)
{
    if (score >= 95)      { return "A"; }
    else if (score >= 90) { return "A-"; }
    else if (score >= 85) { return "B+"; }
    else if (score >= 80) { return "B"; }
    else if (score >= 77) { return "B-"; }
    else if (score >= 73) { return "C+"; }
    else if (score >= 70) { return "C"; }
    else if (score >= 67) { return "C-"; }
    else if (score >= 63) { return "D+"; }
    else if (score >= 60) { return "D"; }
    else                  { return "F"; }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string id, gender, runtime, passed;
        int _50, _5, trainingtimes;
        cin >> id
            >> gender
            >> _50
            >> runtime
            >> passed
            >> _5
            >> trainingtimes;

    }
    return 0;
}
