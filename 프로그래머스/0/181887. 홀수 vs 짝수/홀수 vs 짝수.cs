using System;

public class Solution 
{
    public int solution(int[] num_list) 
    {
        int answer = 0;
        int even = 0;
        int odd = 0;

        for (int i=0; i<num_list.Length; i++) {
            if (i%2 == 0) {
                even += num_list[i];
            }
            else {
                odd += num_list[i];
            }
        }
        return answer = (even > odd) ? even : odd;
    }
}