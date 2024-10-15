#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) 
{
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    int pos = distance(seoul.begin(), it);
    string p = to_string(pos);
    string ans = "김서방은 " + p + "에 있다";
    return ans;
}