using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string my_string) 
    {
        // 먼저 공백한칸을 기준으로 배열을 만든다.
        string[] str = my_string.Split(' ');
        for(int i=0; i<str.Length; i++) {
            str[i] = str[i].Trim();
        } // 이렇게 만들고나면 공백이 포함된 배열이 완성된다.
        
    
        // 우리가 원하는건 공백이 없는 배열이기 때문에 리스트를 하나 만들어준다. 
        List <string> strList = new List<string>();
        foreach(string s in str) { // foreach문을통해 str에 들어있는 요소하나하나 점검한다.
            if(s == "") { // 요소가 비어있다면 다시 반복문으로 돌아가고
                continue;
            }
            strList.Add(s); // 그렇지 않다면 s를 리스트에 추가한다.
        }
        return strList.ToArray();
        
    }
}