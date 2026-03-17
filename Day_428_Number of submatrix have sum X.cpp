#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D matrix of integers and an integer x, count the number of square submatrices that have a sum equal to x.
Approach: We can use a prefix sum approach to efficiently calculate the sum of any square submatrix. We will create a prefix sum matrix where each entry at (i, j) contains the sum of the elements from the top-left corner (0, 0) to (i, j). Then, we can iterate through all possible square submatrices and use the prefix sum matrix to calculate their sums in constant time.

Steps:
1. Create a prefix sum matrix `pre` of size (n+1) x (m+1) initialized to 0, where n and m are the dimensions of the input matrix.
2. Fill the prefix sum matrix using the formula: `pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j]`.
3. Define a helper function `getSum(r1, c1, r2, c2)` that returns the sum of the submatrix defined by the corners (r1, c1) and (r2, c2) using the prefix sum matrix.
4. Iterate through all possible top-left corners (i, j) of the square submat rices and for each corner, iterate through possible sizes of the square (k) while ensuring that the bottom-right corner (i+k, j+k) is within bounds.
5. For each square submatrix defined by (i, j) and (i+k, j+k), use the `getSum` function to calculate its sum and compare it with x. If it matches, increment the count.

Time Complexity: O(n^3) in the worst case, where n is the dimension of the matrix, due to the three nested loops. However, the prefix sum allows us to calculate the sum of each submatrix in O(1) time.
Space Complexity: O(n*m) for the prefix sum matrix.
*/

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int count = 0;
        
        vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];
            }
        }
        
        auto getSum = [&](int r1, int c1, int r2, int c2) -> long long {
            return pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; i + k < n && j + k < m; k++) {
                    if (getSum(i, j, i + k, j + k) == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};