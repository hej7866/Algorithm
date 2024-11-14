#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    map<string, int> wMap;
    int totalDay = 0;
    int cnt = 0;
    for(int n : number)
    {
        totalDay += n;
    }
    
    for(int i = 0; i<want.size(); i++)
    {
        wMap[want[i]] = number[i];
    }
    
    int k = 0;
    while(k + totalDay <= discount.size())
    {
        map<string, int> tmp = wMap;
        bool isBool = false;
        for(int i=k; i<k + totalDay; i++)
        {
            tmp[discount[i]]--;
        }
        
        
        for(string w : want)
        {
            if(tmp[w] != 0)
            {
                isBool = true;
                break;
            }
        }
        if(!isBool) { cnt++; }
        k++;
    }
    return cnt;
}