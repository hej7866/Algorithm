#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) 
{
    auto max_it = max_element(array.begin(), array.end()); // max_element는 최대값의 위치를 찾는 메서드

    // distance(array.begin(), max_it); 은 array의 처음부터 시작해서 max_it이 등장하는 위치를 인덱스 값으로 반환한다
    int max_index = distance(array.begin(), max_it);  
    vector<int> result;
    result.push_back(*max_it);
    result.push_back(max_index);
    return result;
}