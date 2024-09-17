#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int count = 1;
    while(true)
    {
        if(7*count >= n) { break; }
        count++;
    }
    return count;
}