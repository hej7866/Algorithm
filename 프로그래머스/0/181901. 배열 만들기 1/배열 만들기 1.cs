using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int n, int k) {
        List<int> numbers = new List<int>();
        int i = 1;
        while(k * i <= n) {
            numbers.Add(k * i);
            i++;
        }
        
        int[] answer = numbers.ToArray();
        return answer;
    }
}