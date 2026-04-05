#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an undirected graph with V vertices and a list of edges, find all the minimum height roots of the graph. A minimum height root is a vertex that, when chosen as the root of the tree formed by the graph, results in the minimum possible height of the tree.
Approach: To find the minimum height roots of the graph, we can use a breadth-first search (BFS) approach. The idea is to start from all the leaf nodes (vertices with degree 1) and iteratively remove them from the graph until we are left with one or two vertices, which will be the minimum height roots.

Steps:
1. Create an adjacency list to represent the graph and a degree array to keep track of the degree of each vertex.
2. Initialize a queue and enqueue all the leaf nodes (vertices with degree 1).  
3. While the queue is not empty:
    a. Clear the result vector to store the current level of nodes.
    b. Get the size of the queue, which represents the number of nodes at the current level.
    c. For each node in the current level:
        i. Dequeue a node and add it to the result vector.
        ii. For each neighbor of this node, decrement its degree by 1. If any neighbor's degree becomes 1, enqueue it as it will become a leaf node in the next iteration.
4. After the loop ends, the result vector will contain one or two vertices, which are the minimum height roots of the graph.

Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges, as we will visit each vertex and edge at most once during the BFS traversal.
Space Complexity: O(V + E) for the adjacency list and the degree array, and O(V) for the queue in the worst case when all vertices are leaf nodes. In general, the space complexity is O(V + E).
*/

class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        
        vector<int> deg(V, 0);
        vector<vector<int>> adj(V);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ++deg[e[0]];
            ++deg[e[1]];
        }
        
        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (deg[i] == 1) q.push(i);
        
        vector<int> res;
        
        while (!q.empty()) {
            res.clear();
            int sz = q.size();
            
            while (sz--) {
                int u = q.front(); q.pop();
                res.push_back(u);
                
                for (int v : adj[u])
                    if (--deg[v] == 1) q.push(v);
            }
        }
        
        return res;
    }
};