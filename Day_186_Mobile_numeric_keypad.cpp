#include <bits/stdc++.h>
using namespace std;

// Problem: Mobile Numeric Keypad
// Approach: Use dynamic programming to count the number of valid sequences of key presses.

// Steps:
// 1. Define the adjacency list for each key on the keypad.
// 2. Initialize a vector to keep track of the number of ways to reach each key.
// 3. For each digit from 1 to n, update the number of ways to reach each key based on the previous counts.
// 4. Return the total count of valid sequences after processing all digits.

// Time Complexity: O(n * 10), where n is the number of digits and 10 is the number of keys.
// Space Complexity: O(10), for storing the counts of each key.

class Solution {
  public:
    int getCount(int n) {
        vector<vector<int>> adj={{0,8}, {1,2,4}, {1,2,3,5}, {2,3,6}, {1,4,5,7},
                        {2,4,5,6,8}, {3,5,6,9}, {4,7,8}, {5,7,8,9,0}, {6,8,9}};
        // Initialize two vectors to store the number of ways to reach each key.
        // v: stores the ways for the previous step, dp: stores the ways for the current step.
        vector<int> v(10,1), dp(10,1);

        // Iterate for each digit position from 2 to n
        for(int i=1;i<n;i++){
            // For each key (0-9)
            for(int j=0;j<10;j++){
            dp[j]=0; // Reset current count for key j
            // For each adjacent key k to key j
            for(auto k:adj[j]){
                dp[j] += v[k]; // Add the ways to reach key k in the previous step
            }
            }
            v = dp; // Update v for the next iteration
        }

        // Sum all possible ways for the last digit position
        return accumulate(dp.begin(), dp.end(), 0);
    }
};