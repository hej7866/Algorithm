public class Solution 
{
    public bool solution(string s) 
    {
        if(s.Length != 4 && s.Length != 6)
        {
            return false;
        }
        
        foreach(char c in s)
        {
            if(c >= 65)
            {
                return false;
            }
        }
        
        return true;
    }
}