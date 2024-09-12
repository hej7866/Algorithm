#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<double> avg;
    for(auto &s : score)
    {
        avg.push_back((double)(s[0] + s[1])/ 2);
    }
    
    vector<int> rank(avg.size(),1);
    for(int i=0; i<avg.size(); i++)
    {
        for(int j=0; j<avg.size(); j++)
        {
            if(avg[i] < avg[j])
            {
                rank[i]++;
            }
        }
    }
    return rank;
}