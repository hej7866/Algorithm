#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) 
{
    string s;
    for(int i=0; i<code.size(); i++)
    {
        if(i%q == r) s.push_back(code[i]);
    }
    return s;
}