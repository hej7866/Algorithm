#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) 
{
    string result = "fail";
    bool isLogin = false;
    for(auto &d : db)
    {
        if(id_pw == d)
        {
            result = "login";
            isLogin = true;
        }
    }
    
    if(!isLogin)
    {       
        for(auto &d : db)
        {
            if(id_pw[0] == d[0]) 
            {
                if(id_pw[1] != d[1])
                {
                    result = "wrong pw";
                }
            }
        }
    }
    return result;
}