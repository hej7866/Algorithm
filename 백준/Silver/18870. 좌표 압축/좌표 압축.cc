#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/* 문제 
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.


/* 입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

/* 출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

/* 제한
 1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9
*/


int main() 
{
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> vec[i];
    }

    // vec을 복사해서 정렬할 배열 생성
    vector<int> sorted_vec = vec;

    // 정렬 및 중복 제거
    sort(sorted_vec.begin(), sorted_vec.end());
    sorted_vec.erase(unique(sorted_vec.begin(), sorted_vec.end()), sorted_vec.end());

    // 좌표 압축 맵 생성
    unordered_map<int, int> compressed;
    for (int i = 0; i < sorted_vec.size(); ++i) 
    {
        compressed[sorted_vec[i]] = i;
    }

    // 압축된 결과 출력
    for (int i = 0; i < N; ++i) 
    {
        cout << compressed[vec[i]] << " ";
    }

    return 0;
}