using System;

public class Solution 
{
    public int solution(int[] arr) 
    {
        bool check = false;
        int count = 0;
        
        while(true) {
            
            for(int i=0; i<arr.Length; i++) {
                if(arr[i] >= 50 && arr[i]%2 == 0) {
                    arr[i] /= 2;
                    check = true;
                }
                else if (arr[i] < 50 && arr[i]%2 == 1) {
                    arr[i] *= 2;
                    arr[i]++;
                    check = true;
                }
            }   
            if (!check) {
                break;
            }
            check = false;
            count ++;
        }
        return count;
    }
}