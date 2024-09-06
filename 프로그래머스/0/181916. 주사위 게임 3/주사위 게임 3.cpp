#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) 
{
    vector<int> numVec = { a, b, c, d};
    vector<int> countVec(4,1);
    
    for(int i=0; i<=2; i++)
    {
        for(int j=i+1; j<=3; j++)
        {
            if(numVec[i] == numVec[j])
            {
                countVec[i]++;
                countVec[j]++;
            }
        }
    }
    
    int answer = 0;
    if(find(countVec.begin(), countVec.end(), 4) != countVec.end())
    {
        answer = 1111 * a;  
    }
    else if(find(countVec.begin(), countVec.end(), 3) != countVec.end())
    {
        int oneIdx = 0;
        int threeIdx = 0;
        for(int i=0; i<countVec.size(); i++)
        {
            if(countVec[i] == 1) { oneIdx = i; }
            if(countVec[i] == 3) { threeIdx = i; }
        }
        answer = (10 * numVec[threeIdx] + numVec[oneIdx]) * (10 * numVec[threeIdx] + numVec[oneIdx]);
    }
    else if(find(countVec.begin(), countVec.end(), 2) != countVec.end())
    {
        if(find(countVec.begin(), countVec.end(), 1) != countVec.end())
        {
            int temp = 1;
            for(int i=0; i<countVec.size(); i++)
            {
               if(countVec[i] == 1)
               {
                   temp *= numVec[i];
               }
            }
            answer = temp;
        }
        else
        {
            int temp1 = numVec[0];
            int temp2 = 0;
            for(int i=0; i<numVec.size(); i++)
            {
               if(temp1 != numVec[i])
               {
                   temp2 = numVec[i];
               }
            }
            answer = (temp1 + temp2) * abs(temp1 - temp2);
        }
    }
    else
    {
        int min = numVec[0];
        for(int i=1; i<numVec.size(); i++)
        {
            if(min > numVec[i])
            {
                min = numVec[i];
            }
        }
        answer = min;
    }
    return answer;
}