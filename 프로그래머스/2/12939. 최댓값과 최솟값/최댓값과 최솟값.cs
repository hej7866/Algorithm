using System;

public class Solution 
{
    public string solution(string s) 
    {
        string[] str = s.Split(' ');
        int[] arr = new int [str.Length];
        for(int i=0; i<str.Length; i++)
        {
            arr[i] = Int32.Parse(str[i]);
        }
        Array.Sort(arr);
        string ans = arr[0].ToString() + " " + arr[arr.Length - 1].ToString();
        return ans;
    }
}