#include <bits/stdc++.h>
using namespace std;

// Problem: Generate Parentheses
// Approach: Backtracking

// Steps:
// 1. Use backtracking to generate all combinations of parentheses.
// 2. Maintain counts of opening and closing parentheses.
// 3. Ensure that the number of opening parentheses does not exceed n/2.
// 4. Ensure that the number of closing parentheses does not exceed the number of opening parentheses.
// 5. When the total number of parentheses reaches n, add the combination to the result.

// Time Complexity: O(2^n) where n is the number of pairs of parentheses
// Space Complexity: O(n) for the recursion stack and temporary storage

class Solution {
  public:
    void f(vector<string> &ans, string s, int n, int o, int c) {
        if(o + c == n) {
            ans.push_back(s);
            return;
        }
        // go for opening iff it can occur at most n / 2 times
        if(o + 1 <= n / 2) f(ans, s + '(', n, o + 1, c);
        
        // go for closing iff it can occur <= opening cnt
        if(c + 1 <= o) f(ans, s + ')', n, o, c + 1);
    }
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        f(ans, "", n, 0, 0);
        return ans;
    }
};