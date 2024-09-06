#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> idx; // arr에서 2가 등장하는 idx값을 모두 저장할 벡터
    for(int i=0; i<arr.size(); i++) // arr을 순회하면서
    {
        if(arr[i] == 2) // arr의 i번째 인덱스 값이 2라면 i를 idx에 추가
        {
            idx.push_back(i);
        }
    }
    
    vector<int> vec; // 결과를 담을 벡터
    if(idx.size() >= 2) // idx의 크기가 2이상이라면
    {
        for(int i=idx[0]; i<=idx[idx.size()-1]; i++) // idx의 첫번째 값부터 마지막 값까지 반복하며
        {
            vec.push_back(arr[i]); // arr[i]값을 vec에 추가
        }
    }
    else if(idx.size() == 1) // idx의 크기가 1이라면
    {
        vec.push_back(arr[idx[0]]); // 입출력예의 2번째 예시로치면 arr[1]값을 vec에 넣는것 사실 2를 넣어줘도 상관없다.
    }
    else if(idx.size() == 0) // idx 크기가 0이면 -1을 추가
    {
        vec.push_back(-1);
    }
    return vec;
}