#include <bits/stdc++.h>
using namespace std;

// Problem: Given a directed acyclic graph (DAG) with V vertices and E edges, determine the maximum number of edges that can be added to the graph without creating a cycle.
// Approach: The maximum number of edges in a DAG with V vertices is V*(V-1)/2. The number of edges that can be added is the difference between this maximum and the current number of edges E.

// Steps:
// 1. Calculate the maximum number of edges in a complete graph with V vertices.
// 2. Subtract the current number of edges E from this maximum to get the number of edges that can be added.
// 3. Return this value.

// Time Complexity: O(V^2) due to the adjacency matrix representation and checking for existing edges.
// Space Complexity: O(V^2) for the adjacency matrix.

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> v(V , vector<int>(V,-1));
        
        for(int i = 0 ; i < V ; i++){
            v[i][i] = 1;
        }
        for(auto ch : edges){
            int a = ch[0];
            int b = ch[1];
            
            v[a][b] = 1;
            v[b][a] = 1;
        }
        
        int c = 0;
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(v[i][j]==-1){
                    v[i][j]=1;
                    c++;
                    v[j][i] = 1;
                }
            }
        }
        
        return c;
    }
};