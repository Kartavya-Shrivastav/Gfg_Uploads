#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given a list of coordinates of houses in a city, find the minimum cost to connect all the houses with roads. The cost to connect two houses is the Manhattan distance between them.
Approach: We can model the problem as a graph where each house is a node and the edges between them represent the cost to connect them (the Manhattan distance). We can then use Prim's algorithm to find the minimum spanning tree of this graph, which will give us the minimum cost to connect all the houses.

Steps:
1. Create an adjacency list to represent the graph, where each node (house) has a list of pairs (neighboring house, cost to connect).
2. Use a priority queue to implement Prim's algorithm, starting from the first house.
3. Keep track of the visited nodes to avoid cycles and ensure we only add edges that connect new nodes to the growing spanning tree.    
4. Sum the costs of the edges included in the spanning tree to get the total minimum cost.
5. Return the total minimum cost.

Time Complexity: O(n^2 log n) due to the construction of the graph and the priority queue operations in Prim's algorithm.
Space Complexity: O(n^2) for storing the graph and O(n) for the priority queue and visited array.
*/

class Solution {
  public:
  
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size();
        
        vector<vector<pair<int, int>>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=houses[i][0];
                int y1=houses[i][1];
                int x2=houses[j][0];
                int y2=houses[j][1];
                int d=abs(x2-x1)+abs(y2-y1);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        vector<bool>inMST(n, 0);

        pq.push({0, 0});

        int ans=0;

        while(!pq.empty()){
            auto [wt, node]=pq.top();
            pq.pop();

            if(inMST[node]) continue;

            inMST[node]=true;
            ans+=wt;

            for(auto &it:adj[node]){
                if(!inMST[it.first]){
                    pq.push({it.second, it.first});
                }               
            }
        }

        return ans;        
    }
};