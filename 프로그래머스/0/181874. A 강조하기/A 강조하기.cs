using System;

public class Solution 
{
    public string solution(string myString) 
    {
        char[] str = myString.ToCharArray();
        
        for(int i=0; i<str.Length; i++) {
            if(str[i] == 'a') {
                str[i] = 'A';
            }
            else if (str[i] != 'a' && str[i] != 'A') {
                str[i] = Char.ToLower(str[i]);
            }
        }
        string strA = new string(str);
        
        return strA;
    }
}