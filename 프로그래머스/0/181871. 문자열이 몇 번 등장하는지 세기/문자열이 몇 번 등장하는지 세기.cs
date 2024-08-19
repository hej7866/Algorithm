using System;

public class Solution 
{
    public int solution(string myString, string pat) 
    {
        string str = "";
        int count = 0;
        int Length = myString.Length-pat.Length;
        
        for(int i=0; i<=Length; i++) {
            str = myString.Substring(i, pat.Length);
            if (str.Contains(pat)) {
                count++;
            }
        }
        return count;
    }
}