using System;

public class Solution 
{
    public string solution(string cipher, int code) 
    {
        string result = "";
        for(int i=code; i<=cipher.Length; i = i + code) {
            result += cipher[i-1];
        }
        return result;
    }
}