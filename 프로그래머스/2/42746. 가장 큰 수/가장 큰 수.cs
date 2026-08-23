using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution 
{
    public string solution(int[] numbers) 
    {
        // 배열을 스트링으로 바꿔서 저장
        List<string> num = new List<string>();
        for(int i=0; i<numbers.Length; i++)
        {
            num.Add(numbers[i].ToString());
        }
        
        num.Sort((a, b) => string.Compare(b + a, a + b));
        
        StringBuilder sb = new StringBuilder();
        foreach(string str in num)
        {
            sb.Append(str);
        }
        string result = sb.ToString();
        if(result[0] == '0')
        {
            result = "0";
        }
        return result;
       
    }
}