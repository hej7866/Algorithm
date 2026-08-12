using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string today, string[] terms, string[] privacies) 
    {
        // 약관을 딕셔너리에 넣는과정 dic[A] = 6 이런느낌
        Dictionary<string, int> dic = new Dictionary<string, int>();
        foreach(string term in terms) 
        {
            string[] str = term.Split(' ');
            dic[str[0]] = Int32.Parse(str[1]);
        }
        
        // 오늘 날짜 밸류 계산
        int todayValue = 0;
        string[] todayStrs = today.Split('.');
   
        todayValue = 
            (Int32.Parse(todayStrs[0]) * 28 * 12) + 
            ((Int32.Parse(todayStrs[1]) - 1) * 28) + 
            (Int32.Parse(todayStrs[2]));
        Console.WriteLine(todayValue);
        
        // privacies에 계약 종료날짜를 더한 밸류값 계산
        int[] valueArr = new int[privacies.Length];
        List<int> result = new List<int>();
        for(int i=0; i<privacies.Length; i++)
        {
            string[] str = privacies[i].Split(' ');
            string[] day = str[0].Split('.');
            
            valueArr[i] = 
                (Int32.Parse(day[0]) * 28 * 12) + 
                ((Int32.Parse(day[1]) - 1) * 28) + 
                (Int32.Parse(day[2])) +
                ((dic[str[1]]) * 28);
            if(todayValue >= valueArr[i])
            {
                result.Add(i + 1);
            }
        }
        
        return result.ToArray();
    }
}