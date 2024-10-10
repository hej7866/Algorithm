#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) 
{
    long long root = sqrt(n);
    if (root * root == n) 
    {
        // n이 완전 제곱수일 경우 다음 완전 제곱수를 반환
        return (root + 1) * (root + 1);
    }
    // n이 완전 제곱수가 아닐 경우 -1 반환
    return -1;
}