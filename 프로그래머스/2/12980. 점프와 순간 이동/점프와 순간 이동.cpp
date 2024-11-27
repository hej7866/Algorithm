#include <iostream>
using namespace std;

int solution(int N) 
{
    int batteryUsage = 0;
    while (N > 0) 
    {
        // N이 홀수라면 점프를 해야 한다.
        if (N % 2 == 1) 
        {
            batteryUsage++; // 점프는 배터리 소모
            N--;            // 점프했으니 위치를 줄임
        } 
        else 
        {
            // N이 짝수라면 순간이동
            N /= 2; // 현재 위치를 2배로 순간이동하여 줄임
        }
    }
    return batteryUsage;
}