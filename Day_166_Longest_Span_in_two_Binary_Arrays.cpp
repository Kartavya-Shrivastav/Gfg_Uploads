#include <bits/stdc++.h>
using namespace std;

// This code defines a Solution class with a method to find the longest span with equal sum in two binary arrays.

class Solution {
    public:
        // Function to find the longest span with equal sum in two binary arrays
        int longestCommonSum(vector<int> &a1, vector<int> &a2) {
                int n = a1.size();
                unordered_map<int, int> mpp; // Map to store the first occurrence of a particular sum difference
                int sum = 0; // This will store the running sum of differences
                int maxi = 0; // To keep track of the maximum length found
                
                mpp[0] = -1; // Initialize with sum 0 at index -1 to handle the case when the span starts from index 0
                
                for (int i = 0; i < n; i++) {
                        sum += (a1[i] - a2[i]); // Update the running sum of differences
                        if (mpp.find(sum) != mpp.end()) {
                                // If this sum has been seen before, update the maximum length
                                maxi = max(maxi, i - mpp[sum]);
                        } else {
                                // Otherwise, store the index of the first occurrence of this sum
                                mpp[sum] = i;
                        }
                }
                
                return maxi; // Return the maximum length found
        }
};