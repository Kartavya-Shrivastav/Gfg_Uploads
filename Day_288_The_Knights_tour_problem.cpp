#include <bits/stdc++.h>
using namespace std;

// Problem: The Knight's Tour Problem
// Approach: We can use backtracking to explore all possible moves of the knight on the chessboard. 
//           We will keep track of the visited cells to avoid cycles and ensure that we visit each cell exactly once.

// Steps:
// 1. Define a recursive function that explores all eight possible moves of the knight from the current cell.
// 2. When we have visited all cells (i.e., the count of visited cells equals n*n), we store the current board configuration as a valid solution.
// 3. Use backtracking to mark cells as visited and unvisited as we explore different paths.
// 4. Finally, return the board configuration if a solution is found.

// Time Complexity: O(8^(n^2)) in the worst case (for exploring all possible paths in an n x n chessboard)
// Space Complexity: O(n^2) for the recursion stack and O(n^2) for storing the board configuration
class Solution {
public:
vector<vector<int>>ans;
bool flag=false;
int arr[8]={-1,1,-2,-2,-1,1,2,2};
int brr[8]={-2,-2,-1,1,2,2,-1,1};
int n;
   void solve(int i,int j,vector<vector<int>>&vis,int sum)
   {  
       if(flag)
       {
       return;
       }
      if(sum==n*n)
       {
          ans=vis;
          flag=true;
          return ;
       }
      for(int x=0;x<8;x++)
       {
          int p=i+arr[x];
          int q=j+brr[x];
          if(p>=0 && q>=0 && p<n && q<n && vis[p][q]==-1)
           {
              vis[p][q]=sum;
              solve(p,q,vis,sum+1);
              vis[p][q]=-1;
            }
        }
   }
    vector<vector<int>> knightTour(int m) {
        // code here
        n=m;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        vis[0][0]=0;
        solve(0,0,vis,1);
        return ans;
    }
};