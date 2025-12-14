#include <bits/stdc++.h>
using namespace std;

// Problem: Given a 2D matrix `mat` and a list of queries where each query consists of four integers representing the top-left and bottom-right corners of a submatrix, return the sum of elements within each submatrix.
// Approach: Prefix Sum 2D Array

// Steps:
// 1. Preprocess the matrix to create a prefix sum matrix where each element at (i, j) contains the sum of all elements from (0, 0) to (i, j).
// 2. For each query, use the prefix sum matrix to calculate the sum of the specified submatrix in constant time.
// 3. Return the list of sums for each query.

// Time Complexity: O(n*m + q)
// Space Complexity: O(1) (if we modify the input matrix for prefix sums)

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        int q = queries.size();
        
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        
        vector<int> sums(q);
        for(int i = 0;i<q;i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            
            sums[i] = mat[r2][c2];
            
            if(r1-1>=0){
                sums[i]-=mat[r1-1][c2];
            }
            if(c1-1>=0){
                sums[i]-=mat[r2][c1-1];
            }
            
            // intersection matrix
            if(r1-1>=0 and c1-1>=0){
                sums[i]+=mat[r1-1][c1-1];
            }
        }
        
        return sums;
    }
};