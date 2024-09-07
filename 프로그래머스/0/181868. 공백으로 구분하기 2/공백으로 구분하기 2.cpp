#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;
    string space = " ";
    string temp = "";
    
    bool isCheck;
    for(int i=0; i<my_string.length(); i++)
    {
        if(my_string.compare(i,1,space) == 0)
        {
            isCheck = false;
        }
        else
        {
            isCheck = true;
            temp += my_string[i];
        }
        
        if(!isCheck && !temp.empty() || !temp.empty() && i == my_string.length() - 1)
        {
            answer.push_back(temp);
            temp = "";
        }
    }
    return answer;
}