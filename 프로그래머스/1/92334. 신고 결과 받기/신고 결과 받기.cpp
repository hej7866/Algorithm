#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    // 1단계: set 사용하여 고유한 보고서를 저장
    set<string> reportSet;
    for(string &s : report)
    {
        reportSet.insert(s);
    }
    
    // 2단계: 신고 수와 결과를 추적할 맵 생성
    map<string, int> reportCounts;
    map<string, int> result;
    
    for(string &id : id_list)
    {
        reportCounts[id] = 0;
        result[id] = 0;
    }
    
     // 3단계: 각 사용자에 대한 신고 수 카운트
    for(auto &r : reportSet)
    {
        // 문자열 분리
        istringstream iss(r); 
        string word;
        vector<string> vec;
        while (iss >> word) 
        {
            vec.push_back(word);
        }
        
        string reporter = vec[0];
        string reported = vec[1];
        
        
        reportCounts[reported]++;   
    }
    
    // 4단계: k 이상 신고 된 사용자의 알림 수 카운트
    for(auto &r : reportSet)
    {
        // 문자열 분리
        istringstream iss(r); 
        string word;
        vector<string> vec;
        while (iss >> word) 
        {
            vec.push_back(word);
        }
        
        string reporter = vec[0];
        string reported = vec[1];
        
        
        if(reportCounts[reported] >= k)
        {
            result[reporter]++;
        }
    }
    
    // 5단계: 최종 결과 벡터 준비
    vector<int> ans(id_list.size(),0);
    for (int i = 0; i < id_list.size(); i++)
    {
        ans[i] = result[id_list[i]];
    }
    
    return ans;
}