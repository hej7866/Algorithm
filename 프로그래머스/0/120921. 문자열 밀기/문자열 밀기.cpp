#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string A, string B) 
{
    if(A == B) { return 0; }
    else
    {   
        string AA = A + A; // A를 두개 연속으로 연결한다.
        
        // rfind => 그렇게만든 AA에서 B를 찾는데 여러개 등장할경우 마지막 index를 찾는다 만약 없으면 npos반환
        // A의사이즈에서 B가발견된 마지막인덱스를 빼면 밀어야하는 최소횟수가 나옴
        if(AA.rfind(B) != string::npos) { return A.length() - AA.rfind(B); }
        else { return -1; }
    }
    
    
    
    
}