#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) 
{
    int x = (board[0] - 1)/2;
    int y = (board[1] - 1)/2;
    vector<int> vec(2,0);
    for(string &ip : keyinput)
    {
        if(ip == "up")
        {
            if(vec[1] < y)
            {
                vec[1]++;
            }
        }
        else if(ip == "down")
        {
            if(vec[1] > -y)
            {
                vec[1]--;
            }
        }
        else if(ip == "left")
        {
            if(vec[0] > -x)
            {
                vec[0]--;
            }
        }
        else if(ip == "right")
        {
            if(vec[0] < x)
            {
                vec[0]++;
            }
        }
    }
    return vec;
}