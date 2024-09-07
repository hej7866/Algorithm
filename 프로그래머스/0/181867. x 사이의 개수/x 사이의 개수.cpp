#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string myString) 
{
    vector<int> answer;
    string temp = "";
    int count = 0;
    for(int i=0; i<myString.length(); i++)
    {
        if(myString.compare(i,1,"x") == 0)
        {
            answer.push_back(count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}