#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    int ranking = 1;
    int idx = 0;
    vector<int> rankVec;
    while(rankVec.size() != 3)
    { 
        for(int i=0; i<rank.size(); i++)
        {
            if(rank[i] == ranking) { idx = i; }
        }
        
        if(attendance[idx])
        {
            rankVec.push_back(idx);
        }
        ranking++;
    }
    
    
    return rankVec[0] * 10000 + rankVec[1] * 100 + rankVec[2];
}