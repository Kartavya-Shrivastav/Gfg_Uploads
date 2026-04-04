#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a directed graph represented as an array of edges, where each edge is defined as a pair of vertices (u, v) indicating a directed edge from vertex u to vertex v, find the length of the longest cycle in the graph. If there are no cycles, return -1.
Approach: To solve this problem, we can use a depth-first search (DFS) approach to detect cycles in the directed graph. We will maintain a visited array to keep track of the nodes we have visited during our DFS traversal. If we encounter a node that is currently being visited (i.e., it is in the recursion stack), it means we have found a cycle. We can then calculate the length of this cycle by taking the difference between the current time and the time when we first visited that node.

Steps:
1. Create an array 'next' of size V to store the next vertex for each vertex based on the edges provided. Initialize all values to -1.
2. Create a visited array 'vis' of size V to keep track of the visit time for each vertex. Initialize all values to -1.
3. Initialize a variable 'ans' to store the length of the longest cycle found, and a variable 'time' to keep track of the visit time during DFS.
4. Iterate through each vertex from 0 to V-1:
    - If the vertex has already been visited (i.e., vis[i] != -1), skip it.
    - Otherwise, start a DFS traversal from this vertex:
        a. Set the start time for this traversal to the current time.
        b. While the current node is not -1 and has not been visited:
            i. Mark the current node as visited with the current time.
            ii. Move to the next node using the 'next' array.
        c. If we encounter a node that has already been visited and its visit time is greater than or equal to the start time, it means we have found a cycle. Calculate the length of this cycle and update 'ans' if it is longer than the previously recorded longest cycle.  
5. After iterating through all vertices, return the value of 'ans'. If no cycles were found, 'ans' will remain -1.

Time Complexity: O(V) where V is the number of vertices in the graph, as we will visit each vertex at most once during the DFS traversal.
Space Complexity: O(V) for the visited array and the recursion stack in the worst case when the graph is a single long chain. In general, the space complexity is O(V).
*/

class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> next(V, -1);
        for (auto& e : edges) next[e[0]] = e[1];
        
        vector<int> vis(V, -1);
        int ans = -1, time = 0;
        
        for (int i = 0; i < V; ++i) {
            if (vis[i] != -1) continue;
            
            int start = time;
            int node = i;
            
            while (node != -1 && vis[node] == -1) {
                vis[node] = time++;
                node = next[node];
            }
            
            if (node != -1 && vis[node] >= start) {
                ans = max(ans, time - vis[node]);
            }
        }
        
        return ans;
    }
};

