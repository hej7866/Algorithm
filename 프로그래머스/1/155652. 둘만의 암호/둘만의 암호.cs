using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string s, string skip, int index) 
    {
        string result = "";
        List<char> alphabetList = new List<char>();
        for(int i=0; i<s.Length; i++)
        {   
            int c = 1;
            char ch = s[i];
            char a = (char)((int)ch + c);
            while(alphabetList.Count < index)
            {
                if(a > 'z') { a = 'a'; }
                while(skip.Contains(a))
                {
                    a++;
                    if(a > 'z') { a = 'a'; }
                }
                alphabetList.Add(a);
                a++;
            }
            result += alphabetList[alphabetList.Count - 1];
            alphabetList.Clear();
        }
        return result;
    }
}