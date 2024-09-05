using System;

public class Solution 
{
    public string solution(string myString) 
    {
        for(int i=0; i<myString.Length; i++)
        {
            if((int)myString[i] < (int)'l')
            {
                myString = myString.Replace(myString[i].ToString(), "l");
            }
        }
        return myString;
    }
}