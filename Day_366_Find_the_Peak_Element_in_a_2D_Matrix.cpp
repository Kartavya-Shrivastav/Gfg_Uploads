#include <bits/stdc++.h>
using namespace std;

// Problem: Find a peak element in a 2D matrix
// Approach: Brute Force Search

// Steps:
// 1. Iterate through each element in the matrix.
// 2. For each element, check its four possible neighbors (up, down, left, right).
// 3. If the current element is greater than or equal to all its valid neighbors, it is a peak element.
// 4. Return the coordinates of the first peak element found.

// Time Complexity: O(N * M) where N is the number of rows and M is the number of columns in the matrix
// Space Complexity: O(1) additional space (excluding the output array)

class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, -1, 0, 1};
        
        vector<int>ans;
        
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                bool peak=1;
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        if(mat[r][c]<mat[nr][nc]){
                            peak=0;
                            break;
                        }
                    }
                }
                if(peak){
                    ans.push_back(r);
                    ans.push_back(c);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
