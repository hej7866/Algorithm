using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        int num_list_multiply = 1;
        int num_list_add = 0;
        for (int i=0; i<num_list.Length; i++) {
            num_list_multiply *= num_list[i];
            num_list_add += num_list[i];
        }
        return answer = (num_list_multiply < num_list_add * num_list_add) ? 1 : 0;
    }
}