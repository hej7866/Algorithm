#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int> validReserve;
    for (int r : reserve) 
    {
        // 여벌 체육복을 가진 학생이 도난당한 경우
        if (find(lost.begin(), lost.end(), r) != lost.end()) 
        {
            validReserve.push_back(r);
        }
    }
    
    // 여벌 체육복이 있는 학생이 도난당한 경우 제거
    for (int v : validReserve) 
    {
        auto it = find(lost.begin(), lost.end(), v);
        if (it != lost.end()) 
        {
            lost.erase(it); // 도난당한 학생 목록에서 제거
            reserve.erase(find(reserve.begin(), reserve.end(), v)); // 여벌 목록에서도 제거
        }
    }

    // 체육복을 빌려주는 과정
    for (int r : reserve) 
    {
        // 왼쪽 학생에게 빌려주기
        auto it = find(lost.begin(), lost.end(), r - 1);
        if (it != lost.end()) 
        {
            lost.erase(it); // 왼쪽 학생에게 빌려줌
            continue; // 다음 여벌 체육복 가진 학생으로 이동
        }
        
        // 오른쪽 학생에게 빌려주기
        it = find(lost.begin(), lost.end(), r + 1);
        if (it != lost.end()) 
        {
            lost.erase(it); // 오른쪽 학생에게 빌려줌
        }
    }

    // 체육복을 가진 학생 수
    return n - lost.size();
}
