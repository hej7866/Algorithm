#include <string>
#include <vector>

using namespace std;

int solution(string num_str)
{
    int numSum = 0;
    for(char &c : num_str)
    {
        numSum += (c - '0');
    }
    return numSum;
}