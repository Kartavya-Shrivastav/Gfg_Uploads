#include <bits/stdc++.h>
using namespace std;

// Problem: Count elements in given range [a, b] for multiple queries
// Approach: Sorting and Binary Search

// Steps:
// 1. Sort the input array to enable binary search.
// 2. For each query [a, b]:
//   a. Use lower_bound to find the first position where 'a' can be inserted.
//   b. Use upper_bound to find the first position where 'b' can be inserted.
//   c. The difference between the two positions gives the count of elements in the range [a, b].
// 3. Store the counts for each query and return the result.

// Time Complexity: O(N log N + Q log N) where N is the size of the array and Q is the number of queries
// Space Complexity: O(1) additional space (excluding the output array)

class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        vector <int> res;
        sort(arr.begin(), arr.end());
        
        for(auto query : queries){
            int a = query[0];
            int b = query[1];
            
            auto low = lower_bound(arr.begin(), arr.end(), a);
            auto high = upper_bound(arr.begin(), arr.end(), b);
            int cnt = high - low;
            res.push_back(cnt);
        }
        
        return res;
    }
};