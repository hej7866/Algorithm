#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) 
{
    vector<string> vec;
    string temp = "";
    for(char &c : s)
    {
        if(c != ' ')
        {
            if(isdigit(c) || c == '-')
            {
                temp += c;
            }
            else if(c == 'Z')
            {
                vec.pop_back();
            }
        }
        else if(c == ' ' && !temp.empty())
        {
            vec.push_back(temp);
            temp = "";
        }
    }
    int sum = 0;
    if(!temp.empty())
    {
        vec.push_back(temp);
    }
    for(string &s : vec)
    {
        cout << s << ",";
        sum += stoi(s);
    }

    return sum;
}