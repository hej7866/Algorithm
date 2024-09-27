#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    map<string, int> surveyMap;
    
    // key 와 value 설정
    surveyMap["RT"] = 1;
    surveyMap["TR"] = 1;
    surveyMap["CF"] = 2;
    surveyMap["FC"] = 2;
    surveyMap["JM"] = 3;
    surveyMap["MJ"] = 3;
    surveyMap["AN"] = 4;
    surveyMap["NA"] = 4;
    
    vector<vector<int>> vec(4,vector<int>(2,0));
    for(int i=0; i<survey.size(); i++)
    {
        if(surveyMap[survey[i]] == 1)
        {
            if(survey[i] == "RT")
            {
                if(choices[i] > 4) { vec[0][1] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[0][0] += 4 - choices[i]; }
            }
            else if(survey[i] == "TR")
            {
                if(choices[i] > 4) { vec[0][0] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[0][1] += 4 - choices[i]; }
            }
        }
        else if(surveyMap[survey[i]] == 2)
        {
            if(survey[i] == "CF")
            {
                if(choices[i] > 4) { vec[1][1] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[1][0] += 4 - choices[i]; }
            }
            else if(survey[i] == "FC")
            {
                if(choices[i] > 4) { vec[1][0] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[1][1] += 4 - choices[i]; }
            }
        }
        else if(surveyMap[survey[i]] == 3)
        {
            if(survey[i] == "JM")
            {
                if(choices[i] > 4) { vec[2][1] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[2][0] += 4 - choices[i]; }
            }
            else if(survey[i] == "MJ")
            {
                if(choices[i] > 4) { vec[2][0] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[2][1] += 4 - choices[i]; }
            }
        }
        else if(surveyMap[survey[i]] == 4)
        {
            if(survey[i] == "AN")
            {
                if(choices[i] > 4) { vec[3][1] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[3][0] += 4 - choices[i]; }
            }
            else if(survey[i] == "NA")
            {
                if(choices[i] > 4) { vec[3][0] += choices[i] - 4; }
                else if(choices[i] < 4) { vec[3][1] += 4 - choices[i]; }
            }
        }
    }
    string result = "";
    if(vec[0][0] > vec[0][1]) { result +="R"; }
    else if(vec[0][0] < vec[0][1]) { result +="T"; }
    else { result +="R"; }
    
    if(vec[1][0] > vec[1][1]) { result +="C"; }
    else if(vec[1][0] < vec[1][1]) { result +="F"; }
    else { result +="C"; }
    
    if(vec[2][0] > vec[2][1]) { result +="J"; }
    else if(vec[2][0] < vec[2][1]) { result +="M"; }
    else { result +="J"; }
    
    if(vec[3][0] > vec[3][1]) { result +="A"; }
    else if(vec[3][0] < vec[3][1]) { result +="N"; }
    else { result +="A"; }
    
    return result;
}


// 문제를 푼 뒤 참고한 가독성 좋은 코드
// #include <string>
// #include <vector>
// #include <map>

// using namespace std;

// char MBTI[4][2] = 
// {
//     {'R','T'},
//     {'C','F'},
//     {'J','M'},
//     {'A','N'}
// };

// string solution(vector<string> survey, vector<int> choices) {
//     string ans = "";
//     map<char,int> score;

//     for(int i = 0; i < survey.size(); ++i)
//     {
//         if(choices[i] < 4)
//         {
//             score[survey[i][0]] += (4 - choices[i]);
//         } 
//         else
//         {
//             score[survey[i][1]] += (choices[i] - 4); 
//         }
//     }

//     for(int i = 0; i < 4; ++i)
//     {
//         if(score[MBTI[i][0]] >= score[MBTI[i][1]]) { ans += MBTI[i][0]; }
//         else { ans += MBTI[i][1]; }
//     }

//     return ans;
// }