using System;
using System.Linq;

        
public class Solution 
{
    public int solution(string[] strArr) 
    {
        int[] answer = new int[31];
        for(int i=0; i<strArr.Length; i++) {
            answer[strArr[i].Length]++;
        }
        return answer.Max();
    }     
}