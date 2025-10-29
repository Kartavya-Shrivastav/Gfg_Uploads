#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary grid, find the distance of the nearest cell having 1 for each cell.
// Approach: Use multi-source BFS starting from all cells containing 1. Update distances for neighboring cells.

// Steps:
// 1. Initialize a queue and enqueue all cells containing 1, marking them as visited.
// 2. While the queue is not empty:
//    - Dequeue a cell and get its distance.
//    - For each of its 4 neighboring cells, if they are within bounds and not visited:
//      - Mark them as visited.
//      - Update their distance as current distance + 1.
//      - Enqueue the neighboring cell with the updated distance.
// 3. Return the distance matrix after processing all cells.

// Time Complexity: O(m*n) where m and n are the dimensions of the grid, as each cell is processed at most once.
// Space Complexity: O(m*n) for the distance and visited matrices, and the queue in the worst case.

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[x][y] = steps;
            vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = steps + 1;
                    q.push({{nx,ny}, steps+1});
                }
            }
        }
        return dist;
    }
};