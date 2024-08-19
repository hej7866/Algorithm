using System;

public class Solution 
{
    public int solution(string myString, string pat) 
    {
        int answer = 0;
        
        // 대소문자 구분없이 문자열 포함여부 검사하는방법
        bool isContains = myString.Contains(pat, StringComparison.OrdinalIgnoreCase); 
        return answer = (isContains) ? 1 : 0;
    }
}