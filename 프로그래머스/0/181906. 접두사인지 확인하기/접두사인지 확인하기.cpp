#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_prefix) 
{
    int pos = 0; // 체크할 시작 인덱스

    if (my_string.substr(pos, is_prefix.size()) == is_prefix) {
        return 1;
    } else {
        return 0;
    }
}