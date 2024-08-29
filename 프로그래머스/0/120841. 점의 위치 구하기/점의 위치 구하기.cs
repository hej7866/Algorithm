using System;

public class Solution 
{
    public int solution(int[] dot) 
    {
        bool isNegativeX = (dot[0] < 0);
        bool isNegativeY = (dot[1] < 0);
        
        int answer = 0;
        if(!isNegativeX && !isNegativeY)
        {
            answer = 1;
        }
        else if(isNegativeX && !isNegativeY)
        {
            answer = 2;
        }
        else if(isNegativeX && isNegativeY)
        {
            answer = 3;
        }
        else if(!isNegativeX && isNegativeY)
        {
            answer = 4;
        }
        return answer;
    }
}