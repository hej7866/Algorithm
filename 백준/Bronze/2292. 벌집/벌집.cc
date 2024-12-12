#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << 1 << endl; // 시작 방은 이동이 필요 없음
        return 0;
    }

    long long layer = 1;  // 몇 번째 층인지 (1층부터 시작)
    long long range = 1;  // 현재 층의 마지막 숫자

    // N이 해당 층의 범위를 초과할 때까지 반복
    while (N > range) {
        range += 6 * layer;  // 다음 층의 마지막 숫자 계산
        layer++;
    }

    cout << layer << endl;
    return 0;
}
