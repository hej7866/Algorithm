public class Solution 
{
    public string solution(string[] seoul) 
    {
        int idx = 0;
        for(int i=0; i<seoul.Length; i++)
        {
            if(seoul[i].Contains("Kim"))
            {
                idx = i;
                break;
            }
        }
        string ans = "김서방은 " + idx.ToString() + "에 있다";
        return ans;
    }
}