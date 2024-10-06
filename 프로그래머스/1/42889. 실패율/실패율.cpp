#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{   
    map<int, int> map;
    
    for(int i=1; i<=N; i++)
    {
        int count = 0;
        for(int &n : stages)
        {
            if(n == i)
            {
                count++;
            }
        }
        map[i] = count;
    }
    
    vector<pair<int, double>> fvec;
    double f = 0.0;
    int size = stages.size();
    int s = 1;
    while(s <= N)
    {
        if(map[s] != 0)
        {
            f = (double)map[s] / size;
            fvec.push_back({s, f});
        }
        else
        {
            fvec.push_back({s, 0});
        }
        size -= map[s];
        s++;
    }
     
    sort(fvec.begin(), fvec.end(), [](pair<int, double>& a, pair<int, double>& b) {
        // 실패율이 높은 순서로 정렬, 실패율이 같으면 번호가 작은 순서로 정렬
        if (a.second == b.second) { return a.first < b.first; }
        return a.second > b.second; 
    });
    
    vector<int> result; // 최종 결과를 저장할 벡터
    for (auto &p : fvec) 
    {
        result.push_back(p.first); // 정렬된 스테이지 번호 추가
    }
    
    return result;
}