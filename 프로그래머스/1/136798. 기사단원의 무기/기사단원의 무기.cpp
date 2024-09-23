#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) 
{
    int sum = 0;
    
    // 시간 복잡도 해결해야하는 문제.
    // 처음엔 단순하게 약수구하는 방법으로 계산을 했더니(O(n^2)) 실행시간 초과
    
    // 시간 복잡도를 최적화하며 약수 구하는 방법으로 다시 계산을 했더니 통과.
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