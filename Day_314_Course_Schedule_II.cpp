#include <bits/stdc++.h>
using namespace std;

// Problem: Given an undirected graph, find the length of the shortest cycle in the graph. If there is no cycle, return -1.
// Approach: Use Depth-First Search (DFS) to explore the graph and track the depth of each node. If we encounter a previously visited node that is not the parent of the current node, we have found a cycle. The length of the cycle can be calculated using the depth information.

// Steps:
// 1. Construct the adjacency list from the given edges.
// 2. Initialize a visited array to keep track of the depth of each node during DFS
// 3. For each unvisited node, perform DFS. If a cycle is detected, update the minimum cycle length.
// 4. Return the length of the shortest cycle found, or -1 if no cycle exists.

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V) for the adjacency list and the visited array.

class Solution {
  public:
  void dfs(int node ,vector<vector<int>>&adj , vector<int>& vis , int prev , int &ans){
        vis[node] = prev;
        for(auto i: adj[node]){
            if(vis[i] == 0)dfs(i , adj , vis , prev+1 , ans);
            else if(vis[node] - vis[i] >1){
                if(ans ==-1)ans = vis[node] - vis[i] +1;
                else ans = min (ans , vis[node] - vis[i] +1);
            }
            else if(vis[node] +1 < vis[i] )dfs(i , adj , vis , prev+1 ,ans );
        }
  }
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int ans = -1;
        vector<vector<int>>adj(V);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(V , 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0 && adj.size()>0)dfs(i, adj , vis, 1, ans);
        }
        return ans;
        
    }
};