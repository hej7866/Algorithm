#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    for(char &ch : my_string)
    {
        // 한글자 짜리 char형 문자를 한글자짜리 문자열로 바꾸는방법 to_string은 아스키코드로 변환되기때문에 사용불가.
        string str = string(1, ch); 
        if(str == alp) // 문자열끼리 비교를해주고 만약 같다면
        {
            ch = toupper(str[0]); // str은 문자열이기때문에 str[0]은 char형이된다. 그 값을 대문자로 바꾼뒤 할당해준다.
        }
    }

    return my_string;
}