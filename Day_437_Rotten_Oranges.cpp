#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid, each cell can have one of three values: 0 representing an empty cell, 1 representing a fresh orange, and 2 representing a rotten orange. Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Approach: We can use a breadth-first search (BFS) approach to solve this problem. We will start by enqueueing all the rotten oranges along with their initial time (0 minutes). Then, we will process each rotten orange and enqueue any adjacent fresh oranges that become rotten, incrementing the time for each newly rotten orange. We will also keep track of the count of fresh oranges and decrement it whenever a fresh orange becomes rotten. Finally, if there are still fresh oranges left after processing all rotten oranges, we will return -1; otherwise, we will return the maximum time taken to rot all oranges.

Steps:
1. Initialize a queue to store the rotten oranges and their corresponding time.
2. Initialize a visited matrix to keep track of which cells have been processed.
3. Count the number of fresh oranges and enqueue all the rotten oranges with time 0.
4. Define the possible directions for adjacent cells (up, right, down, left).
5. While the queue is not empty, process each rotten orange:
   a. Dequeue the front element to get the current orange's position and time.
   b. For each adjacent cell, check if it is within bounds, not visited, and is a fresh orange.
   c. If it is a fresh orange, enqueue it with time incremented by 1, mark it as visited, and decrement the fresh orange count.
6. After processing all rotten oranges, check if there are any fresh oranges left. If yes, return -1; otherwise, return the maximum time taken to rot all oranges.

Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the grid, since we may need to process each cell at most once.
Space Complexity: O(n*m) for the visited matrix and the queue in the worst case when all oranges are rotten.
*/

class Solution {
  public:
    int orangesRot(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair< pair<int,int>, int> > q;
        vector<vector<int>> vis(n, vector<int>(m));
        int freshCount=0;
        
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c] == 2){
                    q.push({ {r,c}, 0 });
                    vis[r][c] = 1;
                }
                else if(grid[r][c] == 1) freshCount++;
            }
        }

        vector<pair<int,int>> adjNodes = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int time=0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int t = node.second;
            time = max(time, t);

            for(auto p: adjNodes){
                int nr = r + p.first;
                int nc = c + p.second;

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({ {nr,nc}, t+1 });
                    vis[nr][nc] = 1;
                    freshCount--;
                }
            }
        }

        if(freshCount != 0) return -1;

        return time;
    }
};