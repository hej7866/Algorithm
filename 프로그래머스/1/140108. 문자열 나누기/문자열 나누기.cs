using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string s) 
    {
        List<string> strList = new List<string>();
        
        int idx = 0;
        while(true)
        {
            char ch = s[idx];
            
            bool isBool = false;
            int eNum = 0;
            int dNum = 0;
            string tmp = "";
            for(int i = idx; i<s.Length; i++)
            {
                if(ch == s[i]) { eNum++; }
                else if(ch != s[i]) { dNum++; }
                
                tmp += s[i];
                
                if(eNum == dNum)
                {
                    strList.Add(tmp);
                    tmp = "";
                    if(i+1<s.Length){ idx = i+1; }
                    else if(i+1 == s.Length) { break; }
                    isBool = true;
                    break;
                }
            }
            
            if(!isBool)
            {
                strList.Add(tmp);
                break;
            }
            
        }
        
        if(strList[strList.Count - 1] == "")
        {
            strList.RemoveAt(strList.Count - 1);
        }
        foreach(string str in strList)
        {
            Console.WriteLine(str);
        }
        return strList.Count;
    }
}