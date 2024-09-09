#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) 
{
    vector<string> result;
    vector<vector<string>> s_vec;
    
    int i = 0; 
    for(string &op : quiz)
    {
        vector<string> temp_vec;
        string temp = "";
        for(char &c : op)
        {
            if(c != ' ')
            {
                temp += c;
            }
            else if(c == ' ')
            {
                temp_vec.push_back(temp);
                temp = "";
            }
        }
        temp_vec.push_back(temp);
        s_vec.push_back(temp_vec);
        i++;
    }
    

    for(int i=0; i<s_vec.size(); i++)
    {     
        int a = stoi(s_vec[i][0]);
        int b = stoi(s_vec[i][2]);
        if(s_vec[i][1] == "+")
        {            
            if(a + b == stoi(s_vec[i][4]))
            {
                result.push_back("O");
            }
            else if (a + b != stoi(s_vec[i][4]))
            {
                result.push_back("X");
            }
        }
        else if(s_vec[i][1] == "-")
        {            
            if(a - b == stoi(s_vec[i][4]))
            {
                result.push_back("O");
            }
            else if (a - b != stoi(s_vec[i][4]))
            {
                result.push_back("X");
            }
        }
    }
    return result;
}