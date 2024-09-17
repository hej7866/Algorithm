#include <string>
#include <vector>

using namespace std;

int solution(int hp)
{
    int count = 0;
    while(hp != 0)
    {
        while(hp >= 5)
        {
            hp -= 5;
            count++;
        }
        while(hp >= 3)
        {
            hp -= 3;
            count++;
        }
        while(hp > 0)
        {
            hp -= 1;
            count++;
        }
    }
    return count;
}