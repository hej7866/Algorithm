using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string[] babbling) 
    {
        // 옹알이에 해당하는 문자열을 key로 그거에 대응하는 value를 특수문자로 저장하기 위한 Dictionary
        Dictionary<string, string> dic = new Dictionary<string, string>(); 
        
        string[] Key = new string[] {"aya", "ye", "woo", "ma"}; // key가 될 배열
        string[] Value = new string[] {"@", "#", "$", "%"};     // value가 될 배열
        
        int answer = 0;
        // dic에 key와 value를 할당하는 과정
        for(int i=0; i<Key.Length; i++)
        {
            dic[Key[i]] = Value[i];
        }
        
        // babbling에 들어있는 각 요소를 변형하는 과정
        for(int i=0; i<babbling.Length; i++)
        {
            for(int j=0; j<Key.Length; j++)
            {
                while(babbling[i].Contains(Key[j]))
                {
                    babbling[i] = babbling[i].Replace(Key[j],dic[Key[j]]);
                }
            }
        }
        
        // 그렇게 만들어진 각 요소들이 네 가지 발음을 이어붙힌 형태로만 이루어져있으며
        // 같은 발음이 연속되지는 않는지 점검하는 로직
        foreach(string str in babbling)
        {
            bool isBool = false; // babbling의 요소를 이루는 각 글자가 value의 원소들 중 하나인지 체크하는 변수
            for(int i=0; i<str.Length; i++)
            {
                if(str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%')
                {
                    isBool = true; // str[i]가 @ # $ % 중 하나라면 true
                }
                else
                {
                    isBool = false; // 그렇지 않으면 false로 바꾸고
                    break;          // 반복문 탈출
                }
            }
            
            bool isSame = false; // 발음이 연속되어 있는지 체크하는 변수
            if(isBool) // 만약 babbling의 요소를 이루는 각 글자가 모두 value의 원소들 중 하나라면
            {
                for(int i=0; i<str.Length - 1; i++)
                {
                    if(str[i] == str[i+1]) // str의 i번째 글자와 i+1번째 글자가 같다면
                    {
                        isSame = true; // 발음이 연속되는 것이다.
                        break;         // 발음이 연속된다면 break;
                    }
                }
            }
            // babbling의 요소를 이루는 각 글자가 모두 value의 원소들 중 하나이고 발음이 연속되지않는다면
            if(isBool && !isSame) 
            {
                answer++; // answer 1증가
            }
            Console.WriteLine(answer);
        }
        return answer;
    }
}