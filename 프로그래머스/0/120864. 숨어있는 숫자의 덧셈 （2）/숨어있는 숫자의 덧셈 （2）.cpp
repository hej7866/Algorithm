#include <string>
#include <vector>

using namespace std;

int solution(string my_string) 
{
    vector<int> num;
    string temp = "";
    for(char &c : my_string)
    {
        if(isdigit(c))
        {
            temp += c;
        }
        if(!isdigit(c) && !temp.empty())
        {
            num.push_back(stoi(temp));
            temp = "";
        }
    }
    if(!temp.empty()) { num.push_back(stoi(temp)); }
    
    int sum = 0;
    for(int &i : num)
    {
        sum += i;
    }
    return sum;
}