using System;

public class Solution 
{
    public int solution(int[] common) 
    {
        int answer = 0;
        bool isArithmetic = false; // 등차수열인지 체크하고자 만든 bool변수
        bool isGeometric = false;  // 등비수열인지 체크하고자 만든 bool변수
        int cl = common.Length;    // common의 길이
        
        int a = common[0]; // 첫째항
        int d = 0;         // 공차
        int r = 0;         // 공비
        if(common[1]-common[0] == common[cl-1]-common[cl-2]) { // 만약 둘째항 - 첫째항 == 마지막항 - 마지막전항
            d = common[1]-common[0]; 
            isArithmetic = true; // 등차수열
        }
        else if(common[1]/common[0] == common[cl-1]/common[cl-2]) { // 만약 둘째항/첫째항 == 마지막항/마지막전항
            r = common[1]/common[0];
            isGeometric = true; // 등비수열
        }
        
        if(isArithmetic) {
            answer = common[cl - 1] + d;
        }
        else if(isGeometric) {
            answer = common[cl - 1] * r;
        }
        return answer;
    }
}