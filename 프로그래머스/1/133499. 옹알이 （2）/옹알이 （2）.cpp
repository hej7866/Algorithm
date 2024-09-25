#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) 
{
    map<string, char> babbMap;
    
    // map을 만드는 과정
    vector<string> key = {"aya", "ye", "woo", "ma"};
    vector<char> value = {'1', '2', '3', '4'};
    int count = 0;
    for(int i=0; i<key.size(); i++)
    {
        babbMap[key[i]] = value[i]; // ["aya"] = '1' , ["ye"] = '2' ....
    }
    
    for(string &babb : babbling)
    {
        for(int i=0; i<babbMap.size(); i++) // ["aya"] ["ye"] ["woo"] ["ma"] 순으로 체크
        {
            // key[i] => (["aya"] ["ye"] ["woo"] ["ma"])가 babb 에 포함되어있으면..
            while(babb.find(key[i]) != string::npos) 
            {
                size_t pos = babb.find(key[i]); // key[i]가 발견된 시점의 인덱스를 pos로 받아와서
                // babb의 pos시점에서부터 key[i] 만큼의 길이를 value[i]로 바꾼다.
                // 이때 value[i]는 char형이므로 3번째에 1이라는 인자를 넣어준다.
                babb.replace(pos, key[i].length(), 1, value[i]); 
            }
        }
        // 디버깅용
        cout << babb << endl;
        
        bool isOnlyNum = true; // babb이 오직 숫자로만 이루어져있는지 체크하는 변수
        for(char &i : babb)
        {
            if(!isdigit(i))
            {
                isOnlyNum = false;
                break;
            }
        }
        bool isBool = false;
        if(isOnlyNum)
        {
            for(int i=0; i<babb.length()-1; i++)
            {
                if(babb[i] == babb[i+1])
                {
                    isBool = true;
                    break;
                }
            }
        }
        if(isOnlyNum && !isBool)
        {
            count++;
        }
    }
    return count;
}