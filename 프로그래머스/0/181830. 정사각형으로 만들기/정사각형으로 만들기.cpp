#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) 
{
    int arrRow = arr.size();
    int arrCol = arr[0].size();
    
    int n = 0;    
    if(arrRow > arrCol)
    {
        n = arrRow;
    }
    else
    {
        n = arrCol;
    }
    
    vector<vector<int>> vec(n, vector<int> (n, 0));
    for(int i=0; i<arr.size(); i++)
    {
        vector<int> a = arr[i];
        vector<int> v = vec[i];
        
        copy(a.begin(), a.end(), v.begin());
        vec[i] = v;
    }
    return vec;
}