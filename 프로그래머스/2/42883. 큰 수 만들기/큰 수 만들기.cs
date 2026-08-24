using System;
using System.Collections.Generic;

public class Solution
{
    public string solution(string number, int k)
    {
        List<char> list = new List<char>();

        foreach (char c in number)
        {
            while (list.Count > 0 && k > 0 && list[list.Count - 1] < c)
            {
                list.RemoveAt(list.Count - 1);
                k--;
            }

            list.Add(c);
        }

        if (k > 0)
        {
            list.RemoveRange(list.Count - k, k);
        }

        return new string(list.ToArray());
    }
}