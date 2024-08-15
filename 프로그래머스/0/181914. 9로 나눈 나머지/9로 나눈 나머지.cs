using System;


public class Solution 
{
    public int solution(string number) 
    {
        int answer = 0;
        int n = 0;
        foreach (char num in number) {
            n += Int32.Parse(num.ToString());
        }
        return n%9;
    }
}