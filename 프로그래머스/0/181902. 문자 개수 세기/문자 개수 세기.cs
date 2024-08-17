using System;

public class Solution {
    public int[] solution(string my_string) {
        int[] answer = new int[52];
        string alpabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        
        for (int i=0; i<52; i++) {
            foreach(char ch in my_string) {
                if (ch == alpabet[i]) {
                    answer[i]++;
                }
            }
        }
        return answer;
    }
}