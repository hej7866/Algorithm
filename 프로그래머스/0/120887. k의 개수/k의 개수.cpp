#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int i, int j, int k) 
{
    string num = "";
    for(int idx = i; idx<=j; idx++)
    {
        num += to_string(idx);
    }
    
    int count = 0;
    for(char &c : num)
    {
        if(c-'0' == k)
        {
            count++;
        }
    }
    return count;
}