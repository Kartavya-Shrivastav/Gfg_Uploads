#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Valid Parentheses
// Given n pairs of parentheses, write a function to count the number of valid combinations of parentheses.
// Approach: Use a recursive helper function to explore all combinations of parentheses while keeping track of the number of left and right parentheses used.

// Steps:
// 1. If the current position equals n, check if the number of left parentheses is greater than the number of right parentheses. If so, return 1 (valid combination), else return 0.
// 2. If the number of left parentheses used exceeds n/2, return 0 (invalid).
// 3. If the number of right parentheses used exceeds the number of left parentheses, return 0 (invalid).
// 4. Recursively call the helper function by adding a left parenthesis and a right parenthesis, summing the results.
// 5. Return the total count of valid combinations.

// Time Complexity: O(2^N) in the worst case, as we explore all combinations.
// Space Complexity: O(N) due to the recursion stack.

class Solution {
  public:
    int findWays(int n) {
        if(n%2 ==1) return 0;
        return helper(0, 0,0,n);
        
    }
    int helper(int pos , int l , int r , int n ){
        if(n==pos){
            if(l > r) return 1;
            else return 0;
        }
        if(l>n/2) return 0;
        if(r>l) return 0;
        return helper(pos+1, l+1,r,n) + helper(pos+1, l,r+1,n);
    }
};