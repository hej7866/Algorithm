#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) 
{
    sort(sides.begin(), sides.end());
    
    int count = 0;
    int i = 1;
    while(i<=sides[1])
    {
        if(i + sides[0] > sides[1])
        {
            count++;
        }
        i++;
    }
    
    int j = sides[1] + 1;
    while(j<sides[0] + sides[1])
    {
        count++;
        j++;
    }
    return count;
}