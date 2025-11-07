#include <bits/stdc++.h>
using namespace std;

// Problem: Given a directed graph with V vertices and E edges, identify all the safe nodes in the graph. A safe node is defined as a node from which every possible path leads to a terminal node (a node with no outgoing edges).
// Approach: Use a modified topological sort on the reverse graph to identify safe nodes. Nodes with zero indegree in the reversed graph are safe nodes.

// Steps:
// 1. Construct the reverse graph and calculate the indegree of each node.  
// 2. Initialize a queue with all nodes having zero indegree.  
// 3. Perform a BFS-like traversal, reducing the indegree of neighboring nodes and adding them to the queue when their indegree becomes zero.
// 4. Collect and return all nodes that were processed in this manner as they are safe nodes.

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E) for storing the reverse graph and indegree array.

class Solution {
  public:
     vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjRev[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> safe;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
           int node=q.front();
           q.pop();
           safe.push_back(node);
           for(auto it:adjRev[node]){
               indegree[it]--;
               if(indegree[it]==0)q.push(it);
           }
        }
        return safe;
    }
};