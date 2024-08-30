using System;

public class Solution 
{
    public int[] solution(int[] num_list) 
    {
        int[] evenoddList = new int[2];
        for(int i=0; i<num_list.Length; i++)
        {
            if(num_list[i]%2 == 0)
            {
                evenoddList[0]++;
            }
            else
            {
                evenoddList[1]++;
            }
        }
        return evenoddList;
    }
}