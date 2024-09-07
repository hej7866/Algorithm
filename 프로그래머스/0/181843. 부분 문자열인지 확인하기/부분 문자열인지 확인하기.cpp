#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string target) 
{
    int answer = 0;
    
    // 문자열이 있는지 없는지만 체크하면되니까 search 만약 index가 궁금하면 compare
    if(search(my_string.begin(), my_string.end(), target.begin(), target.end()) != my_string.end())
    {
         answer = 1;
    }
    return answer;       
}