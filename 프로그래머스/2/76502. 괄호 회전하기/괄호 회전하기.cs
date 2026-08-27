using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int solution(string s)
    {
        int length = s.Length;
        List<char> sList = s.ToList();
        int count = 0;

        for (int x = 0; x < length; x++)
        {
            Stack<char> stack = new Stack<char>();
            bool isValid = true;

            foreach (char c in sList)
            {
                switch (c)
                {
                    case '[':
                    case '(':
                    case '{':
                        stack.Push(c);
                        break;

                    case ']':
                        if (stack.Count == 0 || stack.Pop() != '[')
                            isValid = false;
                        break;

                    case ')':
                        if (stack.Count == 0 || stack.Pop() != '(')
                            isValid = false;
                        break;

                    case '}':
                        if (stack.Count == 0 || stack.Pop() != '{')
                            isValid = false;
                        break;
                }

                if (!isValid)
                    break;
            }

            if (isValid && stack.Count == 0)
                count++;

            char first = sList[0];

            for (int i = 0; i < sList.Count - 1; i++)
                sList[i] = sList[i + 1];

            sList[sList.Count - 1] = first;
        }

        return count;
    }
}