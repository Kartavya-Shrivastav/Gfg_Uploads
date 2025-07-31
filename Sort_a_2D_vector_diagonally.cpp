#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Sort a 2D vector diagonally
// Approach: Use a priority queue to sort the elements along each diagonal

// Steps:
// 1. Iterate through the matrix starting from the first row and each column.
// 2. For each diagonal, collect the elements into a priority queue.
// 3. Pop the elements from the priority queue and place them back into the matrix in sorted order.
// 4. Repeat the process for diagonals starting from the first column.
// 5. Ensure that the sorting is done in ascending order for the first set of diagonals and descending for the second set.
// 6. This ensures that all diagonals are sorted correctly in the 2D vector.

// Time Complexity: O(n * m log(min(n, m))), where n is the number of rows and m is the number of columns, due to the priority queue operations.
// Space Complexity: O(min(n, m)), for storing the elements of the diagonal in the priority queue.

class Solution {
  public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        for(int i=1;i<n;i++){
            
            int row=i,col=0;
            priority_queue<int, vector<int>, greater<int> >p;
            
            while(row<n && col<m){
                p.push(matrix[row++][col++]);
            }
            row=i;
            col=0;
             while(row<n && col<m){
                matrix[row++][col++]=p.top();
                p.pop();
            }
        }
        
         for(int i=1;i<m;i++){
            
            int row=0,col=i;

             priority_queue<int> pq;
            while(row<n && col<m){
                pq.push(matrix[row++][col++]);
            }
            row=0;
            col=i;
             while(row<n && col<m){
                matrix[row++][col++]=pq.top();
                pq.pop();
            }
        }
    }
};