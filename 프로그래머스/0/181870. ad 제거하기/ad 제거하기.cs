using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] strArr) 
    {
        List<string> strList = new List<string>();
        
        for(int i=0; i<strArr.Length; i++) {
            if(strArr[i].Contains("ad")) {
                continue;
            }
            strList.Add(strArr[i]);
        }
        return strList.ToArray();
    }
}