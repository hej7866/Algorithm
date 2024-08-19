using System;
using System.Linq;

public class Solution 
{
    public string[] solution(string myString) 
    {
        string[] str = myString.Split('x');
        Array.Sort(str);
        
        // Where메소드로 조건에 맞는 요소들만 필터링
        // !string.IsNullOrEmpty로 문자열이 비어있지 않고 null이 아닌 경우만 포함하도록 함
        return str.Where(w => !string.IsNullOrEmpty(w)).ToArray(); 
        
    }
}