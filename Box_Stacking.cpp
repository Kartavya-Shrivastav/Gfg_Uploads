#include <bits/stdc++.h>
using namespace std;

// Problem: Box Stacking
// Approach: Dynamic Programming

// Steps:
// 1. Generate all permutations of the dimensions of each box.
// 2. Sort the boxes based on their base area (width * length).
// 3. Use dynamic programming to find the maximum height of the stackable boxes.
// 4. For each box, check all previous boxes to see if it can be placed on top of them.
// 5. Return the maximum height found.

// Time Complexity: O(n^2 * log(n)), where n is the number of boxes.
// Space Complexity: O(n), for storing the boxes and the dp array.


class Solution {
    public:
        int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
                // Number of original boxes
                int n = height.size();
                // To store all possible orientations of all boxes
                vector<vector<int>> arr;
                
                // Generate all permutations (orientations) for each box
                for (int i = 0; i < n; ++i){
                        vector<int> per = {height[i], width[i], length[i]};
                        sort(per.begin(), per.end());
                        // Generate all 6 permutations for the box
                        do {
                                arr.push_back(per);
                        } while (next_permutation(per.begin(), per.end()));
                }
                
                // Sort boxes by base area (width * length) in descending order
                sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {
                    return a[0] * a[1] > b[0] * b[1]; 
                });
                
                n = arr.size();
                // dp[i] will store the maximum stack height ending with box i
                vector<int> dp(n);
                
                // Compute optimized dp values in bottom up manner
                for (int i = 0; i < n; ++i){
                        dp[i] = arr[i][2]; // Height of the current box
                        for (int j = 0; j < i; ++j){
                                // If box i can be placed on box j
                                if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) {
                                        dp[i] = max(dp[i], dp[j] + arr[i][2]);
                                }
                        }
                }
                
                // Return the maximum value from dp array
                return *max_element(dp.begin(), dp.end());
        }
};