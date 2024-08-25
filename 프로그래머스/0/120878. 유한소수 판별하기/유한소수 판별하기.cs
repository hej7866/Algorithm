using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int a, int b) 
    {
        List<int> divNumA = new List<int>();
        List<int> divNumB = new List<int>();
        
        divNumA.Add(a);
        divNumB.Add(b);
        int index=0;
        for(int i=2; i<=divNumA[index]; i++) {
            if(divNumA[index]%i == 0 && divNumB[index]%i == 0) {
                divNumA.Add(divNumA[index]/i);
                divNumB.Add(divNumB[index]/i);
                index++;
            }
        }
        List<int> div = new List<int>();
        int temp = divNumB[divNumB.Count-1];
        int k = 2;
        while(temp>1) {
            while(temp % k == 0) {
                div.Add(k);
                temp /= k;
            }
            k++;
        }
        int answer = 1;
        
        foreach(int num in div) {
            if(num != 2 && num != 5) {
                answer = 2;
            } 
        }

        return answer;
    }
}