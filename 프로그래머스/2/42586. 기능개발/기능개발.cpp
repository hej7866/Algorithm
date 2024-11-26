#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    int size = progresses.size();
    vector<int> dayVec;
    for(int i=0; i<size; i++)
    {
        int p = progresses[i];
        int s = speeds[i];
        
        int day = 0;
        while(p < 100)
        {
            p += s;
            day++;
        }
        dayVec.push_back(day);
        cout << day << "\n";
    }
    
    int idx = 0;
    int cnt = 1;
    vector<int> vec;
    for(int i=1; i<size; i++)
    {
        int curr = dayVec[idx];
        if(curr >= dayVec[i])
        {
            cnt++;
        }
        else if(curr < dayVec[i])
        {
            vec.push_back(cnt);
            cnt = 1;
            idx = i;
        }
    }
    vec.push_back(cnt);
    return vec;
}