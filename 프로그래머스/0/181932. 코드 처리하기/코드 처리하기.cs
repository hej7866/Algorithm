using System;

// 문자열비교

public class Solution {
    public string solution(string code) {
        string answer = "";
        int mode = 0;
        for (int i=0; i<=code.Length-1; i++) {
            if(mode == 0) {
                if (code[i].ToString() != "1") {
                    if (i%2 == 0) {
                        answer += code[i];
                    }
                }
                else if (code[i].ToString() == "1") {
                    mode = 1;
                }
            }
            else if(mode == 1) {
                if (code[i].ToString() != "1") {
                    if (i%2 == 1) {
                        answer += code[i];
                    }
                }
                else if (code[i].ToString() == "1") {
                    mode = 0;
                }
        
            }
        }
        if (answer == "") {
            return "EMPTY";
        }
        return answer;
    }
}