#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) 
{
    int count = 0;
    for(string &s : s1)
    {
        for(string &t : s2)
        {
            if(s == t)
            {
                count++;
            }
        }
    }
    return count;
}