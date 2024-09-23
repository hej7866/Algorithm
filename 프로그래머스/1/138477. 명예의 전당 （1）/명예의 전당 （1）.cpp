#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    int day = score.size();
    
    vector<int> vec;
    vector<int> result;
    for(int i=0; i<day; i++)
    {
        if(vec.size() < k)
        {
            vec.push_back(score[i]);
            sort(vec.begin(), vec.end());
            result.push_back(vec[0]);
            continue;
        }
        
        if(vec.size() == k)
        {
            if(vec[0] < score[i])
            {
                vec[0] = score[i];
                sort(vec.begin(), vec.end());
                result.push_back(vec[0]);
            }
            else
            {
                result.push_back(vec[0]);
            }
        }       
    }
    return result;  
}

// for(int &i : vec)
// {
//     cout << i;
// }