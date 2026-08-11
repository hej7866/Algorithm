using System;
using System.Linq;

public class Solution 
{
    public string solution(string X, string Y) 
    {
        int[] countX = new int[10];
        int[] countY = new int[10];
        
        foreach (char c in X) countX[c - '0']++;
        foreach (char c in Y) countY[c - '0']++;
        
        var result = new System.Text.StringBuilder();
        
        for (int digit = 9; digit >= 0; digit--)  // 큰 숫자부터 내림차순으로
        {
            int common = Math.Min(countX[digit], countY[digit]);
            for (int i = 0; i < common; i++)
            {
                result.Append(digit);
            }
        }
        
        string str = result.ToString();
        
        if (str == "") return "-1";
        if (str[0] == '0') return "0";
        return str;
    }
}