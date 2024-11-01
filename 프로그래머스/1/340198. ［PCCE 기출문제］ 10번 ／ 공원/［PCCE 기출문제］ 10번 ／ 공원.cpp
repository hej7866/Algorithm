#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 주어진 위치에서 지정된 크기의 돗자리를 놓을 수 있는지 확인하는 함수
bool canPlaceMat(const vector<vector<string>>& park, int row, int col, int size) 
{
    for (int i = row; i < row + size; ++i) 
    {
        for (int j = col; j < col + size; ++j) 
        {
            // 공원 범위를 벗어나거나 사람이 있는 위치인 경우 false 반환
            if (i >= park.size() || j >= park[0].size() || park[i][j] != "-1") 
            {
                return false;
            }
        }
    }
    return true;
}

// 가장 큰 돗자리 크기를 찾는 함수
int solution(vector<int> mats, vector<vector<string>> park) 
{
    // 돗자리를 크기 순으로 내림차순 정렬
    sort(mats.rbegin(), mats.rend());
    
    // 돗자리 크기별로 공원의 모든 위치에서 배치 가능 여부 확인
    for (int size : mats) 
    {
        for (int i = 0; i < park.size(); ++i) 
        {
            for (int j = 0; j < park[0].size(); ++j) 
            {
                if (canPlaceMat(park, i, j, size)) 
                {
                    return size; // 가장 큰 돗자리 크기를 반환
                }
            }
        }
    }
    
    return -1; // 깔 수 있는 돗자리가 없는 경우
}