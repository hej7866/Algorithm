#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// HH:MM 형식의 시간을 분 단위로 변환하는 함수
int timeToMinutes(const string& time) 
{
    return (time[0] - '0') * 600 + (time[1] - '0') * 60 + (time[3] - '0') * 10 + (time[4] - '0');
}

int solution(vector<vector<string>> book_time) 
{
    vector<pair<int, int>> times;

    // 예약 시간을 분 단위로 변환
    for (const auto& booking : book_time) 
    {
        int start = timeToMinutes(booking[0]);
        int end = timeToMinutes(booking[1]) + 10; // 종료 시간에 10분 청소 시간 추가
        times.push_back({start, end});
    }

    // 시작 시간 기준으로 정렬
    sort(times.begin(), times.end());

    // 종료 시간을 관리할 우선순위 큐 (최소 힙)
    priority_queue<int, vector<int>, greater<int>> room_end_times;

    for (const auto& time : times) 
    {
        int start = time.first;
        int end = time.second;

        // 가장 빨리 끝나는 객실이 현재 예약 시작 시간 이전에 끝났으면 재사용
        if (!room_end_times.empty() && room_end_times.top() <= start) 
        {
            room_end_times.pop();
        }

        // 현재 예약의 종료 시간을 추가
        room_end_times.push(end);
    }

    // 우선순위 큐의 크기가 필요한 최소 객실의 수
    return room_end_times.size();
}
