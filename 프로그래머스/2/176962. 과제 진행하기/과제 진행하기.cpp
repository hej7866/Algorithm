#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct __PlanInfo
{
    string name         = "";

    int startTime   = 0;
    int processTime = 0;

    int GetCompalteTime() { return startTime + processTime; }
}PlanInfo;

int ConvertTime(const string time)
{
    const int hour = stoi(time.substr(0, 2)) * 60;
    const int minute = stoi(time.substr(3, 5));
    return hour + minute;
}

int ConvertMinute(const string minute)
{
    return stoi(minute);
}

PlanInfo ConvertPlanInfo(vector<string> plan)
{
    PlanInfo info
    {
        plan[0],
        ConvertTime(plan[1]),
        ConvertMinute(plan[2])
    };

    return info;
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    string currentPlan;

    stack<PlanInfo> remainingPlan;

    PlanInfo currentInfo, prevInfo;


    sort(plans.begin(), plans.end(), 
        [](const vector<string>& src, const vector<string>& dest) {
            return ConvertTime(src[1]) < ConvertTime(dest[1]);
        });

    for (auto plan : plans)
    {
        currentInfo = ConvertPlanInfo(plan);

        if (prevInfo.name != "")
        {
            int remainingTime = prevInfo.GetCompalteTime() - currentInfo.startTime;
            if (remainingTime > 0) // 처리 중단
            {
                prevInfo.processTime = remainingTime;
                remainingPlan.push(prevInfo);
            }
            else                  // 처리 완료
            {
                answer.push_back(prevInfo.name);

                while (!remainingPlan.empty()) // 남은 시간동안 처리할 수 있는 과목이 있는 경우
                {
                    remainingPlan.top().startTime = prevInfo.GetCompalteTime();

                    remainingTime = remainingPlan.top().GetCompalteTime() - currentInfo.startTime;
                    if (remainingTime <= 0)    // 처리하고도 남는 시간이 있음
                    {
                        answer.push_back(remainingPlan.top().name); // 처리 완료

                        prevInfo = remainingPlan.top();
                        remainingPlan.pop();
                    }
                    else           // 처리하기엔 시간이 부족함
                    {
                        remainingPlan.top().processTime = remainingTime;
                        break;
                    }

                }
            }
        }

        prevInfo = currentInfo;     // 마지막 과목
    }

    answer.push_back(prevInfo.name);

    while (!remainingPlan.empty())
    {
        answer.push_back(remainingPlan.top().name);
        remainingPlan.pop();
    }


    return answer;
}