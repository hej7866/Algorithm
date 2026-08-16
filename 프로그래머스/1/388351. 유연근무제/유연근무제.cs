using System;

public class Solution 
{
    public int solution(int[] schedules, int[,] timelogs, int startday) 
    {
        int n = schedules.Length;
        int count = n;
        for(int i=0; i<n; i++)
        {
            int start = startday;
            for(int j=0; j<7; j++)
            {
                int tmp = start % 7;
                if(ChangeFun(timelogs[i,j]) - ChangeFun(schedules[i]) > 10 && tmp != 6 && tmp != 0)
                {
                    count--;
                    break;
                }
                start += 1;
            }
        }
        return count;
    }
    
    int ChangeFun(int time)
    {
        int h = time / 100;
        int m = time % 100;
        return h * 60 + m;
    }
}