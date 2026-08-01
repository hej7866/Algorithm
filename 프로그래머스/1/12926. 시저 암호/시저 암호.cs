using System;
public class Solution 
{
    public string solution(string s, int n) 
    {
        char[] arr = s.ToCharArray();
        for(int i = 0; i < arr.Length; i++)
        {
            if(arr[i] == ' ')
            {
                continue;
            }
            
            char baseChar = char.IsUpper(arr[i]) ? 'A' : 'a';
            int offset = ((arr[i] - baseChar) + n) % 26;
            arr[i] = (char)(baseChar + offset);
        }
        
        return new string(arr);
    }
}