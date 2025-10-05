#include <bits/stdc++.h>
using namespace std;

// Problem: Expression Add Operators
// Approach: We can use backtracking to generate all possible expressions by inserting '+', '-', and '*' between the digits of the input string. We need to evaluate each expression to check if it equals the target value.

// Steps:
// 1. Define a recursive function that builds expressions by adding operators between digits.
// 2. When we reach the end of the string, evaluate the expression and check if it equals the target value. If it does, add it to the result list.
// 3. Use backtracking to explore all combinations of operators, ensuring to handle operator precedence correctly (especially for multiplication).
// 4. Finally, return the list of valid expressions.

// Time Complexity: O(4^n) in the worst case (for exploring all combinations of operators between n digits)
// Space Complexity: O(n) for the recursion stack and O(m) for storing the results

class Solution {
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> ans;
        solve(0, s, target, "", ans, 0, 0);
        return ans;
    }
    
private:
    void solve(int index, string &num, int target, string curr, vector<string>& ans, long prev, long res) {
        if(index == num.length()) {
            if(res == target) {
                ans.push_back(curr);
            }
            return;
        }
        
        string st = "";
        long currRes = 0;
        
        for(int i = index; i < num.length(); i++) {
            if(i > index && num[index] == '0') break;
            
            st += num[i];
            currRes = currRes * 10 + (num[i] - '0');
            
            if(index == 0) {
                solve(i + 1, num, target, st, ans, currRes, currRes);
            } else {
                solve(i + 1, num, target, curr + "+" + st, ans, currRes, res + currRes);
                solve(i + 1, num, target, curr + "-" + st, ans, -currRes, res - currRes);
                solve(i + 1, num, target, curr + "*" + st, ans, prev * currRes, res - prev + (prev * currRes));
            }
        }
    }
};