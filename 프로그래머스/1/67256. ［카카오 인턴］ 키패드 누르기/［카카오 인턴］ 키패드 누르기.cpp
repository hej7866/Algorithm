#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) 
{
    vector<vector<string>> phone = 
    {
        {"1","2","3"},
        {"4","5","6"},
        {"7","8","9"},
        {"*","0","#"},
    };
    
    vector<string> hands;
    hands.push_back(phone[3][0]);
    hands.push_back(phone[3][2]);
    
    string ans = "";
    for(int n : numbers)
    {
        string num = to_string(n);
        if(num == "1" || num == "4" || num == "7")
        {
            ans += "L";
            hands[0] = num;
        }
        else if(num == "2" || num == "5" || num == "8" || num == "0")
        {
            int llen = 0;
            int rlen = 0;
            vector<int> pos(2,0);
            vector<int> lpos(2,0);
            vector<int> rpos(2,0);
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(num == phone[i][j])
                    {
                        pos[0] = i;
                        pos[1] = j;
                    }
                    
                    if(hands[0] == phone[i][j])
                    {
                        lpos[0] = i;
                        lpos[1] = j;
                    }
                    
                    if(hands[1] == phone[i][j])
                    {
                        rpos[0] = i;
                        rpos[1] = j;
                    }
                }
            }
            llen = abs(pos[0] - lpos[0]) + abs(pos[1] - lpos[1]);
            rlen = abs(pos[0] - rpos[0]) + abs(pos[1] - rpos[1]);
            
            if(llen < rlen)
            {
                ans += "L";
                hands[0] = num;
            }
            else if(llen > rlen)
            {
                ans += "R";
                hands[1] = num;
            }
            else if(llen == rlen)
            {
                if(hand == "right")
                {
                    ans += "R";
                    hands[1] = num;
                }
                else
                {
                    ans += "L";
                    hands[0] = num;
                }
            }
        }
        else if(num == "3" || num == "6" || num == "9")
        {
            ans += "R";
            hands[1] = num;
        }
    }
    return ans;
}