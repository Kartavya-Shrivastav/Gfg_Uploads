#include <bits/stdc++.h>
using namespace std;

// Problem: Set matrix zeroes if any element in the matrix is zero.
// Approach: Create a copy of the original matrix and iterate through it to find zeroes.

// Steps:
// 1. Create a copy of the original matrix to preserve the initial values.
// 2. Iterate through each element of the matrix.
// 3. If an element is zero, set the entire row and column of that element to zero in the original matrix.
// 4. Return the modified matrix.

// Time Complexity: O(n * m) where n is the number of rows and m is the number of columns.
// Space Complexity: O(n * m) for the copy of the matrix.

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
          int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>original=mat;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(original[row][col]==0){
                    for(int i=0;i<m;i++){
                        mat[row][i]=0;
                    }
                    for(int j=0;j<n;j++){
                        mat[j][col]=0;
                    }
                }
            }
        }
    }
};