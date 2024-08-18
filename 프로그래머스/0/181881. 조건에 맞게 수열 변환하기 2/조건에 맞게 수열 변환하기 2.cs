using System;

public class Solution 
{
    public int solution(int[] arr) 
    {
        bool check = false; // 조건 체크용 bool변수
        int count = 0; // 반복 횟수
        
        // 무한루프로 배열을 조건에 맞게 계속 변환하는 기능
        while(true) {
            // 매 반복마다 배열의 idx를 하나씩 하나씩 점검하며 아래의 조건에 맞는지 찾아준다. 
            // 만약 맞다면 그 idx에 들어있는 값을 조건에 맞게 변환후 check를 true로 변환
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
            // 만약 check값이 false라면 while 반복문을 탈출해준다.
            if (!check) {
                break;
            }
            // 만약 check 값이 true라면 check 값을 false로 바꾸어주고 반복횟수를 하나 올려준다.
            check = false;
            count ++;
        }
        return count;
    }
}