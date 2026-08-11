using System;

public class Solution 
{
    public int solution(int[] numbers)
    {
        int result = 0;
        for(int i=0; i<=9; i++)
        {    
            if(!numbers.Contains(i))
            {
                result += i;
            }
        }
        return result;
    }
}