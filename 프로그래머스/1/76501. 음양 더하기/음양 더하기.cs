using System;

public class Solution 
{
    public int solution(int[] absolutes, bool[] signs) 
    {
        int result = 0;
        for(int i=0; i<absolutes.Length; i++)
        {
            if(!signs[i])
            {
                absolutes[i] *= (-1);
            }
            result += absolutes[i];
        }
        return result;
    }
}