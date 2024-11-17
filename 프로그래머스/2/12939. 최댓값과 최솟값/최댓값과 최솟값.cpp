#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) 
{
    vector<int> vec;
    string tmp = "";
    for(char ch : s)
    {
        if(ch != ' ')
        {
            tmp += ch;
        }
        else if (ch == ' ')
        {
            vec.push_back(stoi(tmp));
            tmp = "";
        }
    }
    vec.push_back(stoi(tmp));
    sort(vec.begin(), vec.end());
    string result = to_string(vec[0]) + " " + to_string(vec[vec.size() - 1]);
    return result;
}