#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string my_string) 
{
    vector<string> vec;
    string temp = "";
    for(char &c : my_string)
    {
        if(c != ' ')
        {
            temp += c;
        }
        else if(c == ' ')
        {

            vec.push_back(temp);
            temp = "";
        }
    }
    vec.push_back(temp);
    
    
    vector<string> num_vec;
    vector<string> op_vec;
    for(int i=0; i<vec.size(); i++)
    {
        if(i%2 == 0)
        {
            num_vec.push_back(vec[i]);
        }
        else
        {
            op_vec.push_back(vec[i]);
        }
    }
    int sum = stoi(num_vec[0]);
    for(int i = 0; i<op_vec.size(); i++)
    {
        if(op_vec[i] == "+")
        {
            sum += stoi(num_vec[i+1]);
        }
        else if(op_vec[i] == "-")
        {
            sum -= stoi(num_vec[i+1]);
        }
    }
    return sum;
}