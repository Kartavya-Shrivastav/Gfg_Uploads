#include <bits/stdc++.h>
using namespace std;

// Problem: Make a matrix beautiful by equalizing the row and column sums.
// Approach: Calculate the maximum row and column sums, then determine the operations needed to equalize them.

// Steps:
// 1. Calculate the sum of each row and each column.
// 2. Find the maximum row sum and maximum column sum.
// 3. Calculate the total sum of the matrix.
// 4. Determine the operations needed to make all row sums equal to the maximum row sum or all column sums equal to the maximum column sum.
// 5. Return the minimum operations required to balance the matrix.

// Time Complexity: O(n^2) where n is the number of rows/columns in the matrix.
// Space Complexity: O(1) as we are using a constant amount of extra space.

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n=mat.size();
        int rowMax=0, colMax=0, sum=0;
        
        for(int i=0; i<n; i++){
            int rowSum=0, colSum=0;
            for(int j=0; j<n; j++){
                sum+=mat[i][j];
                rowSum+=mat[i][j];
                colSum+=mat[j][i];
            }
            rowMax=max(rowMax, rowSum);
            colMax=max(colMax, colSum);
        }
        
        return (rowMax>=colMax)?((n*rowMax)-(sum)):((n*colMax)-(sum));
    
    }
};