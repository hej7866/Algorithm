#include <string>
#include <vector>

using namespace std;

int solution(int chicken) 
{
    int cp = chicken;
    int sv = 0;
    int total = 0;
    while(cp >= 10)
    {
        sv = cp/10; 
        cp = sv + cp%10; 
        total += sv; 
    }
    return total;
}