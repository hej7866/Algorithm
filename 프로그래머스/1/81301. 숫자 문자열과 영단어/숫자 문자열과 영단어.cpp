#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) 
{
    vector<string> strNum = 
    {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    
    for(int i=0; i<=9; i++)
    {
        while(s.find(strNum[i]) != string::npos)
        {
            size_t pos = s.find(strNum[i]);
            s.replace(pos, strNum[i].size(), to_string(i));
        }
    }
    cout << s;
    return stol(s);
}