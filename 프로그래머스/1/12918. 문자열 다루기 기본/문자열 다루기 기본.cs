using System;

public class Solution 
{
    public bool solution(string s) 
    {
        bool isBool = true;
        foreach(char c in s)
        {
            if(!Char.IsDigit(c))
            {
                isBool = false;
                break;
            }
        }

        if(s.Length != 4 && s.Length != 6)
        {
            isBool = false;
        }
        return isBool;
    }
}