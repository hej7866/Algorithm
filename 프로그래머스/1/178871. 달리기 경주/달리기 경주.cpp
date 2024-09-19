#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    unordered_map<string, int> playerIndex;
    
    // Key와 Value설정
    for (int i = 0; i < players.size(); ++i) 
    {
        playerIndex[players[i]] = i;
    }

    for (const string &name : callings) 
    {
        // 호출된 플레이어의 인덱스 찾기
        int index = playerIndex[name];
        
        // 이전 플레이어와 스왑
        string temp = players[index - 1];
        players[index - 1] = players[index];
        players[index] = temp;
            
        // 인덱스 업데이트
        playerIndex[temp] = index; // 스왑된 플레이어의 인덱스 업데이트
        playerIndex[name] = index - 1; // 호출된 플레이어의 인덱스 업데이트
    }
    return players;
}