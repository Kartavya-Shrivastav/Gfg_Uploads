#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a matrix, determine if it is a Toeplitz matrix. A Toeplitz matrix is a matrix where every diagonal from top-left to bottom-right has the same elements.
Approach: We can iterate through the matrix starting from the second row and second column, and compare each element with the element that is diagonally up-left (i.e., mat[i-1][j-1]). If we find any element that does not match, we can immediately return false. If we finish iterating through the matrix without finding any mismatches, we can return true.

Steps:
1. Get the number of rows (m) and columns (n) in the matrix.    
2. Iterate through the matrix starting from the second row (i=1) and second column (j=1):
    a. For each element mat[i][j], compare it with mat[i-1][j-1].
    b. If they are not equal, return false.
3. If we finish iterating through the matrix without finding any mismatches, return true.

Time Complexity: O(m*n) - We need to check each element in the matrix once, so the time complexity is linear with respect to the number of elements in the matrix.
Space Complexity: O(1) - We use only a constant amount of extra space for the loop variables and comparisons.
*/

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]!=mat[i-1][j-1])return false;
            }
        }
        return true;
    }
};