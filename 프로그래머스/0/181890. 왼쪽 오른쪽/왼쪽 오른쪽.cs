using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] str_list) 
    {
        int count = 0; 
        List<string> strList = new List<string>(str_list); // 먼저 리스트에 str_list배열을 옮겨담는다.
        List<string> answerList = new List<string>(); // 반환할 값을 담을 리스트를 만든다
        
        for (int i=0; i<str_list.Length; i++) { // i을 0부터 str의 길이만큼 반복하면서
            if(str_list[i] == "l") { // str_list의 i번째 인덱스의 값이 l이라면
                answerList = strList.GetRange(0, i); // answerList에 strList의 0부터 count 값을 떼와서 붙히기
                break; // 더 순환할 필요가없으므로 for문 탈출
            }
            else if(str_list[i] == "r") { // str_list의 i번째 인덱스의 값이 r이라면
                // answerList에 strList의 count+1부터 strList.Count - count -1 만큼의 값을 떼와서 붙히기
                answerList = strList.GetRange(i+1,strList.Count - i -1);
                break; // 더 순환할 필요가없으므로 for문 탈출
            }
        }
        string[] answer = answerList.ToArray();
        return answer;
    }
}