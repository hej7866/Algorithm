using System;

public class Solution 
{
    int count;
    
    public int solution(string word) 
    {
        count = 0;
        char[] alphabet = new char[] {'A', 'E', 'I', 'O', 'U'};
        return DFS("", word, alphabet);
    }
    
    int DFS(string prefix, string target, char[] alphabet)
    {
        count++;
        
        if (prefix == target)
        {
            return count - 1;
        }
        
        if (prefix.Length == 5)
        {
            return 0; // 더 이상 못 늘어남 = 못 찾음
        }
        
        for (int i = 0; i < alphabet.Length; i++)
        {
            int result = DFS(prefix + alphabet[i], target, alphabet);
            if (result != 0)
            {
                return result; // 찾았으면 그 즉시 위로 전달하고 끝
            }
        }
        
        return 0; // 5개 다 시도했는데 못 찾음
    }
}