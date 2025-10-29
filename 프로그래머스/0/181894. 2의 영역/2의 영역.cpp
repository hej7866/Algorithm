#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> iv;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 2)
        {
            iv.push_back(i);
        }
    }
    
    for(int i : iv)
    {
        cout << i << "\t";
    }
    
    vector<int> v;
    
    if(iv.empty()) return {-1};
    
    for(int i=iv[0]; i<=iv[iv.size() - 1]; i++)
    {
        v.push_back(arr[i]);
    }
    
    
    return v;
}