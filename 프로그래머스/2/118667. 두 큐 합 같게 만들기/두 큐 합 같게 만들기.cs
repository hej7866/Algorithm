using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] queue1, int[] queue2) 
    {
        Queue<int> q1 = new Queue<int>(queue1);
        Queue<int> q2 = new Queue<int>(queue2);
        
        int length = queue1.Length;
        int limit = queue1.Length * 4;
        long sum1 = 0;
        long sum2 = 0;
        int count = 0;
        for(int i=0; i<length; i++)
        {
            sum1 += queue1[i];
            sum2 += queue2[i];
        }
        
        while(sum1 != sum2)
        {
            if (sum1 > sum2)
            {
                int v = q1.Dequeue();
                q2.Enqueue(v);

                sum1 -= v;
                sum2 += v;
            }
            else
            {
                int v = q2.Dequeue();
                q1.Enqueue(v);

                sum2 -= v;
                sum1 += v;
            }

            count++;
            if(count == limit)
            {
                count = -1;
                break;
            }
        }
        return count;
    }
}