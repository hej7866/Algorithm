#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string a, string b) 
{
    int alen = a.length();
    int blen = b.length();
    
    int len = (alen >= blen) ? (alen + 1) : (blen + 1);
    bool isLenA = (alen >= blen) ? true : false;
    
    vector<int> avec; // a를 한글자씩 때서 담을 벡터
    vector<int> bvec; // b를 한글자씩 때서 담을 벡터
    
    // 각각의 벡터에 값을 할당하는 과정
    for(char &c : a)
    {
        avec.push_back(c-'0');
    }
    for(char &c : b)
    {
        bvec.push_back(c-'0');
    }
    
    if(isLenA)
    {
        while(bvec.size() < avec.size())
        {
            bvec.insert(bvec.begin(),0);
        }      
    }
    else if(!isLenA)
    {
        while(bvec.size() > avec.size())
        {
            avec.insert(avec.begin(),0);
        }   
    }
    
    
    vector<int> vec(len,0);
    
    // 덧셈로직
    for(int i=avec.size()-1; i>=0; i--)
    {
        int x = avec[i];
        int y = bvec[i];
        
        int sum = x + y;
        vec[i+1] += sum;
        
        if(vec[i+1] >= 10)
        {
            vec[i] += vec[i+1]/10;
            vec[i+1] = vec[i+1]%10;
        }
    }
    
    // 만약 첫번째 문자가 0이라면 0은 지워준다.
    if(vec[0] == 0)
    {
        vec.erase(vec.begin(),vec.begin()+1);
    }
    // 벡터에 담겨있는 요소를 이어붙혀 문자열로 만드는 과정
    string result = "";
    for(int &i : vec)
    {
        result += to_string(i);
    }
    return result;
}