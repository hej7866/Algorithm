using System;

public class Solution 
{
    public string solution(string s, string skip, int index) 
    {
        string result = "";
        foreach(char c in s)
        {
            int count = 0;
            char tmp = c;
            while(count < index)
            {
                int newIndex = (tmp - 'a' + 1) % 26;
                tmp = (char)('a' + newIndex);   // 먼저 이동
                
                if(!skip.Contains(tmp))          // 이동한 후 도착한 곳이 skip이 아니면
                {
                    count++;                      // 그때 카운트
                }
            }
            result += tmp;
        }
        return result;
    }
}