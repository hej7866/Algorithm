#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) 
{
    if(num%2 == 1)
    {      
        int i = total/num;
        vector<int> answer(1,i);

        int inc = i;
        int dec = i;
        while(answer.size() < num)
        { 
            answer.insert(answer.begin(), --dec);
            answer.insert(answer.end(), ++inc);
        }
        return answer;
    }
    else
    {      
        int i = total/num;
        vector<int> answer= {i, i+1};
        
        int inc = answer[1];
        int dec = answer[0];
        while(answer.size() < num)
        { 
            answer.insert(answer.begin(), --dec);
            answer.insert(answer.end(), ++inc);
        }
        return answer;
    }
}