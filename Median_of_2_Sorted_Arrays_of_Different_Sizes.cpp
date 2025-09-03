#include <bits/stdc++.h>
using namespace std;

// Problem: Find the median of two sorted arrays of different sizes
// Approach: Merge the two arrays and find the median

// Steps:
// 1. Merge the two arrays into a single sorted array.
// 2. Find the median of the merged array.
// 3. Return the median.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        vector<int> v;
        for(auto it:a){
            v.push_back(it);
        }
        for(auto it:b){
            v.push_back(it);
        }
        sort(v.begin(),v.end());

        int n = v.size();
        return n%2!=0?v[(n)/2]:(v[n/2]+v[(n/2)-1])/2.0;
    }
};