using System;

public class Solution 
{
    public string solution(string myString, string pat) 
    {
        while(myString.Length > 0) {
            if(myString.EndsWith(pat)){
                break;
            }
            myString = myString.Remove(myString.Length-1,1);
        }
        return myString;
    }
}