using System;

using System;

public class Solution 
{
    public int solution(int number, int limit, int power) 
    {
        int[] countArr = new int[number];
        for(int i=1; i<=number; i++)
        {
            for(int j=1; j<=i; j++)
            {
                if(i%j == 0)
                {
                    countArr[i-1]++; 
                }
            }
        }
        
        int result = 0;
        for(int i=0; i<countArr.Length; i++)
        {
            if(countArr[i] > limit)
            {
                countArr[i] = power;
            }
            result += countArr[i];
        }
        return result;
    }
}