using System;

public class Solution 
{
    public int solution(int[] num_list) 
    {
        int i = 0;
        int count = 0;
        
        foreach(int num in num_list) {
            int current = num;
             while(current > 1) {
            
                if(current%2 == 0) {
                    current /= 2;
                    count++;
                }
                else if(current%2 == 1) {
                    current -= 1;
                    current /= 2;
                    count++;
                }
            }
        }      
        return count;
    }
}