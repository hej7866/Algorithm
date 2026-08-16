using System;

public class Solution 
{
    public int solution(int[,] signals) 
    {
        int n = signals.GetLength(0);
        int[] cycles = new int[n];
        for (int i = 0; i < n; i++)
        {
            cycles[i] = signals[i,0] + signals[i,1] + signals[i,2];
        }
        
        // 모든 주기의 최소공배수 구하기
        long lcmAll = cycles[0];
        for (int i = 1; i < n; i++)
        {
            lcmAll = LCM(lcmAll, cycles[i]);
        }
        
        for (long t = 1; t <= lcmAll; t++)
        {
            bool allYellow = true;
            for (int i = 0; i < n; i++)
            {
                int G = signals[i,0];
                int Y = signals[i,1];
                long pos = (t - 1) % cycles[i];  // 이 신호등의 주기 안에서 몇 번째 초인지
                
                bool isYellow = (pos >= G && pos < G + Y);
                if (!isYellow)
                {
                    allYellow = false;
                    break;
                }
            }
            
            if (allYellow)
            {
                return (int)t;
            }
        }
        
        return -1;
    }
    
    long GCD(long a, long b)
    {
        while (b != 0)
        {
            long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    
    long LCM(long a, long b)
    {
        return a / GCD(a, b) * b;
    }
}