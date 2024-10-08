#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    long long n = num ;
    int count = 0;
    while (n != 1) // num이 1이 아닐 때 반복
    {
        if (n % 2 == 0) // 짝수
        {
            n /= 2;
        }
        else // 홀수
        {
            n = n * 3 + 1;
        }
        count++;
    }
    
    return (count < 500) ? count : -1;
}