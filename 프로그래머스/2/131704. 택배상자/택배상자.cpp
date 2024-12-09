#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    stack<int> stack;  // 보조 컨테이너 벨트
    int index = 0;     // order 배열의 현재 위치
    int n = order.size();
    
    for (int box = 1; box <= n; ++box) {  // 메인 컨테이너 벨트에서 상자 처리
        if (box == order[index]) {
            index++;  // 바로 트럭에 실을 수 있음
        } else {
            stack.push(box);  // 보조 컨테이너 벨트에 저장
        }
        
        // 보조 벨트의 상자를 트럭에 실을 수 있는지 확인
        while (!stack.empty() && stack.top() == order[index]) {
            stack.pop();
            index++;
        }
    }
    
    return index;  // 트럭에 실은 상자의 개수
}
