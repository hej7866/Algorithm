#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;


/* 문제 [재귀]
오늘도 서준이는 병합 정렬 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
N개의 서로 다른 양의 정수가 저장된 배열 A가 있다. 병합 정렬로 배열 A를 오름차순 정렬할 경우 배열 A에 K 번째 저장되는 수를 구해서 우리 서준이를 도와주자.
크기가 N인 배열에 대한 병합 정렬 의사 코드는 다음과 같다.

merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
    if (p < r) then {
        q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
        merge_sort(A, p, q);      # 전반부 정렬
        merge_sort(A, q + 1, r);  # 후반부 정렬
        merge(A, p, q, r);        # 병합
    }
}

# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
merge(A[], p, q, r) {
    i <- p; j <- q + 1; t <- 1;
    while (i ≤ q and j ≤ r) {
        if (A[i] ≤ A[j])
        then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
        else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
    }
    while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
        tmp[t++] <- A[i++];
    while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
        tmp[t++] <- A[j++];
    i <- p; t <- 1;
    while (i ≤ r)  # 결과를 A[p..r]에 저장
        A[i++] <- tmp[t++]; 
}


/* 입력
첫째 줄에 배열 A의 크기 N(5 ≤ N ≤ 500,000), 저장 횟수 K(1 ≤ K ≤ 108)가 주어진다.
다음 줄에 서로 다른 배열 A의 원소 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

/* 출력
배열 A에 K 번째 저장 되는 수를 출력한다. 저장 횟수가 K 보다 작으면 -1을 출력한다.


/* 제한
*/


int cnt = 0;  // 저장 횟수를 세는 변수
int result = -1;  // K번째 저장된 값을 저장할 변수
int K;  // 전역 변수 K

// 병합 함수
void Merge(vector<int>& list, int left, int mid, int right)
{
    int leftIdx = left;
    int rightIdx = mid + 1;

    vector<int> sorted;

    // 왼쪽 파트와 오른쪽 파트를 비교해서 작은 수부터 정렬된 공간에 저장
    while (leftIdx <= mid && rightIdx <= right)
    {
        if (list[leftIdx] <= list[rightIdx])
        {
            sorted.push_back(list[leftIdx]);
            leftIdx++;
        }
        else
        {
            sorted.push_back(list[rightIdx]);
            rightIdx++;
        }

        // 저장할 때마다 count를 증가시키고 K번째 값을 찾음
        cnt++;
        if (cnt == K)
        {
            result = sorted.back();  // sorted에 마지막으로 저장된 값을 result에 저장
        }
    }

    // 왼쪽 파트에 남은 요소를 추가
    while (leftIdx <= mid)
    {
        sorted.push_back(list[leftIdx]);
        leftIdx++;
        cnt++;
        if (cnt == K)
        {
            result = sorted.back();
        }
    }

    // 오른쪽 파트에 남은 요소를 추가
    while (rightIdx <= right)
    {
        sorted.push_back(list[rightIdx]);
        rightIdx++;
        cnt++;
        if (cnt == K)
        {
            result = sorted.back();
        }
    }

    // 정렬된 배열을 원래 배열로 복사
    for (int i = 0; i < sorted.size(); i++)
    {
        list[left + i] = sorted[i];
    }
}

// 병합 정렬 함수
void MergeSort(vector<int>& list, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        MergeSort(list, left, mid);  // 왼쪽 정렬
        MergeSort(list, mid + 1, right);  // 오른쪽 정렬
        Merge(list, left, mid, right);  // 병합
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N >> K;  // 배열 크기 N과 K번째 값을 입력받음

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];  // 배열 요소를 입력받음
    }

    MergeSort(A, 0, N - 1);  // 병합 정렬 호출

    if (result != -1)
    {
        cout << result << "\n";  // K번째 저장된 값을 출력
    }
    else
    {
        cout << -1 << "\n";  // K번째 저장된 값이 없으면 -1 출력
    }

    return 0;
}