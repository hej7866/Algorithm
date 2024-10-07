#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    unordered_map<string, int> participantMap;

    // 참가자 목록의 이름을 해시맵에 저장
    for (const string& name : participant) 
    {
        participantMap[name]++;
    }

    // 완주자 목록을 체크하여 해시맵의 값을 감소시킴
    for (const string& name : completion) 
    {
        participantMap[name]--;
    }

    // 완주하지 못한 참가자를 찾음
    for (const auto& entry : participantMap) 
    {
        if (entry.second > 0)
        {
            return entry.first;
        }
    }
}