using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string s, string skip, int index) 
    {
        char[] alphabet = new char[26];
        
        // alphabet 배열에 알파벳을 할당하는 과정
        for(int i=97; i<=122; i++) { alphabet[i-97] = (char)i; }
        
         // alphabetDic 딕셔너리에 알파벳과 인덱스를 매칭하여 할당하는 과정
        Dictionary<char, int> alphabetDic = new Dictionary<char, int>();
        Dictionary<int, char> indexDic = new Dictionary<int, char>();
        
        for(int i=0; i<alphabet.Length; i++) { alphabetDic[alphabet[i]] = i; }
        for(int i=0; i<alphabet.Length; i++) { indexDic[i] = alphabet[i]; }
        
        string result = "";
        List<char> alphabetList = new List<char>();
        for(int i=0; i<s.Length; i++)
        {   
            int c = 1;
            char ch = s[i];
            char a = (char)((int)ch + c);
            while(alphabetList.Count < index)
            {
                if(a > 'z') { a = 'a'; }
                while(skip.Contains(a))
                {
                    a++;
                    if(a > 'z') { a = 'a'; }
                }
                alphabetList.Add(a);
                a++;
            }
            result += alphabetList[alphabetList.Count - 1];
            alphabetList.Clear();
        }
        return result;
    }
}