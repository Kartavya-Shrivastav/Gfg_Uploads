#include <bits/stdc++.h>
using namespace std;

// Problem: Given a square matrix `mat`, swap its primary and secondary diagonals.
// Approach: In-Place Swapping

// Steps:
// 1. Initialize two pointers, one for the primary diagonal and one for the secondary diagonal.
// 2. Iterate through the matrix, swapping the elements at these pointers.
// 3. Return the modified matrix.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
    virtual void swapDiagonal(vector<vector<int>> &mat) {
      int i=0, j=0, n=mat.size();
      while(i<n && j<n){
          int t = mat[i][j];
          mat[i][j] = mat[i][n-1-j];
          mat[i][n-1-j] = t;
      
          i++, j++;
      }
      
      return;    
    }
};