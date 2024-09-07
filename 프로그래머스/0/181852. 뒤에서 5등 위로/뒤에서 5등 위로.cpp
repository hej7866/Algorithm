#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(num_list.size()-5); // copy메소드를 쓸려면 벡터크기를 정의해야함
    sort(num_list.begin(), num_list.end());
    
    copy(num_list.begin()+5, num_list.end(), answer.begin());
    return answer;
}