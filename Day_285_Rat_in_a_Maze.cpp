#include <bits/stdc++.h>
using namespace std;

// Problem: Rat in a Maze
// Approach: We can use backtracking to explore all possible paths from the top-left corner to the bottom-right corner of the maze. We will keep track of visited cells to avoid cycles and only move to cells that are open (1).

// Steps:
// 1. Define a recursive function that explores all four possible directions (down, left, right, up) from the current cell.
// 2. When we reach the bottom-right corner, add the current path to the result list.
// 3. Use backtracking to mark cells as visited and unvisited as we explore different paths.
// 4. Finally, return the list of all valid paths.

// Time Complexity: O(4^(n^2)) in the worst case (for exploring all possible paths in an n x n maze)
// Space Complexity: O(n^2) for the recursion stack and O(m) for storing the results

class Solution {
  public:
    void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<int>> &vis) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = 1;
        
        if(i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1) {
            solve(i + 1, j, maze, n, ans, path + "D", vis);
        }
        
        if(j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1) {
            solve(i, j - 1, maze, n, ans, path + "L", vis);
        }
        
        if(j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1) {
            solve(i, j + 1, maze, n, ans, path + "R", vis);
        }
        
        if(i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
            solve(i - 1, j, maze, n, ans, path + "U", vis);
        }
        
        vis[i][j] = 0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if(maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
            solve(0, 0, maze, n, ans, "", vis);
        }
        
        return ans;
    }
};