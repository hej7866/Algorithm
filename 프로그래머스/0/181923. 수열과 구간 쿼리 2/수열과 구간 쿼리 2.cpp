#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
    vector<int> result;
    
    int row = queries.size();
    int col = queries[0].size();
    
    int s = 0;
    int e = 0;
    int k = 0;
    
    
    vector<int> temp;
    for(int i=0; i<row; i++)
    {
        s = queries[i][0];
        e = queries[i][1];
        k = queries[i][2];
        for(int j=s; j<=e; j++)
        {
            if(arr[j]>k)
            {
                temp.push_back(arr[j]);
            }
        }
        
        if (!temp.empty())
        {
            result.push_back(*min_element(temp.begin(), temp.end()));
        }
        else
        {
            result.push_back(-1);
        }
        temp.clear();
    }
    return result;
}