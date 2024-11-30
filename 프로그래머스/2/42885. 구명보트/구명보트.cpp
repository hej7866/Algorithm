#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    sort(people.begin(), people.end()); // 몸무게를 오름차순으로 정렬
    int left = 0, right = people.size() - 1; // 투 포인터 초기화
    int boatCount = 0; // 필요한 구명보트 개수

    while (left <= right) 
    {
        if (people[left] + people[right] <= limit) 
        {
            // 가장 가벼운 사람과 가장 무거운 사람이 함께 탈 수 있는 경우
            left++;
        }
        // 가장 무거운 사람은 반드시 태워야 하므로 오른쪽 포인터 이동
        right--;
        // 구명보트 하나 사용
        boatCount++;
    }

    return boatCount;
}