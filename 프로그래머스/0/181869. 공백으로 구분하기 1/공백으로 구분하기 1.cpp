#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;
    string temp = "";
    string space = " ";
    for(int i=0; i<my_string.length(); i++)
    {
        if(my_string.compare(i,1,space) == 0) // index를 한칸씩 옮겨가며 1칸씩 점검할건데 그게 공백이라면
        {
            if(!temp.empty()) // 만약 temp가 비어있지 않다면 answer에 추가
            {
                answer.push_back(temp);
                temp = ""; // temp를 다시 빈문자열로 초기화
            }
        }
        else
        {    
            temp += my_string[i];  // index를 한칸씩 옮겨가며 1칸씩 점검할건데 그게 공백이아니라면 temp에 그 값을 붙힘
        }
    }
    answer.push_back(temp); // 맨 뒷글자는 공백이 아니므로 최종적으로 temp에 들어있는 값을 직접 추가
    return answer;
}