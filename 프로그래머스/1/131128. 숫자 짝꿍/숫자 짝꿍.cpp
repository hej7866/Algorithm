#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y) 
{
    vector<int> Xvec(10,0);
    vector<int> Yvec(10,0);
    
    for(int i=0; i<X.length(); i++)
    {
        Xvec[X[i] - '0']++;
    }
    for(int i=0; i<Y.length(); i++)
    {
        Yvec[Y[i] - '0']++;
    }
    
    vector<int> vec;
    
    for(int i=0; i<=9; i++)
    {
        int minValue = min(Xvec[i], Yvec[i]);
        vec.push_back(minValue);
    }
    
    string result = "";
    
    for(int i=9; i>=0; i--)
    {
        if(vec[i] > 0)
        {
            for(int j=0; j<vec[i]; j++)
            {
                result += to_string(i);
            }
        }
    }
    
    bool isOverOne = false;
    
    for(int i=1; i<=9; i++)
    {
        if(vec[i] > 0) { isOverOne = true; }
    }
    
    if(!isOverOne)
    {
        if(vec[0] > 0) { result = "0"; }
        else { result = "-1"; }
    }
    return result;
}