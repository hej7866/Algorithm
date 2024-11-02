#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) 
{
    int n = friends.size();
    // Map each friend's name to a unique index
    unordered_map<string, int> name_to_index;
    for(int i = 0; i < n; ++i)
    {
        name_to_index[friends[i]] = i;
    }
    
    // Initialize arrays to track total given and received
    vector<int> given(n, 0);
    vector<int> received(n, 0);
    
    // Initialize a 2D array to track gifts given from A to B
    vector<vector<int>> gifts_given(n, vector<int>(n, 0));
    
    // Process each gift record
    for(auto &gift : gifts)
    {
        // Split the string into giver and receiver
        size_t space_pos = gift.find(' ');
        string A = gift.substr(0, space_pos);
        string B = gift.substr(space_pos + 1);
        
        int a = name_to_index[A];
        int b = name_to_index[B];
        
        given[a] += 1;
        received[b] += 1;
        gifts_given[a][b] += 1;
    }
    
    // Calculate gift index for each friend
    vector<int> gift_index(n, 0);
    for(int i = 0; i < n; ++i)
    {
        gift_index[i] = given[i] - received[i];
    }
    
    // Initialize array to track gifts each friend will receive next month
    vector<int> received_next(n, 0);
    
    // Iterate over all unique pairs of friends
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j)
        {
            int a_to_b = gifts_given[i][j];
            int b_to_a = gifts_given[j][i];
            
            if(a_to_b > b_to_a)
            {
                // Friend i has given more to j, so i receives one gift from j
                received_next[i] += 1;
            }
            else if(b_to_a > a_to_b)
            {
                // Friend j has given more to i, so j receives one gift from i
                received_next[j] += 1;
            }
            else{
                // Equal number of gifts given to each other, compare gift indices
                if(gift_index[i] > gift_index[j])
                {
                    // Friend i has a higher gift index, receives one gift from j
                    received_next[i] += 1;
                }
                else if(gift_index[j] > gift_index[i])
                {
                    // Friend j has a higher gift index, receives one gift from i
                    received_next[j] += 1;
                }
                // If gift indices are equal, no one receives a gift
            }
        }
    }
    
    // Find the maximum number of gifts any friend will receive
    int max_gifts = 0;
    for(auto &count : received_next)
    {
        if(count > max_gifts)
        {
            max_gifts = count;
        }
    }
    
    return max_gifts;
}