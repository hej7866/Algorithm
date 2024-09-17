#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) 
{
    vector<int> answer(emergency.size(),1);
    
    for(int i=0; i<emergency.size(); i++)
    {
        for(int &c : emergency)
        {
            if(emergency[i] < c)
            {
                answer[i]++;
            }
        }
    }
    return answer;
}


// #include <string>
// #include <vector>
// #include <map>
// using namespace std;

// vector<int> solution(vector<int> emergency) {
//     auto amt = map<int, int>();
//     for (auto& e : emergency) { amt[e]; }
//     auto order = amt.size();
//     for (auto& e : amt) { e.second = order--; }
//     for (auto& e : emergency) { e = amt[e]; }
//     return emergency;
// }
