#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) 
{
    int sum = 0;
    
    // 시간 복잡도 해결해야하는 문제.
    for(int i=1; i<=number; i++)
    {
        int count = 0;
        for(int j=1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
                if(j != i/j)
                {
                    count++;
                }
            }
        }
        if(count <= limit) { sum += count; }
        else if(count > limit) { sum += power; }
    }
    return sum;
}