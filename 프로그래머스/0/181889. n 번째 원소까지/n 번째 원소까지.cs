using System;

public class Solution 
{
    public int[] solution(int[] num_list, int n) 
    {
        int[] answer = new int[n];
        Array.Copy(num_list,0,answer,0,n);
        return answer;
    }
}