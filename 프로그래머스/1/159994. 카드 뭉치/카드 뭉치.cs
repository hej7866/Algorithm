using System;

public class Solution 
{
    public string solution(string[] cards1, string[] cards2, string[] goal) 
    {
        int i = 0;  // cards1의 다음에 뽑을 위치
        int j = 0;  // cards2의 다음에 뽑을 위치
        
        foreach (string word in goal)
        {
            if (i < cards1.Length && cards1[i] == word)
            {
                i++;
            }
            else if (j < cards2.Length && cards2[j] == word)
            {
                j++;
            }
            else
            {
                return "No";  // 어느 쪽 맨 앞과도 안 맞으면 완성 불가능
            }
        }
        
        return "Yes";
    }
}