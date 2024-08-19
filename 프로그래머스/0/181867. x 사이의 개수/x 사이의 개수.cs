using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string myString) 
    {
        string[] str = myString.Split('x');
        List<int> numList = new List<int>();
        
        for(int i=0; i<str.Length; i++) {
            numList.Add(str[i].Length);
        }
        return numList.ToArray();
    }
}