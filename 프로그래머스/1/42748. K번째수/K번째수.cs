using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] array, int[,] commands) 
    {
        List<int> temp = new List<int>();
        int[] result = new int[commands.GetLength(0)];
        for(int i=0; i<commands.GetLength(0); i++)
        {
            for(int j=commands[i,0]; j<=commands[i,1]; j++)
            {
                temp.Add(array[j - 1]);
            }
            int[] tmp = temp.ToArray();
            Array.Sort(tmp);
            result[i] = tmp[commands[i,2] - 1];
            temp.Clear();
        }
        return result;
    }
}