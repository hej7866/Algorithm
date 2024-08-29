using System;

public class Solution 
{
    public int[,] solution(int[] num_list, int n) 
    {
        int row = num_list.Length / n;
        int col = n;
        int[,] resultList = new int[row,col];
        
        int index = 0;
        int count = 0;
        for(int i=0; i<row; i++)
        {
            while(true)
            {
                resultList[i,count] = num_list[index];
                count++;
                index++;
                if(count == n)
                {
                    count = 0;
                    break;
                }
            }
        }
        return resultList;
    }
}