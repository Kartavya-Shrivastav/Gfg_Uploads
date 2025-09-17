#include <bits/stdc++.h>
using namespace std;

// Problem: Decode the string
// Approach: Using stack to decode the string

// Steps:
// 1. Traverse the string character by character.
// 2. If the character is not ']', push it onto the stack.
// 3. If the character is ']', pop characters from the stack until '[' is found to get the substring.
// 4. Pop the '[' from the stack.
// 5. Pop digits from the stack to get the number of times the substring should be repeated.
// 6. Repeat the substring and push it back onto the stack.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    string decodedString(string &s) {
        string res = "";
    
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                res.push_back(s[i]);
            }
    
            else {
                string temp = "";
                while (!res.empty() && res.back() != '[') {
                    temp.push_back(res.back());
                    res.pop_back();
                }
    
                reverse(temp.begin(), temp.end());
    
                res.pop_back();
    
                string num = "";
                while (!res.empty() && res.back() >= '0' && res.back() <= '9') {
                    num.push_back(res.back());
                    res.pop_back();
                }
                reverse(num.begin(), num.end());
                int p = stoi(num);
    
                while (p--) {
                    res.append(temp);
                }
            }
        }
    
        return res;
    }
};