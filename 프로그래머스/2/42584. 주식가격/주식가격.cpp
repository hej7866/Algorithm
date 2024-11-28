#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> result(prices.size());
    for(int i=0; i<prices.size() - 1; i++)
    {
        int cnt = 1;
        for(int j=i+1; j<prices.size() - 1; j++)
        {
            if(prices[i] <= prices[j])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        result[i] = cnt;
    }
    result[result.size() - 1] = 0;
    // for(int r : result)
    // {
    //     cout << r << " ";
    // }
    return result;
}