#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> vec(s.length(),0);
    
    for(int i=0; i<s.length(); i++)
    {
        int currIdx = i;
        for(int j=0; j<currIdx; j++)
        {
            if(s[i] == s[j]) { vec[i] = i-j; }
        }
    }
    
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] == 0) { vec[i] = -1; }
    }
    return vec;
}