#include<bits/stdc++.h>
using namespace std;
// This code defines a Solution class with a method to count the number of paths from a source vertex to a destination vertex in a directed graph represented by edges.

class Solution {
    public:
        // Helper function to perform DFS and count paths from curr to dest
        int dfs(int curr, int dest, vector<vector <int>>& adj, vector <int>& vis){
                // If current node is the destination, one path is found
                if(curr == dest) return 1;
                // If already computed, return memoized result
                if(vis[curr] != -1) return vis[curr];
                
                int cnt = 0;
                // Explore all neighbors
                for(int nbr: adj[curr]){
                        cnt += dfs(nbr, dest, adj, vis);
                }
                
                // Memoize and return the count
                return vis[curr] = cnt;
        }

        // Main function to count number of paths from src to dest
        int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
                vector<vector <int>> adj(V); // Adjacency list
                vector <int> vis(V, -1);     // Memoization array
                
                // Build the adjacency list from edge list
                for(auto edge: edges){
                        int u = edge[0];
                        int v = edge[1];
                        adj[u].push_back(v);
                }
                
                // Start DFS from source
                return dfs(src, dest, adj, vis);
        }
};