#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    string a_str = to_string(a);
    string b_str = to_string(b);
    
    string sumAB = a_str + b_str;
    string sumBA = b_str + a_str;
    string result = "";
    if(stoi(sumAB) > stoi(sumBA))
    {
        result = sumAB;
    }
    else if(stoi(sumAB) < stoi(sumBA))
    {
        result = sumBA;
    }
    else
    {
        result = sumAB;
    }
    return stoi(result);
}