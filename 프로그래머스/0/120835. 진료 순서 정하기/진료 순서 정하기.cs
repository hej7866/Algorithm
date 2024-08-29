using System;
using System.Linq;
public class Solution 
{
    public int[] solution(int[] emergency) 
    {
        int[] rankList = new int[emergency.Length];
        int count = 1;
        while(count != emergency.Length + 1)
        {            
            int max = emergency.Max();
            for(int i=0; i<emergency.Length; i++)
            {
                if(emergency[i] == max)
                {
                    rankList[i] = count;
                    emergency[i] = 0;
                    count++;
                }
            }
        }
        return rankList;
    }
}