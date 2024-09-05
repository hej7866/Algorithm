#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    string sum_ab = to_string(a) + to_string(b);
    int answer = 0;
    if(stoi(sum_ab) >= 2 * a * b)
    {
        answer = stoi(sum_ab);
    }
    else
    {
        answer = 2 * a * b;
    }
    return answer;
}