#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    vector<char> vec;
    for(char &c : my_string)
    {
        if(isdigit(c))
        {
            vec.push_back(c);
        }
    }
    
    int sum = 0;
    for(char &c : vec)
    {
        sum += c - '0';
    }
    return sum;
}