using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string s) 
    {
        string tmp = "";
        List<string> tmpList = new List<string>();
        int c1 = 0;
        int c2 = 0;
        
        char x = s[0]; // 처음 문자 세팅
        bool isMatch = false;
        for(int i=0; i<s.Length; i++)
        {
            
            if(isMatch)
            {
                x = s[i];
                isMatch = false;
            }
            
            if(x == s[i])
            {
                c1++;
            }
            else
            {
                c2++;
            }
            tmp += s[i];
            if(c1 == c2)
            {
                tmpList.Add(tmp);
                tmp = "";
                isMatch = true;
            }
        }
        if(tmp.Length != 0)
        {
            tmpList.Add(tmp);
        }
        return tmpList.Count;
    }
}