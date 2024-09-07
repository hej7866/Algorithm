#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) 
{
    vector<string> answer;
    string temp = "";
    for(int i=0; i<myString.length(); i++)
    {
        if(myString.compare(i,1,"x") == 0)
        {
            if(!temp.empty())
            {
                answer.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += myString[i];
        }
    }
    if(!temp.empty())
    {
        answer.push_back(temp);
    }
    sort(answer.begin(), answer.end());
    return answer;
}