#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D matrix, return the elements of the matrix in diagonal order. The diagonal order starts from the top-left corner of the matrix and proceeds to the bottom-right corner, traversing the diagonals of the matrix.
Approach: We can iterate through the diagonals of the matrix. The number of diagonals

Steps:
1. The total number of diagonals in an n x m matrix is n + m - 1.
2. For each diagonal, we can determine the starting point (row and column) based on the diagonal index.
   - If the diagonal index d is less than m, the starting point is (0, d).
   - If the diagonal index d is greater than or equal to m, the starting point is (d - m + 1, m - 1).
3. We can then traverse the diagonal by incrementing the row and decrementing the column until we go out of bounds.
4. We can store the elements of the diagonal in a result vector and return it at the end.

Time Complexity: O(n*m) - We need to traverse all elements of the matrix once.
Space Complexity: O(n*m) - We are storing all elements of the matrix in the result vector.
*/

class Solution {
  public:
    vector<int> diagView(vector<vector<int>>  arr) {
    
        int  n = arr.size() , m = arr[0].size();
         vector<int> ans;
         for(int d = 0; d < n + m - 1; d++){
            
            int row = (d < m) ? 0 : d - m + 1;
            int col = (d < m) ? d : m - 1;

            while(row < n && col >= 0){
                ans.push_back(arr[row][col]);
                row++;
                col--;
            }
        }

        return ans;
        
    }
};