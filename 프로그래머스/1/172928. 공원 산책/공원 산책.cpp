#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    int row = park.size();
    int col = park[0].size();
    vector<vector<char>> park2D(row, vector<char>(col));
    
    // 시작위치 설정
    vector<int> pos(2,0);
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[i].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                pos[0] = i;
                pos[1] = j;
            }
            park2D[i][j] = park[i][j];
        }
    }     
    
    // 방향과 움직이는 칸 수를 벡터에 각각 담는다.
    vector<char> op;
    vector<int> n;
    for(string &route : routes)
    {
        op.push_back(route[0]);
        n.push_back(route[2] - '0');
    }
    
    // 명령에 따라 움직이는 로직
    int command = routes.size();
    for(int i=0; i<command; i++)
    {
        int currV = pos[0];
        int currH = pos[1];
        bool isPossible = true;
        if(op[i] == 'E')
        {
            if(currH + n[i] < col) // 현재 위치에서 오른쪽으로 n[i]만큼 움직였을때 공원을 이탈하는지에대한 여부
            {
                for(int p = currH; p <= currH + n[i]; p++)
                {
                    if(park2D[currV][p] == 'X')
                    {
                        isPossible = false; // 만약 장애물을만난다면 명령수행이 불가능하니 isPossible을 false로 설정
                    }
                }
                if(isPossible) // 명령수행이 가능하다면
                {
                    pos[1] = currH + n[i]; // pos[1]을 재설정
                }
            }
        }
        else if(op[i] == 'W') 
        {
            if(currH - n[i] >= 0) // 현재 위치에서 왼쪽으로 n[i]만큼 움직였을때 공원을 이탈하는지에대한 여부
            {
                for(int p = currH; p >= currH - n[i]; p--)
                {
                    if(park2D[currV][p] == 'X')
                    {
                        isPossible = false; // 만약 장애물을만난다면 명령수행이 불가능하니 isPossible을 false로 설정
                    }
                }
                if(isPossible) // 명령수행이 가능하다면
                {
                    pos[1] = currH - n[i]; // pos[1]을 재설정
                }
            }
        }
        else if(op[i] == 'N') 
        {
            if(currV - n[i] >= 0) // 현재 위치에서 윗쪽으로 n[i]만큼 움직였을때 공원을 이탈하는지에대한 여부
            {
                for(int p = currV; p >= currV - n[i]; p--)
                {
                    if(park2D[p][currH] == 'X')
                    {
                        isPossible = false; // 만약 장애물을만난다면 명령수행이 불가능하니 isPossible을 false로 설정
                    }
                }
                if(isPossible) // 명령수행이 가능하다면
                {
                    pos[0] = currV - n[i]; // pos[0]을 재설정
                }
            }
        }
        else if(op[i] == 'S') 
        {
            if(currV + n[i] < row) // 현재 위치에서 아랫쪽으로 n[i]만큼 움직였을때 공원을 이탈하는지에대한 여부
            {
            for(int p = currV; p <= currV + n[i]; p++)
                {
                    if(park2D[p][currH] == 'X')
                    {
                        isPossible = false; // 만약 장애물을만난다면 명령수행이 불가능하니 isPossible을 false로 설정
                    }
                }
                if(isPossible) // 명령수행이 가능하다면
                {
                    pos[0] = currV + n[i]; // pos[0]을 재설정
                }
            }
        }
    }
    
    return pos;
}