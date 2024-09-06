#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) 
{
    vector<string> mystrVec;
    
    // 벡터에 my_string의 모든 접미사를 추가
    for(int i=0; i<my_string.length(); i++)
    {   
        int len = my_string.length() - i;
        mystrVec.push_back(my_string.substr(i,len));
    }
    // 만약 mystrVec에 is_suffix가 포함되어있다면 1을 아니면 0을 반환하라.   
    return (find(mystrVec.begin(), mystrVec.end(), is_suffix) != mystrVec.end()) ? 1 : 0;
}