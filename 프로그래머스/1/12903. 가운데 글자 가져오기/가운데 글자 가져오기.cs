public class Solution 
{
    public string solution(string s) 
    {
        string ans = "";
        if(s.Length % 2 == 1)
        {
           ans = s[(s.Length - 1) / 2].ToString();
        }
        else
        {
            ans += s[(s.Length) / 2 - 1];
            ans += s[(s.Length) / 2];
        }
        return ans;
    }
}