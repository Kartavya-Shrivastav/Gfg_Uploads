#include <bits/stdc++.h>
using namespace std;

// Problem: Determine if all prerequisite tasks can be completed without cyclic dependencies
// Approach: Use Depth First Search (DFS) to detect cycles in the prerequisite graph.

// Steps:
// 1. Create an adjacency list from the prerequisite pairs.
// 2. Use DFS to traverse the graph and detect cycles.
// 3. Return true if no cycles are found, otherwise return false.
// 4. Implement the DFS function to check for cycles.
// 5. Call the DFS function for each unvisited node.

// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
    private:
    bool getAns(int node, vector<bool> &path, vector<int> adj[], vector<bool> &vis){
        path[node]= true;
        vis[node]= true;
        for (auto i: adj[node]){
            if(path[i]){
                return true;
            }
            if(vis[i]){
                continue;
            }
            bool next= getAns(i, path, adj, vis);
            if(next){
                return true;
            }
        }
        path[node]= false;
        return false;
    }
    
    public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        for(auto i: prerequisites){
            auto u= i.first;
            auto v= i.second;
            adj[v].push_back(u);
        }
        vector<bool> vis(N, false);
        vector<bool> path(N, false);
        for (int i=0; i<N; i++){
            if(!vis[i]){
                if(getAns(i, path, adj, vis)){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};