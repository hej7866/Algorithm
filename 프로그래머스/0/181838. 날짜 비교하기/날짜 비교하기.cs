using System;

public class Solution 
{
    public int solution(int[] date1, int[] date2) 
    {
        int i = 0;
        bool isYear = false;
        bool isMonth = false;
        
        int answer = 0;
        if(date1[0] < date2[0])
        {
            answer = 1;
        }
        else if(date1[0] == date2[0])
        {
            isYear = true;
        }
        
        if(isYear && date1[1] < date2[1])
        {
            answer = 1;
        }
        else if(isYear && date1[1] == date2[1])
        {
            isMonth = true;
        }
        
        if(isYear && isMonth && date1[2] < date2[2])
        {
            answer = 1;
        }
        
        
        return answer;
    }
}