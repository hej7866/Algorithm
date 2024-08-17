using System;

public class Solution {
    public int solution(int[] arr, int idx) {
        int answer = -1;
        int index = 0;
        foreach(int i in arr) {
            if (i == 1 && index >= idx) {
                answer = index;
                break;
            }
            index++;
        }
        return answer;
    }
}