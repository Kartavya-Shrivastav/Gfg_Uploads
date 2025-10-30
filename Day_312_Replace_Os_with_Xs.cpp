#include <bits/stdc++.h>
using namespace std;

// Problem: Given a 2D grid consisting of 'X' and 'O', replace all 'O's that are not connected to the border with 'X's. An 'O' is considered connected to the border if it is on the border itself or connected to another 'O' that is connected to the border.
// Approach: Use BFS to mark all 'O's connected to the border. Then, replace all unmarked 'O's with 'X's and revert the marked ones back to 'O's.

// Steps:
// 1. Traverse the border of the grid and for each 'O' found, perform a BFS to mark all connected 'O's.
// 2. After marking, traverse the entire grid and replace unmarked 'O's with 'X's.
// 3. Finally, revert the marked 'O's back to 'O's.

// Time Complexity: O(N*M) where N is the number of rows and M is the number of columns in the grid.
// Space Complexity: O(N*M) in the worst case for the queue used in BFS.

class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            if(grid[i][0]=='O'){
                grid[i][0]='C';
                q.push({i, 0});
            }
            if(grid[i][m-1]=='O'){
                grid[i][m-1]='C';
                q.push({i, m-1});
            }
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j]=='O'){
                grid[0][j]='C';
                q.push({0, j});
            }
            if(grid[n-1][j]=='O'){
                grid[n-1][j]='C';
                q.push({n-1, j});
            }
        }
        
        int dr[4]={0, 1, 0, -1};
        int dc[4]={1, 0, -1, 0};
        
        while(!q.empty()){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='O'){
                    grid[nr][nc]='C';
                    q.push({nr, nc});
                }
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]=='O') grid[i][j]='X';
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='C'){
                    grid[i][j]='O';
                }
            }
        }
    }
};