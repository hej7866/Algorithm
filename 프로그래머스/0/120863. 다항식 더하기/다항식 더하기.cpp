#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string polynomial) 
{
    string temp = "";
    
    vector<string> var_vec; // 변수를 담는 벡터
    vector<int> con_vec; // 상수를 담는 벡터
    vector<string> op_vec; // 연산자를 담는 벡터
    for(char &c : polynomial) // polynomial을 순회하면서
    {
        if(c != ' ') // c가 공백이 아니면
        {
            temp += c; // temp에 c를 붙힌다.
        }
        else if(c == ' ' && !temp.empty()) // c가 공백이고 temp가 비어있지않으면
        {
            if(temp.find('x') != string::npos) // temp에 x가 포함되어있으면 변수라는 뜻
            {
                var_vec.push_back(temp); // 변수벡터에 temp추가
                temp = ""; // temp초기화
            }
            else if(temp.find('+') != string::npos) // 이 문제에선 굳이 필요없는 작업이지만 연산자를 담는 로직 
            {
                op_vec.push_back(temp);
                temp = "";
            }
            else
            {
                con_vec.push_back(stoi(temp)); // 상수라면 temp를 정수형으로 바꿔서 추가
                temp = ""; // temp 초기화
            }
        }
    }
    if(!temp.empty()) // 마지막에 temp에 남아있는 값 처리하는 로직
    {
        if(temp.find('x') != string::npos) // 변수일때
        {
            var_vec.push_back(temp);
        }
        else // 상수일때
        {
            con_vec.push_back(stoi(temp));
        }
    }
    
    // 계수를 계산하는 로직
    int Coefficient = 0; // 변수의 계수를 담는 변수
    for(string &s : var_vec) 
    {
        if(s == "x")
        {
            Coefficient++;
        }
        else
        {
            string coff = "";
            for(char &c : s)
            {
                if(c != 'x')
                {
                    coff += c;
                }
            }
            Coefficient += stoi(coff);
        }
    }
    
    // 상수를 계산하는 로직
    int sum = 0;
    for(int &i : con_vec)
    {
        sum += i;
    }

    // 결과로 반환할 값 result를 만드는 과정
    string result;
    if(Coefficient != 0 && sum != 0)
    {
        if(Coefficient > 1) { result = to_string(Coefficient) + "x" + " " + "+" + " " + to_string(sum); }
        else if(Coefficient == 1) { result = string("x") + " " + "+" + " " + to_string(sum); }
    }
    else if(Coefficient == 0)
    {
        result = to_string(sum);
    }
    else if(sum == 0)
    {
        if(Coefficient > 1) { result = to_string(Coefficient) + "x"; }
        else if(Coefficient == 1) { result = "x"; }
    }
    return result;
}