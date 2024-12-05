#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) 
{
    int transformCount = 0;
    int removedZeros = 0;

    while (s != "1") {
        // 현재 문자열에서 0의 개수를 카운트
        int zeroCount = count(s.begin(), s.end(), '0');
        removedZeros += zeroCount;

        // 0을 제거한 후 문자열의 길이를 계산
        int newLength = s.size() - zeroCount;

        // 문자열을 길이의 2진법 표현으로 변환
        s = "";
        while (newLength > 0) {
            s = char((newLength % 2) + '0') + s;
            newLength /= 2;
        }

        // 변환 횟수 증가
        transformCount++;
    }

    return {transformCount, removedZeros};
}
