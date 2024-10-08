using System;

public class Solution 
{
    public int solution(int[] absolutes, bool[] signs) 
    {
        int sum = 0;
        for(int i=0; i<signs.Length; i++)
        {
            if(signs[i])
            {
                sum += absolutes[i];
            }
            else if(!signs[i])
            {
                sum -= absolutes[i];
            }
        }
        return sum;
    }
}