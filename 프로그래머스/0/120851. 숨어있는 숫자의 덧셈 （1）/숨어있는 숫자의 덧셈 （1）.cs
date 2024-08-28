using System;

public class Solution 
{
    public int solution(string my_string) 
    {
        int hideNumSum = 0;
        for(int i=0; i<my_string.Length; i++)
        {
            if(Char.IsDigit(my_string[i]))
            {
                hideNumSum += Int32.Parse(my_string[i].ToString());
            }
        }
        return hideNumSum;
    }
}