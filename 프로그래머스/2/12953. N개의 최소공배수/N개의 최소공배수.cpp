#include <string>
#include <vector>
#include <numeric> // std::gcd
using namespace std;

// LCM 함수 정의
long long lcm(long long a, long long b) 
{
    return (a / gcd(a, b)) * b; // 두 수의 최소공배수
}

int solution(vector<int> arr) 
{
    long long result = arr[0];
    for (int i = 1; i < arr.size(); i++) 
    {
        result = lcm(result, arr[i]); // 배열 요소로 LCM 갱신
    }
    return result;
}
