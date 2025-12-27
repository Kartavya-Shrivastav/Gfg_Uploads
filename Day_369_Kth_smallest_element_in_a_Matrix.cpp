#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Smallest Element in a Sorted Matrix
// Approach: Min-Heap (Priority Queue)

// Steps:
// 1. Use a min-heap to keep track of the smallest elements from each row.
// 2. Extract the smallest element from the heap k times.
// 3. Each time an element is extracted, push the next element from the same row into the heap.
// 4. The kth extracted element is the answer.

// Time Complexity: O(k log m) where m is the number of rows
// Space Complexity: O(m) for the heap

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> indexes(m, 0);
    for (int i = 0; i < m; i++) {
        pq.push({mat[i][0], i});
    }
    int ans = 0;
    while (k--) {
        auto top = pq.top();
        pq.pop();
        ans = top.first;
        int row = top.second;
        indexes[row]++;
        if (indexes[row] < n) {
            pq.push({mat[row][indexes[row]], row});
        }
    }
    return ans;
}
};