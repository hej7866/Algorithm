#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> result;
    
    vector<int> todayVec;
    // today를 정수형으로 [yyyy,mm,dd] 와 같이 vec에 담는 과정
    string tmp = "";
    for(char &c : today)
    {
        if(c != '.') { tmp += c; }
        else if(c == '.')
        {
            todayVec.push_back(stoi(tmp));
            tmp = "";
        }
    }
    todayVec.push_back(stoi(tmp));
    
    // terms를 map으로 만드는 과정 
    vector<char> key;
    vector<int> value;
    for(string &t : terms)
    {
        string v = "";
        for(char &c : t)
        {
            if(!isdigit(c) && c != ' ')
            {
                key.push_back(c);
            }
            else if(isdigit(c) && c != ' ')
            {
                v += c;
            }
        }
        value.push_back(stoi(v));
    }
    
    map<char, int> termsMap;
    for(int i=0; i<key.size(); i++)
    {
        termsMap[key[i]] = value[i];
    }
    
    // privacies에 담겨져있는 날짜를 떼어서 vector로 담기
    vector<vector<int>> curPriVec;
    for(string &p : privacies)
    {
        vector<int> pv;
        string tmp = "";
        for(char &c : p)
        {          
            if(c != '.' && c != ' ')
            {
                tmp += c;
            }
            else if(c == '.' || c == ' ')
            {
                pv.push_back(stoi(tmp));
                tmp = "";
            }
        }
        curPriVec.push_back(pv);
    }
    
    // curPriVec에서 약관 기한만큼 지난 이후의 날짜를 담을 nextPriVec 선언
    vector<vector<int>> nextPriVec = curPriVec;   
    
    // nextPriVec에 숫자를 할당하는 로직
    for(int i=0; i<privacies.size(); i++)
    {
        string p = privacies[i]; 
        
        char t = p[p.length() - 1]; // p의 마지막 글자는 약관 종류를 나타내므로 그걸 t에 담는다.
        int a = termsMap[t]; // 약관종류 t를 key로하여 그에 대응하는 value를 a에 담는다.
        
        // 먼저 일 수에 -1을 해주는 과정
        nextPriVec[i][2] = curPriVec[i][2] - 1; 
        if(nextPriVec[i][2] == 0) // 일 수가 0이라면
        {
            nextPriVec[i][2] = 28; // 일 수를 28로 변경
            nextPriVec[i][1] -= 1; // 그리고 달 수에 -1를 해준다.
        }
        if(nextPriVec[i][1] == 0) // 위 과정에서 달 수에 -1을 해줬을때 0이 된다면
        {
            nextPriVec[i][1] = 12; // 달 수를 12로 변경
            nextPriVec[i][0] -= 1; // 년 수에 -1를 해준다.
        }
        
        int tmp = nextPriVec[i][1] + a; // 위 과정에 모두 끝난 뒤 달 수 + 약관종류 t에 대응하는 유효기간
        
        if(tmp > 12)
        {
            nextPriVec[i][0] += tmp/12;
            nextPriVec[i][1] = tmp%12;
            if( nextPriVec[i][1] == 0)
            {
                nextPriVec[i][1] = 12; 
                nextPriVec[i][0] -= 1;
            }
        }
        else if(tmp <= 12)
        {
            nextPriVec[i][1] = tmp;
        }
        
    }
    
    int num = 1;  
    for(auto &v : nextPriVec)
    {
        if(v[0] < todayVec[0])
        {
            result.push_back(num);
            num++;
            continue;
        }
        else if(v[0] == todayVec[0] && v[1] < todayVec[1])
        {
            result.push_back(num);
            num++;
            continue;
        }
        else if(v[0] == todayVec[0] && v[1] == todayVec[1] && v[2] < todayVec[2])
        {
            result.push_back(num);
            num++;
            continue;
        }
        else
        {
            num++;
        }
    }
    // 디버그 용
    for(auto v : nextPriVec)
    {
        for(int y : v) { cout << y << " "; }
        cout << endl;
    }

    return result;
}