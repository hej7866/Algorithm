#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


vector<long long> point(int r) {
    long long inCnt = 0;  // 내부 점 개수
    long long eqCnt = 0;  // 경계 위 점 개수
    long long rr = pow(r,2);
    
    for (int x = 1; x <= r; x++) 
    {
        long long xx = pow(x,2);

        // y^2 <= r^2 - x^2 를 만족하는 최대 y 값 계산
        int yMax = static_cast<int>(sqrt(rr - xx));
        
        // yMax까지의 점 개수 추가
        inCnt += yMax + 1;

        // yMax가 정확히 제곱근인 경우 eqCnt 추가
        if (pow(yMax,2) + xx == rr) 
        {
            inCnt--;
            eqCnt++;
        }
    }

    // 대칭성을 고려하여 4배로 확장하고 원점 포함
    inCnt = inCnt * 4 + 1;  // 사분면 확장 + 원점
    eqCnt = eqCnt * 4;      // 사분면 확장
    cout << inCnt << " " << eqCnt << endl;
    return {inCnt, eqCnt};
}

long long solution(int r1, int r2) 
{
    vector<long long> v1 = point(r1);  // 작은 반지름 r1의 내부 및 경계점
    vector<long long> v2 = point(r2);  // 큰 반지름 r2의 내부 및 경계점
    
    // r2 영역에서 r1의 내부 점을 제외하여 겹치는 부분 제거
    long long result = (v2[0] + v2[1]) - v1[0];
    return result;
}