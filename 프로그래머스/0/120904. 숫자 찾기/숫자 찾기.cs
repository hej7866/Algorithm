using System;

public class Solution 
{
    public int solution(int num, int k) 
    {
        string numStr = num.ToString();
        int answer = -1;
        for(int i=0; i<numStr.Length; i++) {
            if(numStr[i].ToString() == k.ToString()) {
                answer = i+1;
                break;
            }
        }
        return answer;
    }
}