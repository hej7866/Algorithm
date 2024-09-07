#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> strArr) 
{
    vector<int> strlenVec(30,0); 
    

    for(string &s : strArr)
    {
        strlenVec[s.size()-1]++;
    }
    
    sort(strlenVec.begin(),strlenVec.end());
    // 디버깅용
    // for(int &i : strlenVec) 
    // {
    //     cout << i << " ";
    // }
    return strlenVec.back();
}