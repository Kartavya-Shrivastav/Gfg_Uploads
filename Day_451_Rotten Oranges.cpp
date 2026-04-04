#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a grid representing a box of oranges, where each cell can be empty (0), contain a fresh orange (1), or contain a rotten orange (2), determine the minimum time required for all fresh oranges to become rotten. If it is impossible for all fresh oranges to become rotten, return -1.
Approach: We can use a breadth-first search (BFS) approach to solve this problem. We will start by enqueueing all the rotten oranges along with their initial time (0). Then, we will process each rotten orange in the queue and attempt to rot its adjacent fresh oranges. For each adjacent fresh orange that becomes rotten, we will enqueue it with the time incremented by 1. We will also keep track of the number of fresh oranges remaining. If at the end of the BFS, there are still fresh oranges left, we will return -1. Otherwise, we will return the maximum time taken to rot all oranges.

Steps:
1. Initialize a queue to store the positions of rotten oranges and their corresponding time.
2. Initialize a counter to keep track of the number of fresh oranges.   
3. Iterate through the grid to find all rotten oranges and enqueue their positions and time (0). Also, count the number of fresh oranges.
4. Define the possible directions for adjacent cells (up, right, down, left).
5. While the queue is not empty, do the following:
    - Dequeue an element to get the current position and time.
    - For each of the four possible directions, calculate the new position.
    - If the new position is within bounds, has not been visited, and contains a fresh orange, enqueue it with time incremented by 1 and mark it as visited. Also, decrement the fresh orange counter.
6. After the BFS, if there are still fresh oranges left, return -1. Otherwise, return the maximum time taken to rot all oranges.    

Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the grid, as we may need to process each cell at most once.
Space Complexity: O(n*m) for the queue and the visited array in the worst case when all oranges are rotten.
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