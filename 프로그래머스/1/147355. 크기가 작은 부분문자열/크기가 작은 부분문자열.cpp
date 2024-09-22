#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) 
{
    int count = 0;
    for(int i=0; i<=t.size() - p.size(); i++)
    {
        string str = t.substr(i,p.size());
        if(stol(str) <= stol(p))
        {
            count++;
        }
    }
    return count;
}