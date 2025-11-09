#include <bits/stdc++.h>
using namespace std;

// Problem: Given a floor of size 4 x n, find the number of ways to tile the floor using tiles of size 1 x 4 and 4 x 1.
// Approach: Use recursion to explore all possible placements of tiles and count the valid configurations.

// Steps:
// 1. Define a recursive function that takes the length of the floor (n) as input.
// 2. Base Cases:
//   - If n == 0, return 1 (one way to tile a floor of length 0).
//   - If n == 1, return 1 (only one way to place a vertical tile).
//   - If n < 0, return 0 (invalid configuration).
// 3. Recursive Cases:
//  - Place a vertical tile (1 x 4) and reduce the problem to n - 1.
//  - Place a horizontal tile (4 x 1) and reduce the problem to n - 4.
// 4. Sum the results of the recursive calls to get the total number of ways to tile the floor.
// 5. Return the total count.

// Time Complexity: O(2^n) in the worst case due to the recursive calls.
// Space Complexity: O(n) due to the recursion stack.

class Solution {
  public:
    int numberOfWays(int n) {
        if(n == 0 || n == 1)return 1;
        if(n < 0)return 0;
        int ans = 2 * numberOfWays(n - 2) + numberOfWays(n - 3);
        return ans;
    }
};