#include <bits/stdc++.h>
using namespace std;

// Problem: Given an integer n, find the number of ways to write n as a sum of consecutive positive integers.
// Approach: Use a mathematical formula to count the number of ways to express n as a sum of consecutive integers.

// Steps:
// 1. If n is less than 2, return 0 as there are no valid sums.
// 2. Initialize two variables to keep track of the previous and current Fibonacci-like numbers.
// 3. Use a loop to calculate the number of ways to express n as a sum of consecutive integers.
// 4. Return the total count of ways.

// Time Complexity: O(n), where n is the input integer.
// Space Complexity: O(1), as we are using a constant amount of space.

class Solution {
  public:
    int countConsec(int n) {
        if(n == 2) return 1;
      
        int prev = 0, curr = 1, nex, ans = 1;
        for(int i = 3 ; i<=n ; i++){
          nex = prev+curr;
          ans =  ans * 2 + nex ; 
          prev = curr;
          curr = nex;
          
        }
        return ans ;
    }
};
