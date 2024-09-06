#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) 
{
    // begin() => 0번째 인덱스를 가르킴
    // end() => 마지막 인덱스 + 1를 가르킴 [,) 
    for(int i=0; i<query.size(); i++)
    {
        if(i%2 == 0)
        {
            arr.erase(arr.begin() + query[i] + 1, arr.end()); // query[i] + 1번째 인덱스부터 마지막 인덱스까지 삭제
        }
        else
        {
            arr.erase(arr.begin(), arr.begin() + query[i]); // 0번째 인덱스부터 query[i]번째 인덱스 전까지 삭제
        }
    }
    return arr;
}