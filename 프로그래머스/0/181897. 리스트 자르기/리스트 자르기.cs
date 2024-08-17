using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int n, int[] slicer, int[] num_list) 
    {
        List<int> num = new List<int>();
        int a = slicer[0];
        int b = slicer[1];
        int c = slicer[2];
        
        switch (n) {
            case 1:
                for (int i=0; i<=b; i++) {
                    num.Add(num_list[i]);
                }
                break;
            case 2:
                for (int i=a; i<num_list.Length; i++) {
                    num.Add(num_list[i]);
                }
                break;
            case 3:
                for (int i=a; i<=b; i++) {
                    num.Add(num_list[i]);
                }
                break;
            case 4:
                    for (int i=a; i<=b; i = i+c) {
                    num.Add(num_list[i]);
                }
                break;
        }
        int[] answer = num.ToArray();
        return answer;
    }
}