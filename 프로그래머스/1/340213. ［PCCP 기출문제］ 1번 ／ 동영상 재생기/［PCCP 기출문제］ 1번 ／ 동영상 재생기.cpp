#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    // #1. 문자열로 표현된 시간을 정수형 vec형태로 변환하는 작업 
    string delimiter = ":";
    istringstream isv(video_len);
    istringstream isp(pos);
    istringstream iss(op_start);
    istringstream ise(op_end);
    string token;
    
    // 현재 시점
    vector<int> videoVec;
    while(getline(isv, token, delimiter[0])) 
    {
        videoVec.push_back(stoi(token));
    }
    int v = videoVec[0] * 60 + videoVec[1];
    
    // 현재 시점
    vector<int> posVec;
    while(getline(isp, token, delimiter[0])) 
    {
        posVec.push_back(stoi(token));
    }
    int p = posVec[0] * 60 + posVec[1];
    
    // 오프닝 시작시간
    vector<int> startVec;
    while(getline(iss, token, delimiter[0])) 
    {
        startVec.push_back(stoi(token));
    }
    int s = startVec[0] * 60 + startVec[1];
    
    // 오프닝 엔딩시간
    vector<int> endVec;
    while(getline(ise, token, delimiter[0])) 
    {
        endVec.push_back(stoi(token));
    }
    int e = endVec[0] * 60 + endVec[1];
    
    
    // 비디오 시점 이동 로직
    for(int i=0; i<commands.size(); i++)
    {
        bool isBool = (s <= p && p <= e);

        if(isBool)
        {
            p = e;
            if(commands[i] == "next")
            {
                p += 10;
                if(p > v) { p = v; }
            }
            else if(commands[i] == "prev")
            {
                p -= 10;
                if(p < 0) { p = 0; }
            }
        } 
        else if(!isBool)
        {
            if(commands[i] == "next")
            {
                p += 10;
                if(p > v) { p = v; }
            }
            else if(commands[i] == "prev")
            {
                p -= 10;
                if(p < 0) { p = 0; }
            }
        }
    }
    
    if((s <= p && p <= e))
    {
        p = e;
    } 
    
    
    string result = "";
    if(p/60 != 0) 
    {
        if(p/60 < 10)
        {
            result += string("0") + to_string(p/60); 
        }
        else
        {
            result += to_string(p/60); 
        }
    }
    else if(p/60 == 0) { result += "00"; }
    
    result += ":";
    
    if(p%60 != 0)
    {
        if(p%60 < 10)
        {
            result += string("0") + to_string(p%60); 
        }
        else
        {
            result += to_string(p%60); 
        }
    }
    else if(p%60 == 0) { result += "00"; }
    
    cout << result;
    
    return result;
}