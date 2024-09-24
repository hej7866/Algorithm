#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) 
{
    sort(score.begin(), score.end(), greater<int>()); // score 벡터를 내림차순으로 정렬
    
    int box = score.size() / m; // 만들어야할 박스의 갯수
    int boxCount = 0; // 만든 박스의 갯수
    
    int result = 0; // 결과를 담을 변수
    
    
    if(box != 0) // 만들어질 박스의 갯수가 0이 아니면
    {
        while(true)
        {
            vector<int> vec; // 한개의 상자를 의미하는 벡터 입출력 예 2번에 따르면 [1,1,2] [2,2,2] 등을 의미함.
            for(int i=0; i<m; i++)
            {
                vec.push_back(score[m * boxCount + i]); // vec에 값을 넣는 작업
            }
            // 디버깅 용
            // for(int &i : vec)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            result += vec[m-1] * m;
            boxCount++; // 만든 박스의 갯수를 1증가
            box--; // 만들어야할 박스의 갯수는 1개 감소
            if(box == 0) // 만들어야할 박스의 갯수가 0이되면 
            {
                break; // 반복문 탈출
            }
        }
    }
    else if(box == 0) // 애초에 만들어야할 박스가 0개라면 0을리턴
    {
        return 0;
    }
    return result;
}