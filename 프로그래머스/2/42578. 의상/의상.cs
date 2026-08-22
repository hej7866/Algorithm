using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string[,] clothes) 
    {
        int c = clothes.GetLength(0);
        Dictionary<string, int> dic = new Dictionary<string, int>();
        for(int i=0; i<c ;i++)
        {
            if(dic.ContainsKey(clothes[i,1]))
            {
                dic[clothes[i,1]]++;
            }
            else
            {
                dic[clothes[i,1]] = 1;
            }
        }
        
        int result = 1;
        foreach(var d in dic)
        {
            result *= (d.Value + 1);
        }
        return result - 1;
    }
}