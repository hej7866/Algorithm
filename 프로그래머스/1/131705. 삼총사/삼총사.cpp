#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) 
{
    int idx = 0;
    int count = 0;
    while(idx < number.size() - 2)
    {
        for(int i = idx; i < number.size() - 2; i++)
        {
            vector<int> vec(3,0);
            vec[0] = number[i];
            for(int j = i+1; j < number.size() - 1; j++)
            {
                vec[1] = number[j];
                for(int k = j+1; k < number.size(); k++)
                {
                    vec[2] = number[k];
                    int sum = 0;
                    for(int &i : vec)
                    {
                        sum += i;
                    }
                    if(sum == 0) { count++; }
                }
            }
            idx++;
        }
    }
    return count;
}