using System;

public class Solution 
{
    public int[] solution(int[] prices) 
    {
        int[] result = new int[prices.Length];
        for(int i=0; i<prices.Length-1; i++)
        {
            int start = prices[i];
            int count = 0;
            for(int j=i+1; j<prices.Length; j++)
            {
                count++;
                if(start > prices[j])
                {
                    break;
                }
            }
            result[i] = count;
        }
        return result;
    }
}