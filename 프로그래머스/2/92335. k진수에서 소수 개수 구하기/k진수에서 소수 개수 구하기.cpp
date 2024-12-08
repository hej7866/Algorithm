#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

// 소수 판별 함수
bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

string toKBase(int n, int k) {
    string result = "";
    while (n > 0) {
        result = to_string(n % k) + result;
        n /= k;
    }
    return result;
}

int solution(int n, int k) {
    string k_base = toKBase(n, k); // 진법 변환
    stringstream ss(k_base);
    string segment;
    int count = 0;

    while (getline(ss, segment, '0')) { // '0'을 기준으로 분리
        if (!segment.empty()) {
            long long num = stoll(segment);
            if (isPrime(num)) count++;
        }
    }
    return count;
}
