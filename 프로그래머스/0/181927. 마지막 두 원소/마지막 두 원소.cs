using System;

public class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[num_list.Length+1];
        for(int i=0; i<num_list.Length; i++) {
            answer[i] = num_list[i];
            if(i == num_list.Length-1) {
                if (num_list[num_list.Length-1] > num_list[num_list.Length-2]) {
                    answer[i+1] = num_list[num_list.Length-1] - num_list[num_list.Length-2];
                }
                else if (num_list[num_list.Length-1] <= num_list[num_list.Length-2]) {
                    answer[i+1] = num_list[num_list.Length-1] * 2;
                }            
            }
        }
        return answer;
    }
}