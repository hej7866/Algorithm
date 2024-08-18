using System;

public class Solution 
{
    public int solution(int[] num_list) 
    {
        int numMul = 1;
        int nunSum = 0;
        int answer = 0;
        
        for(int i=0; i<num_list.Length; i++){
            numMul *= num_list[i];
            nunSum += num_list[i];
        }
        
        return answer = (num_list.Length >= 11) ? nunSum : numMul;
    }
}