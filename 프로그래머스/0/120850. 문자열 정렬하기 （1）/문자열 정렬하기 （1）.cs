using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string my_string) 
    {
        List<int> selectNum = new List<int>();
        
        for(int i=0; i<my_string.Length; i++)
        {
            if(Char.IsDigit(my_string[i]))
            {
                selectNum.Add(Int32.Parse(my_string[i].ToString()));
            }
        }
        selectNum.Sort();
        return selectNum.ToArray();
    }
}