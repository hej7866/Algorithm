#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) 
{
    vector<string> answer;
    
    int index = 0;  
    string temp = "";
    for(string &s : str_list)
    {
        if(s == "l" || s == "r")
        {
            temp = s;
            break;
        }
        index++;
    }
    

    if(temp == "l")
    {
        for(int i=0; i<index; i++)
        {
            answer.push_back(str_list[i]);
        }
    }
    else if(temp == "r")
    {
        for(int i=index+1; i<str_list.size(); i++)
        {
            answer.push_back(str_list[i]);
        }
    }

    return answer;
}