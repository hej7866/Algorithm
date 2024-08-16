using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string my_string, string is_prefix) {
        int answer = 0;
        
        int ml = my_string.Length;
        string[] prefix = new string[ml];
        List<string> list_prefix = new List<string>();
        
        // 글자를 떼어서 리스트로 할당
        for(int i=0; i<=ml; i++){
            list_prefix.Add(my_string.Substring(0,i));
        }
        
        // 리스트를 배열로 바꾸기
        prefix = list_prefix.ToArray();
        
        // prefix 배열에 is_prefix 가 있는지 찾는 코드
        foreach(string prf in prefix) {
            if(prf == is_prefix) {
                answer = 1;
            }
        }
        return answer;
    }
}