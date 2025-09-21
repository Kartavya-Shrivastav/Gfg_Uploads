#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary matrix, find the maximum area of a rectangle formed only of 1's.
// Approach: Use a stack-based approach to calculate the maximum area of histograms for each row of the matrix, treating each row as the base of a histogram where the height of each bar is the number of consecutive 1's above it.

// Steps:
// 1. Define a helper function `getMaxArea` that takes a vector of integers (representing heights of histogram bars) and returns the maximum rectangular area that can be formed.
// 2. In the `maxArea` function, iterate through each row of the matrix.
// 3. For each row, update the heights of the histogram bars based on the number of consecutive 1's in that column up to the current row.
// 4. Call the `getMaxArea` function for the updated histogram heights and keep track of the maximum area found.
// 5. Return the maximum area found after processing all rows.

// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix, as we process each element once.
// Space Complexity: O(m) for the stack used in the `getMaxArea` function.

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i<=n;i++){
            while(!st.empty() and (i==n or arr[i]<arr[st.top()])){
                int idx = st.top();
                st.pop();
            
                int l_idx  = (!st.empty()) ? st.top():-1;
                int r_idx = i;
                
                ans = max(ans, arr[idx]*(r_idx-l_idx-1));
            }
            st.push(i);
        }
        
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i-1>=0 and mat[i][j] == 1){
                    mat[i][j] += mat[i-1][j];
                }
            }
            ans = max(ans, getMaxArea(mat[i]));
        }
        
        return ans;
    }
};