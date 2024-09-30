using System;

public class Solution 
{
    public int solution(string s) 
    {
        string[] numArr = new string[10] 
        {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        
        for(int i=0; i<=9; i++)
        {
            while(s.Contains(numArr[i]))
            {
                s = s.Replace(numArr[i], i.ToString());
            }
        }
        return Int32.Parse(s);
    }
}