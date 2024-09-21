#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) 
{
    string answer = "";
    vector<char> vec;
    for(int i=0; i<s.length(); i++)
    {
        char c = ++s[i];
        while(vec.size() < index)
        {
            if(c > 'z') { c = 'a'; }
            while(skip.find(c) != string::npos)
            {
                c++;
                if(c > 'z') { c = 'a'; }
            }
            vec.push_back(c);
            c++;
        }
        answer += vec[vec.size() - 1];
        for(char c : vec)
        {
            cout << c << " ";
        }
        vec.clear();
    }
    return answer;
}