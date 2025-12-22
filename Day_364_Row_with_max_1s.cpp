#include<bits/stdc++.h>
using namespace std;

// Problem: Find the row with the maximum number of 1s in a binary matrix
// Approach: Optimized Search from Top-Right Corner

// Steps:
// 1. Start from the top-right corner of the matrix.
// 2. Initialize row index to 0 and column index to the last column.
// 3. While the row index is within bounds and the column index is non-negative:
//    a. If the current element is 1, move left (decrement column index) and update the answer to the current row.
//    b. If the current element is 0, move down (increment row index).
// 4. Return the row index with the maximum number of 1s found, or -1 if no 1s are present.

// Time Complexity: O(N + M) where N is the number of rows and M is the number of columns
// Space Complexity: O(1) the number of columns

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0;
        int ans = -1;   // better default
        int idx = m - 1;

        while (row < n && idx >= 0) {
            if (arr[row][idx] == 1) {
                ans = row;
                idx--;
            } else {
                row++;
            }
        }
        return ans;
    }
};