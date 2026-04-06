#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a directed graph with V vertices and a list of edges where each edge is represented as a triplet [u, v, wt] indicating a directed edge from vertex u to vertex v with weight wt, find the number of different ways to reach from vertex 0 to vertex V-1 in the shortest time.
Approach: This problem can be solved using a modified Dijkstra's algorithm. We will maintain a priority queue to explore the vertices based on the shortest time to reach them. Along with the shortest time, we will also keep track of the number of ways to reach each vertex in that shortest time.

Steps:
1. Create an adjacency list to represent the graph, where each vertex points to a list of pairs (neighbor, weight).
2. Initialize a priority queue to store pairs of (current time, vertex) and start with the source vertex (0) with time 0.
3. Create a vector to store the shortest time to reach each vertex, initialized to INT_MAX except for the source vertex which is initialized to 0.
4. Create a vector to store the number of ways to reach each vertex, initialized to 0 except for the source vertex which is initialized to 1.
5. While the priority queue is not empty:
    a. Pop the vertex with the smallest time from the priority queue.
    b. If the current time is greater than the recorded shortest time for that vertex, continue to the next iteration.
    c. For each neighbor of the current vertex, calculate the new time to reach that neighbor through the current vertex.
    d. If the new time is less than the recorded shortest time for that neighbor, update the shortest time and set the number of ways to reach that neighbor equal to the number of ways to reach the current vertex.
    e. If the new time is equal to the recorded shortest time for that neighbor, add the number of ways to reach the current vertex to the number of ways to reach that neighbor.

Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices, due to the priority queue operations in Dijkstra's algorithm.
Space Complexity: O(V + E) for the adjacency list and the vectors used to store shortest times and ways to reach each vertex. The priority queue can hold at most O(V) elements in the worst case, so it also contributes O(V) to the space complexity. Overall, the space complexity is O(V + E).
*/

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e: edges){
            int u=e[0], v=e[1], wt=e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }        
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> time(V, INT_MAX);
        time[0] = 0;
        
        vector<int> waysToReach(V, 0);
        waysToReach[0] = 1;
        
        while(!pq.empty()){
            auto [currTime, node] = pq.top();
            pq.pop();
            
            if(currTime > time[node]) continue;
            
            for(auto &[nbr, edgeWt]: adj[node]){
                if(currTime + edgeWt < time[nbr]){
                    time[nbr] = currTime + edgeWt;
                    pq.push({time[nbr], nbr});
                    waysToReach[nbr] = waysToReach[node];
                }
                
                else if(currTime + edgeWt == time[nbr]){
                    waysToReach[nbr] += waysToReach[node];
                }
            }
        }
        
        return waysToReach[V-1];
    }
};