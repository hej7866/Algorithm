#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    string nstr = to_string(n);
    int numSum = 0;
    for(char &c : nstr)
    {
        numSum += c - '0';
    }
    return numSum;
}