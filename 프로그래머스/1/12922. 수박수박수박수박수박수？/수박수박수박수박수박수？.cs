using System;

public class Solution 
{
    public string solution(int n) 
    {
        string ans = "";
        for(int i=1; i<=n; i++)
        {
            if(i%2 == 0)
            {
                ans += '박';
            }
            else
            {
                ans += '수';
            }
        }
        return ans;
    }
}