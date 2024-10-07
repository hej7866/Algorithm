using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] array, int[,] commands) 
    {
        List<int> ans = new List<int>();
        for(int i=0; i<commands.GetLength(0); i++)
        {
            int s = commands[i,0] - 1;
            int e = commands[i,1] - 1;
            int k = commands[i,2] - 1;
            
            List<int> list = new List<int>();
            for(int j=s; j<=e; j++)
            {
                list.Add(array[j]);
            }
            list.Sort();
            ans.Add(list[k]);
        }
        return ans.ToArray();
    }
}