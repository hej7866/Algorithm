#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    string bin = "";
    vector<string> binvec1;
    for(int i=0; i<n; i++)
    {      
        int t = arr1[i];
        while (t > 0) 
        {
            bin += to_string(t % 2); // 나머지를 문자열로 추가
            t /= 2; // n을 2로 나누기
        }
        if(bin.length() < n)
        {
            while(bin.length() != n)
            {
                bin += '0';
            }
        }
        reverse(bin.begin(), bin.end()); 
        binvec1.push_back(bin);
        bin = "";
    }
    
    bin = "";
    vector<string> binvec2;
    for(int i=0; i<n; i++)
    {      
        int t = arr2[i];
        while (t > 0) 
        {
            bin += to_string(t % 2); // 나머지를 문자열로 추가
            t /= 2; // n을 2로 나누기
        }
        if(bin.length() < n)
        {
            while(bin.length() != n)
            {
                bin += '0';
            }
        }
        reverse(bin.begin(), bin.end()); 
        binvec2.push_back(bin);
        bin = "";
    }
    
    vector<string> sharpVec;
    for(int i=0; i<n; i++)
    {
        string sharp = "";
        for(int j=0; j<n; j++)
        {    
            if(binvec1[i][j] == '1' || binvec2[i][j] == '1')
            {
                sharp += "#";
            }
            else
            {
                sharp += " ";
            }
        }
        sharpVec.push_back(sharp);
    }
    
    for(string s : sharpVec)
    {        
        cout << s << " ";
    }
    

    
    return sharpVec;
}