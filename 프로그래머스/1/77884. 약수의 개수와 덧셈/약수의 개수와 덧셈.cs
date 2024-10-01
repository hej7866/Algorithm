using System;

public class Solution 
{
    public int solution(int left, int right) 
    {
        int sum = 0;
        for(int i = left; i<=right; i++)
        {
            int t = 1;
            int count = 0;
            while(t <= i)
            {
                if(i%t == 0) { count++; }
                t++;
            }
            if(count%2 == 0) { sum += i; }
            else if(count%2 != 0) { sum -= i; }
        }
        return sum;
    }
}