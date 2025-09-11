#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array where each element represents the maximum jump length at that position, find the minimum number of jumps to reach the last index.
// Approach: Use a greedy approach to keep track of the farthest reachable index and the number of jumps made.

// Steps:
// 1. Initialize variables to track the maximum reachable index, the number of steps we can still take, and the number of jumps made.
// 2. Iterate through the array, updating the maximum reachable index and decrementing the steps.
// 3. When steps reach zero, increment the jump count and update steps to the number of steps to reach the new maximum reachable index.
// 4. If at any point the current index exceeds the maximum reachable index, return -1 as it's not possible to reach the end.
// 5. If we reach the last index, return the number of jumps made.

// Time Complexity: O(N) where N is the length of the array
// Space Complexity: O(1) as we are using a constant amount of space


class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
         int n = arr.size();
        if (n <= 1) return 0;          // Already at last index
        if (arr[0] == 0) return -1;    // Can't move anywhere

        int maxReach = arr[0];  // Farthest index reachable
        int steps = arr[0];     // Steps left in current jump
        int jumps = 1;          // We make the first jump from index 0

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached last index

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {  // Need to make another jump
                jumps++;
                if (i >= maxReach) return -1;  // Can't move further
                steps = maxReach - i;
            }
        }
        return -1; // If end is never reached
    }
};