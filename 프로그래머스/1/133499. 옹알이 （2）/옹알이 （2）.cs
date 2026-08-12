using System;
using System.Text.RegularExpressions;

public class Solution 
{
    public int solution(string[] babbling) 
    {
        int count = 0;
        
        foreach (string word in babbling)
        {
            string tmp = word;
            tmp = tmp.Replace("aya", "1");
            tmp = tmp.Replace("ye", "2");
            tmp = tmp.Replace("woo", "3");
            tmp = tmp.Replace("ma", "4");
            
            // 조건1: 치환하고 남은 글자가 없어야 함 (4개 음절로만 이루어짐)
            bool onlyValidSyllables = true;
            foreach (char c in tmp)
            {
                if (c != '1' && c != '2' && c != '3' && c != '4')
                {
                    onlyValidSyllables = false;
                    break;
                }
            }
            
            // 조건2: 같은 숫자(음절)가 연속되면 안 됨
            bool hasConsecutive = false;
            for (int i = 0; i < tmp.Length - 1; i++)
            {
                if (tmp[i] == tmp[i + 1])
                {
                    hasConsecutive = true;
                    break;
                }
            }
            
            if (onlyValidSyllables && !hasConsecutive)
            {
                count++;
            }
        }
        
        return count;
    }
}