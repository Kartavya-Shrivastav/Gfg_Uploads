#include <bits/stdc++.h>
using namespace std;    

// Problem: Given a number n, find the minimum number of perfect square numbers (like 1, 4, 9, 16, ...) which sum to n.
// Approach: Use recursion with memoization to explore the combinations of perfect squares that sum to n, limiting the number of squares used to 4 as per Lagrange's Four Square Theorem.

// Steps:
// 1. Define a recursive function that takes the remaining number n, the current square number being considered, and the maximum number of squares allowed.  
// 2. In the recursive function, check base cases: if n is 0, return 0; if the current square number is 1 or max squares is 0, return n (as all remaining n will be made up of 1s).
// 3. Calculate the minimum squares needed by either taking the current square number (if it fits into n) or not taking it and moving to the next smaller square number.
// 4. Return the minimum of the two choices.

// Time Complexity: O(n * sqrt(n)) in the worst case due to the recursive calls and choices made.
// Space Complexity: O(n) for the recursion stack.

class Solution {
  public:
    int solve(int n, int i, int maxThershold){
        if(n==0 || i==1 || maxThershold==0) return n;
        
        int take = 1e4, not_take = 1e4;
        
        //take current i
        if(n>=i*i)
            take = solve(n-i*i, i, maxThershold-1) + 1;
        
        //not_take
        not_take = solve(n, i-1, maxThershold);
        
        return min(take, not_take);
    }
    
    int minSquares(int n) {
        // Code here
        return solve(n, pow(n, 0.5), 4);
    }
};