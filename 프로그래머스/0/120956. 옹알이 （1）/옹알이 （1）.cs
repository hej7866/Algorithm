using System;

public class Solution 
{
    public int solution(string[] babbling) 
    {
        // 먼저 조카가 쓸수있는 발음을 배열로 담는다.
        string[] str_list = new string[] { "aya", "ye", "woo", "ma"};
        
        // 배열의 각 요소에 들어있는 문자열을 확인하면서 조카가 쓸수있는 발음을 모두 #으로 바꾼다. ex) wyeoo => w#oo 
        for(int i=0; i<babbling.Length; i++) {
            foreach(string str in str_list) {
                if(babbling[i].Contains(str)) {
                    babbling[i] = babbling[i].Replace(str, "#"); 
                }
            }
        }
        
        int count = 0; // 조카가 발음할 수 있는 단어의 개수를 카운트할 변수
        bool isSharp = true; // 문자열이 #으로만 이루어져있는지 체크하는 bool 변수
        for (int i=0; i<babbling.Length; i++) {
            foreach(char ch in babbling[i]) { // babbling[i]에 들어있는 문자열의 각 글자를 하나씩 체크할건데
                if(ch != '#') { // 만약 ch가 #이아니면
                    isSharp = false; // isSharp을 false로 바꾸고
                    break; // 반복문을 탈출한다.
                }
            }
            if(isSharp) { // isSharp이 true면 즉, 문자열의 모든글자가 #으로만 이루어져 있다면
                count++;  // count를 하나씩 늘리고
            }
            isSharp = true; // isSharp을 마지막에 true로 초기화해준다. 
        }
        return count;
    }
}