using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] names) 
    {
        List<string> nameList = new List<string>();
        
        for (int i=0; i<names.Length; i++) {
            if (i%5 == 0) {
                nameList.Add(names[i]);
            }
        }
        return nameList.ToArray();
    }
}