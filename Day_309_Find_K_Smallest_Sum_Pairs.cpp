#include <bits/stdc++.h>
using namespace std;

// Problem: Given two sorted arrays, find the k pairs with the smallest sums.
// Approach: Use a min-heap (priority queue) to efficiently retrieve the pairs with the smallest sums.

// Steps:
// 1. Initialize a min-heap to store pairs along with their sums.
// 2. Iterate through the first min(k, n) elements of the first array and the first min(k, m) elements of the second array.
// 3. For each combination, calculate the sum and push it into the min-heap.
// 4. Extract the top k elements from the min-heap to get the pairs with the smallest sums.
// 5. Return the list of k pairs.

// Time Complexity: O(min(k, n) * min(k, m) + k log k) due to heap operations.
// Space Complexity: O(min(k, n) * min(k, m)) for storing elements in the min-heap.

class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int n=arr1.size();
        int m=arr2.size();
        
        for(int i=0; i<min(k, n); i++){
            for(int j=0; j<min(m, k); j++){
                pq.push({arr1[i]+arr2[j], {arr1[i], arr2[j]}});
            }
        }
        
        vector<vector<int>>ans;
        
        while(!pq.empty() && ans.size()<k){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};
