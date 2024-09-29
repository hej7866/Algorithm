using System;

public class Solution 
{
    public string solution(string video_len, string pos, string op_start, string op_end, string[] commands) 
    {
        string[] vArr = video_len.Split(':');
        string[] pArr = pos.Split(':');
        string[] sArr = op_start.Split(':');
        string[] eArr = op_end.Split(':');
        
        int v = Int32.Parse(vArr[0]) * 60 + Int32.Parse(vArr[1]);
        int p = Int32.Parse(pArr[0]) * 60 + Int32.Parse(pArr[1]);
        int s = Int32.Parse(sArr[0]) * 60 + Int32.Parse(sArr[1]);
        int e = Int32.Parse(eArr[0]) * 60 + Int32.Parse(eArr[1]);
            
        for(int i=0; i<commands.Length; i++)
        {
            if(s <= p && p <= e)
            {
                p = e;
                if(commands[i] == "next")
                {
                    p += 10; 
                    if(p > v) { p = v; }
                }
                else if(commands[i] == "prev")
                {
                    p -= 10;
                    if(p < 0) { p = 0; }
                }
            }
            else
            {
                if(commands[i] == "next")
                {
                    p += 10;
                    if(p > v) { p = v; }
                }
                else if(commands[i] == "prev")
                {
                    p -= 10;
                    if(p < 0) { p = 0; }
                }
            }
        }
        
        if(s <= p && p <= e)
        {
            p = e;
        }
        
        Console.Write("{0} {1} {2} {3}",v, p, s, e);
        
        string result = "";
        
        if(p/60 != 0)
        {
            if(p/60 < 10)
            {
                result += "0" + (p/60).ToString();
            }
            else
            {
                result += (p/60).ToString();
            }
        }
        else { result += "00"; }
        result += ":";
        if(p%60 != 0)
        {
            if(p%60 < 10)
            {
                result += "0" + (p%60).ToString();
            }
            else
            {
                result += (p%60).ToString();
            }
        }
        else { result += "00"; }
        return result;
    }
}