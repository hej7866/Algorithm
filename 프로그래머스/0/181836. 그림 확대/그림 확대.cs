using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] picture, int k) 
    {
        List<string> pictureK = new List<string>();
        
        for(int i=0; i<picture.Length; i++)
        {
            string temp = "";
            string pictrueStr = picture[i];
            for(int j=0; j<picture[i].Length; j++)
            {
                for(int w=0; w<k; w++)
                {
                    temp += pictrueStr[j].ToString();
                }
            }
            
            for(int g=0; g<k; g++)
            {
                pictureK.Add(temp);
            }            
        }
        return pictureK.ToArray();
    }
}