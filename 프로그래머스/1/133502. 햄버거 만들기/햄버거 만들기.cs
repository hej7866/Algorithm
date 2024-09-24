using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] ingredient) 
    {
        int count = 0;
        string str = "";
        for(int i=0; i<ingredient.Length; i++)
        {
            if(str.Length < 8)
            {
                str += ingredient[i].ToString();
            }
            else if(str.Length >= 8)
            {
                str += ingredient[i].ToString();
                str = str.Remove(0, 1);
            }
            
            // Console.WriteLine(str);
            if(str.Contains("1231"))
            {
                str = str.Replace("1231","");
                count++;
            }
        }
        return count;
    }
}