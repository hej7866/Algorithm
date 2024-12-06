#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    if (cacheSize == 0) 
    {
        return cities.size() * 5; // 캐시 크기가 0인 경우 모두 Cache Miss
    }

    list<string> cache; // 캐시를 저장할 리스트 (LRU 구현)
    unordered_map<string, list<string>::iterator> cacheMap; // 도시와 리스트 iterator를 매핑
    int totalTime = 0;

    for (string city : cities) 
    {
        // 대소문자 구분 제거
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (cacheMap.find(city) != cacheMap.end()) 
        {
            // Cache Hit
            cache.erase(cacheMap[city]); // 기존 위치 제거
            cache.push_front(city); // 가장 앞에 추가
            cacheMap[city] = cache.begin(); // 새로운 위치 업데이트
            totalTime += 1;
        } 
        else 
        {
            // Cache Miss
            if (cache.size() == cacheSize) 
            {
                // 캐시가 가득 찬 경우 가장 오래된 항목 제거
                string oldCity = cache.back();
                cache.pop_back();
                cacheMap.erase(oldCity);
            }
            cache.push_front(city); // 새로운 도시 추가
            cacheMap[city] = cache.begin(); // 맵에 추가
            totalTime += 5;
        }
    }

    return totalTime;
}
