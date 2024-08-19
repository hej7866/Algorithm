using System;

public class Solution 
{
    public int solution(string myString, string pat) 
    {
        // 문자열을 바꾸는거보단 char배열로 바꾼다음 요소를 바꾸는것이 쉽기 때문에 일단 char[]로 바꾸어준다. 
        char[] ch = myString.ToCharArray();
        int answer = 0;
        
        // A는 B로 B는 A로 바꾸는 과정
        for(int i=0; i<ch.Length; i++) {
            if(ch[i] == 'A') {
                ch[i] = 'B';
            }
            else if(ch[i] == 'B') {
                ch[i] = 'A';
            }
        }
        // 다시 string형으로 바꾸기
        string str = new string(ch);

        return answer = (str.Contains(pat)) ? 1 : 0;
    }
}