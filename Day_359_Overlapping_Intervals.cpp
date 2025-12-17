#include <bits/stdc++.h>
using namespace std;

// Problem: Given a collection of intervals, merge all overlapping intervals.
// Approach: Sort the intervals based on the starting times. Iterate through the sorted intervals and merge them if they overlap.

// Steps:
// 1. Sort the intervals based on their starting times.
// 2. Initialize a result vector to store merged intervals.
// 3. Iterate through the sorted intervals:
//    - If the current interval overlaps with the last interval in the result, merge them by updating the end time.
//    - If they do not overlap, add the current interval to the result.
// 4. Return the result vector containing merged intervals.

// Complexity Analysis:
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) for the result vector

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        int start = arr[0][0],end = arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(end>=arr[i][0]){
                end = max(end,arr[i][1]);
                continue;
            }
            res.push_back({start,end});
            start = arr[i][0];
            end = arr[i][1];
        }
        res.push_back({start,end});
        return res;
    }
};