using System;

public class Solution 
{
    public string solution(string video_len, string pos, string op_start, string op_end, string[] commands)     
    {
        // 정수화
        int video_len_num = ChangeNumber(video_len);
        int pos_num = ChangeNumber(pos);
        int op_start_num = ChangeNumber(op_start);
        int op_end_num = ChangeNumber(op_end);
        
        if (op_start_num <= pos_num && pos_num <= op_end_num)
        {
            pos_num = op_end_num;
        }
        
        foreach(string command in commands)
        {
            if (command == "next")
            {
                pos_num += 10;
                if (pos_num > video_len_num) pos_num = video_len_num;
            }
            else // prev
            {
                pos_num -= 10;
                if (pos_num < 0) pos_num = 0;
            }
            
            // 2. 매 명령 실행 후 무조건 체크 (양쪽 <= 로 통일)
            if (op_start_num <= pos_num && pos_num <= op_end_num)
            {
                pos_num = op_end_num;
            }
        }
        
        string result = "";
        result += (pos_num / 60 < 10 ? "0" : "") + (pos_num / 60).ToString();
        result += ":";
        result += (pos_num % 60 < 10 ? "0" : "") + (pos_num % 60).ToString();
        
        return result;
    }
    
    int ChangeNumber(string time)
    {
        string[] timeSplit = time.Split(':');
        int m = Int32.Parse(timeSplit[0]) * 60;
        int s = Int32.Parse(timeSplit[1]);
        return m + s;
    }
}