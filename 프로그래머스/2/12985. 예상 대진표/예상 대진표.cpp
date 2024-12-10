#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
    int roundCount = 0;
    while (a != b) {
        // 다음 라운드로 위치 계산
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        roundCount++;
    }
    return roundCount;
}
