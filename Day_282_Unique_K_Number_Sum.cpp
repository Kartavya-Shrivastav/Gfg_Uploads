#include <bits/stdc++.h>
using namespace std;

// Problem: Unique K Number Sum
// Approach: We can use backtracking to find all unique combinations of K numbers that sum up to N.

// Steps:
// 1. Define a recursive function that builds combinations by adding numbers from 1 to 9.
// 2. When a combination is formed (i.e., when the size of the current combination reaches K and the sum reaches N), add it to the result list.
// 3. Use backtracking to explore all combinations of numbers, ensuring that each number is only used once in each combination.
// 4. Finally, return the list of unique combinations.

// Time Complexity: O(2^9) in the worst case (for exploring all combinations of numbers from 1 to 9)
// Space Complexity: O(k) for the recursion stack and O(m) for storing the results

class Solution {
  public:
    void get(vector<vector<int>> & ans, vector<int> a, int n, int k, int j){
        if (k == a.size() && n == 0) {
            ans.push_back(a);
            return;
        }
        else {
            for (int i = j; i <= 9; i++) {
                a.push_back(i);
                get(ans, a, n-i, k, i+1);
                a.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        get(ans, {}, n, k, 1);
        return ans;
    }
};