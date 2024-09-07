#include <string>
#include <vector>

using namespace std;

int solution(string binomial) 
{
    vector<string> binmVec;
    char space = ' ';
    string temp = "";
    for(char &ch : binomial)
    {
        if(ch == ' ')
        {
            binmVec.push_back(temp);
            temp = "";
        }
        else
        {
            temp += ch;
        }
    }
    binmVec.push_back(temp);
    
    
    int answer = 0;
    string strop = binmVec[1];
    char op = strop[0];
    switch(op)
    {
        case '+':
            answer = stoi(binmVec[0]) + stoi(binmVec[2]);
            break;
        case '-':
            answer = stoi(binmVec[0]) - stoi(binmVec[2]);
            break;
        case '*':
            answer = stoi(binmVec[0]) * stoi(binmVec[2]);
            break;
    }
    return answer;
}