using System;

public class Solution 
{
    public int[] solution(int[] arr, int n) 
    {
        for(int i=0; i<arr.Length; i++) {
            if(arr.Length%2 == 1) {
                if(i%2 == 0) {
                    arr[i] += n;
                }
            }
            else if(arr.Length%2 == 0) {
                if(i%2 == 1) {
                    arr[i] += n;
                }
            }
        }
        return arr;
    }
}