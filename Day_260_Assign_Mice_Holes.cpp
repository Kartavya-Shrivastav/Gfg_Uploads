#include <bits/stdc++.h>
using namespace std;

// Problem: Assign Mice to Holes such that the maximum distance any mouse has to travel is minimized
// Approach: Sort both mice and holes positions, then pair them in sorted order

// Steps:
// 1. Sort the positions of mice and holes.
// 2. Calculate the absolute distance for each pair of mouse and hole.
// 3. Track the maximum distance encountered.
// 4. Return the maximum distance as the result.

// Time Complexity: O(N log N) due to sorting
// Space Complexity: O(1) if sorting in place, otherwise O(N) for storing sorted arrays

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int n = mices.size();
        
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }
        
        return maxTime;
    }
};