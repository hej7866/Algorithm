#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    int high_count = 0;
    int low_count = 0;
    for(int &w : win_nums)
    {
        if(find(lottos.begin(), lottos.end(), w) != lottos.end())
        {
            high_count++;
            low_count++;
        }
    }
    
    for(int &n : lottos)
    {
        if(n == 0)
        {
            high_count++;
        }
    }
    
    map<int,int> map =
    {
        {0, 6},
        {1, 6},
        {2, 5},
        {3, 4},
        {4, 3},
        {5, 2},
        {6, 1},
        
    };
    vector<int> result(2,0);
    result[0] = map[high_count];
    result[1] = map[low_count];
    return result;
}