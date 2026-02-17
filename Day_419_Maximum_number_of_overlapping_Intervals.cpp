#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of intervals where intervals[i] = [starti, endi], return the maximum number of overlapping intervals at any time.
// Approach: We can use a difference array to keep track of the number of intervals that start and end at each time point. We will iterate through the intervals and for each interval, we will increment the count at the start time and decrement the count at the end time + 1. After processing all intervals, we will compute the prefix sum of the difference array to get the number of overlapping intervals at each time point. Finally, we will find the maximum value in the prefix sum array, which will give us the maximum number of overlapping intervals.

// Steps:
// 1. Find the maximum end time from the intervals to determine the size of the difference array.
// 2. Create a difference array of size max end time + 2, initialized to 0.
// 3. Iterate through the intervals and for each interval [start, end], increment the count at the start index and decrement the count at the end index + 1 in the difference array.
// 4. Compute the prefix sum of the difference array to get the number of overlapping intervals at each time point.
// 5. Find the maximum value in the prefix sum array, which will be the answer.

// Time Complexity: O(n + m) where n is the number of intervals and m is the maximum end time. The iteration through the intervals takes O(n) and computing the prefix sum takes O(m).
// Space Complexity: O(m) where m is the maximum end time, due to the difference array.

class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int maxVal = 0;
        
        for (auto &it : arr) maxVal = max(maxVal, it[1]);
        
        vector<int> diff(maxVal+2, 0);
        
        for (auto &it : arr){
            diff[it[0]]++;
            diff[it[1]+1]--;
        }
        
        int ans = 0;
        
        for (int i = 1; i <= maxVal; i++) diff[i] += diff[i-1];

        for (int i = 0; i <= maxVal; i++) ans = max(ans, diff[i]);
        
        return ans;
    }
};