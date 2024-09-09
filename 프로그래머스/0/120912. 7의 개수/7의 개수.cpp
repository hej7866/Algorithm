#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> array) 
{
    string temp = "";
    for(int &i : array)
    {
        temp += to_string(i);
    }
    
    int count = 0;
    for(char &c : temp)
    {
        if(c == '7')
        {
            count++;
        }
    }
    return count;
}