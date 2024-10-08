#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) 
{
    // 점수 떼오는 작업
    vector<int> ivec;
    string tmp1 = "";
    for(char &ch : dartResult)
    {
        if(isdigit(ch)) { tmp1 += ch; }
        else
        {
            if(!tmp1.empty())
            {
                ivec.push_back(stoi(tmp1));
                tmp1 = "";
            }
            else { continue; }
        }
    }
    
    // 보너스 및 옵션 떼오는 작업
    vector<string> svec;
    string tmp2 = "";
    for(char &ch : dartResult)
    {
        if(!isdigit(ch)) { tmp2 += ch; }
        else
        {
            if(!tmp2.empty())
            {
                svec.push_back(tmp2);
                tmp2 = "";
            }
            else { continue; }
        }
    }    
    if(!tmp2.empty()) { svec.push_back(tmp2); }
    
    
    for(int i = 0; i<svec.size(); i++)
    {
        int t = ivec[i];
        if(svec[i][0] == 'S')
        {
            ivec[i] *= 1;
        }
        else if(svec[i][0] == 'D')
        {
            ivec[i] *= t;
        }
        else if(svec[i][0] == 'T')
        {
            ivec[i] *= t;
            ivec[i] *= t;
        }
    }
    
    // 보너스 작업 로직
    for(int i = 0; i<svec.size(); i++)
    {
        if(svec[i].size() > 1)
        {
            if(svec[i][1] == '*')
            {
                if(i > 0)
                {
                    ivec[i-1] *= 2;
                    ivec[i] *= 2;
                }
                else if(i == 0)
                {
                    ivec[i] *= 2;
                }
            }
            else if(svec[i][1] == '#')
            {
                ivec[i] *= -1;
            }
        }
    }
    
    int ans = 0;
    for(int &i : ivec)
    {
        cout << i << " ";
        ans += i;
    }
    
    return ans;
}