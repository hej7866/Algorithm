using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        string even = "";
        string odd = "";
        for (int i=0; i<num_list.Length; i++) {
            if (num_list[i]%2 == 0) {
                even += num_list[i].ToString();
            }
            else if (num_list[i]%2 == 1) {
                odd += num_list[i].ToString();
            }
        }
        return Int32.Parse(even) + Int32.Parse(odd) ;
    }
}