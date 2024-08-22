using System;
using System.Collections.Generic;
    
public class Solution 
{
    public string[] solution(string my_str, int n) 
    {  
        List<char> strList = new List<char>(); // my_str의 한글자씩 추가하며 n씩자른 문자열을 담을 리스트선언 
        List<string> mystr = new List<string>(); // 결과를 담을 리스트 선언

        for(int i=0; i<my_str.Length; i++) {
            strList.Add(my_str[i]); // my_str을 한 글자씩 때며 strList에 추가
            if (strList.Count == n || i == my_str.Length - 1) { // 이때 strList의 길이가 n이거나 i가 마지막이라면
                char[] str_list = strList.ToArray(); // strList를 char[]배열로 바꾼뒤
                string temp = new string(str_list); // string형으로 바꾸고
                mystr.Add(temp); // 그 값을 mystr에 추가한다 ("abc1Ad", "dfggg4", "556b") 
                strList.Clear(); // 마지막으로 strList에 있는 모든 요소를 제거한다.
            }
        }
        return mystr.ToArray();
    }
}