public class Solution 
{
    public string solution(string s, int n) 
    {
        char[] charArr = s.ToCharArray();
        for(int i=0; i<charArr.Length; i++)
        {
            if(charArr[i] != ' ')
            {
                if (charArr[i] >= 97 && charArr[i] <= 122) 
                {
                    if (charArr[i] + n > 122) 
                    {
                        charArr[i] = (char)(charArr[i] + n - 26);
                    } 
                    else 
                    {
                        charArr[i] = (char)(charArr[i] + n);
                    }
                }
                else if(charArr[i] >= 65 && charArr[i] <= 90)
                {
                    if (charArr[i] + n > 90) 
                    {
                        charArr[i] = (char)(charArr[i] + n - 26);
                    } 
                    else 
                    {
                        charArr[i] = (char)(charArr[i] + n);
                    }
                }
            }
        }
        string newS = new string(charArr);
        return newS;
    }
}