#include <bits/stdc++.h>
using namespace std;

// Problem: Restrictive Candy Crush
// Approach: Use a stack-like structure to keep track of characters and their counts.

// Steps:
// 1. Initialize an empty vector of pairs to act as a stack.
// 2. Iterate through each character in the string.
// 3. If the stack is empty or the top character is different from the current character, push a new pair onto the stack.
// 4. Increment the count of the top character.
// 5. If the count reaches k, pop the top character from the stack.
// 6. Construct the result string from the remaining characters in the stack.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n), for storing the characters in the stack.

class Solution {
    public:
        // Function to reduce the string by removing k consecutive identical characters
        string Reduced_String(int k, string &s) {
                vector<pair<char,int>> st; // Stack to store characters and their consecutive counts
                for(auto &i:s){
                        // If stack is empty or current character is different, push new pair
                        if(st.empty() or st.back().first!=i) 
                                st.push_back({i,0});
                        // Increment the count of the top character
                        if(++st.back().second==k) 
                                st.pop_back(); // Remove if count reaches k
                }
                string ans;
                // Reconstruct the reduced string from the stack
                for(auto &i:st){
                        ans+=string(i.second,i.first);
                }
                return ans;
        }
};