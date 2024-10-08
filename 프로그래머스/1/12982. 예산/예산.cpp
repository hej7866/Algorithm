#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) 
{
    sort(d.begin(), d.end());
    
    int idx = 0;
    while(budget > 0)
    {
        budget -= d[idx];
        idx++;
        if(idx == d.size())
        {
            break;
        }
    }
    
    if(budget < 0)
    {
        idx--;
    }
    
    return idx;
}