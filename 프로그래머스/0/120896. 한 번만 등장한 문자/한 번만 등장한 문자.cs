using System;
using System.Linq;

public class Solution 
{
    public string solution(string s) 
    {
        var charCount = s.GroupBy(c => c)
                         .Where(g => g.Count() == 1)
                         .Select(g => g.Key)
                         .ToArray();
        Array.Sort(charCount);
        string answer = new string(charCount);
        return answer;
    }
}