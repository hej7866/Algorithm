#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) 
{
    vector<string> answer;
    string ad = "ad";
    for(int i=0; i<strArr.size(); i++)
    {
        // 특정 위치에 특정문자열이 있는지 점검하는방법은 compare로 찾는다.
        // 이건 전체 문자열중에 특정문자열이 있는지만 점검하면 되기때문에 search메서드를 쓴다.
        // 매개변수 1,2 =>첫 번째 범위의 시작과 끝을 나타내는 반복자입니다. 검색을 수행할 범위를 지정.
        // 매개변수 3,4 =>두 번째 범위의 시작과 끝을 나타내는 반복자입니다. 찾으려는 서브시퀀스(부분 문자열)를 지정.
        if(search(strArr[i].begin(), strArr[i].end(), ad.begin(), ad.end()) != strArr[i].end())
        {
            continue;
        }
        answer.push_back(strArr[i]);
    }
    return answer;
}