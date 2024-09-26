using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] number) 
    {
        int idx = 0;
        int count = 0;
        while(idx < number.Length-2)
        {
            for(int i=idx; i<number.Length-2; i++)
            {
                int[] numList = new int[3];
                numList[0] = number[idx];
                for(int j=i+1; j<number.Length-1; j++)
                {
                    numList[1] = number[j];
                    for(int k=j+1; k<number.Length; k++)
                    {
                        numList[2] = number[k];
                        int sum = 0;
                        foreach(int num in numList)
                        {
                            sum += num;
                        }
                        if(sum == 0) { count++; }
                    }
                }
                idx++;
            }
            
        }
        return count;
    }
}