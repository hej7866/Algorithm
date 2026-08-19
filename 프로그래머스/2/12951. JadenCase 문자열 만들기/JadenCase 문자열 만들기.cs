using System.Text;

public class Solution 
{
    public string solution(string s) 
    {
        StringBuilder sb = new StringBuilder();
        bool isStartOfWord = true; // 지금 위치가 단어의 첫 글자인지 여부

        foreach (char c in s)
        {
            if (c == ' ')
            {
                sb.Append(c);
                isStartOfWord = true; // 공백을 만나면 다음 글자는 새 단어의 시작
            }
            else
            {
                if (isStartOfWord)
                {
                    sb.Append(char.ToUpper(c)); // 단어의 첫 글자는 대문자로
                }
                else
                {
                    sb.Append(char.ToLower(c)); // 나머지는 소문자로
                }
                isStartOfWord = false; // 다음 글자부터는 더 이상 단어의 시작이 아님
            }
        }

        return sb.ToString();
    }
}