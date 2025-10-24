#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> arr) {
    string ans;
    for(string s : arr)
    {
        ans += s;
    }
    cout << ans;
    return ans;
}