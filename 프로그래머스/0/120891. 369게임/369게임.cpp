#include <string>
#include <vector>

using namespace std;

int solution(int order) 
{
    int count = 0;
    for(char &c : to_string(order))
    {
        if((c - '0') != 0 && (c - '0')%3 == 0)
        {
            count++;
        }
    }
    return count;
}