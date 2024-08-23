using System;

public class Solution 
{
    public string solution(string my_string) 
    {
        char[] myList = my_string.ToCharArray(); // 문자열을 char[]로 변환
        for(int i=0; i<myList.Length; i++) {
            if(Char.IsUpper(myList[i])) { // myList[i]가 대문자면
                myList[i] = Char.ToLower(myList[i]); // 소문자로 변환
            }
            else if(Char.IsLower(myList[i])) { // myList[i]가 소문자면
                 myList[i] = Char.ToUpper(myList[i]);// 대문자로 변환
            } 
        }
        string result = new string(myList);
        return result;
    }
}