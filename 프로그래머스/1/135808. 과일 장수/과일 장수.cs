using System;

public class Solution 
{
    public int solution(int k, int m, int[] score)
    {
        Array.Sort(score);
        Array.Reverse(score);   

        int box = score.Length / m;
        int count = 0;
        int result = 0;
        if(box == 0)
        {
            return 0;
        }
        if(box != 0)
        {      
            while(true)
            {
                int[] boxArr = new int[m];

                for(int i=0; i<m; i++)
                {
                    boxArr[i] = score[m*count + i];
                }

                result += boxArr[m-1] * m;
                count++;
                box--;
                if(box == 0)
                {
                    break;
                }
            }
        }
        return result;
    }
}