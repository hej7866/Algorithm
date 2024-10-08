#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    string strX = to_string(x);
    
    int s = 0;
    for(char &c : strX)
    {
        s += c - '0';
    }
    
    return (x%s == 0) ? true : false;
}