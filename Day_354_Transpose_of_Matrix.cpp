#include <bits/stdc++.h>
using namespace std;

// Problem: Given a square matrix `mat`, return its transpose.
// Approach: In-Place Swapping

// Steps:
// 1. Iterate through the upper triangle of the matrix (excluding the diagonal).
// 2. For each element in the upper triangle, swap it with its corresponding element in the lower triangle.
// 3. Return the transposed matrix.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
  public:
    vector<vector<int> > transpose(vector<vector<int> >& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        return mat;
    }
};