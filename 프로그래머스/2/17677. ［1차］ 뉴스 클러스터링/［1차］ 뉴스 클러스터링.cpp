#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 문자열에서 두 글자씩 끊어서 추출하고 유효한 문자열만 반환하는 함수
vector<string> extractTwoChars(const string& str) {
    vector<string> result;
    for (int i = 0; i < str.size() - 1; ++i) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) {
            string twoChar = "";
            twoChar += tolower(str[i]);
            twoChar += tolower(str[i + 1]);
            result.push_back(twoChar);
        }
    }
    return result;
}

int solution(string str1, string str2) {
    vector<string> vec1 = extractTwoChars(str1);
    vector<string> vec2 = extractTwoChars(str2);

    map<string, int> map1;
    map<string, int> map2;

    // 각 문자열의 요소별 개수 계산
    for(const string& s : vec1) {
        map1[s]++;
    }
    for(const string& s : vec2) {
        map2[s]++;
    }

    int intersectionSize = 0;
    int unionSize = 0;

    // 교집합 크기 계산
    for(auto const& [key, val] : map1) {
        if(map2.count(key)) {
            intersectionSize += min(val, map2[key]);
        }
    }

    // 합집합 크기 계산
    for(auto const& [key, val] : map1) {
        unionSize += val;
    }
    for(auto const& [key, val] : map2) {
         if(!map1.count(key)) {
            unionSize += val;
         }
         else {
             unionSize += max(0,val - map1[key]);
         }
    }
    
    // 예외처리
    if(intersectionSize == 0 && unionSize == 0) return 65536;

    double jaccard = (double)intersectionSize / unionSize;
    return (int)(jaccard * 65536);
}