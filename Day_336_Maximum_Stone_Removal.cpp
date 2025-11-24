#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Stone Removal
// Approach: Disjoint Set Union (DSU)

// Steps:
// 1. Represent each stone as a node in a graph.
// 2. Use DSU to group stones that share the same row or column.
// 3. Count the number of connected components in the graph.
// 4. The maximum number of stones that can be removed is the total number of stones minus the number of connected components.
// 5. Return the result.

// Time Complexity: O(N * α(N)) where N is the number of stones and α is the inverse Ackermann function
// Space Complexity: O(N) for the DSU structure and maps

class Solution {
  public:
    int find_par(vector<int>&par, int x)
    {
        if(par[x] == x)return x;
        return par[x] = find_par(par, par[x]);
    }
    void merge_nodes(vector<int>&par, int x, int y)
    {
        x = find_par(par, x);
        y = find_par(par, y);
        par[x] = y;
    }
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
         int v = stones.size();
         vector<int>par(v, 0);
         map<int, vector<int>>row, col;
         for(int i = 0; i < v; i++)par[i] = i;
         int node = 0;
         for(auto &stone : stones)
         {
             int i = stone[0], j = stone[1];
             row[i].push_back(node);
             col[j].push_back(node);
             node++;
         }
         for(auto &r : row)
         {
             auto nodes = r.second;
             int node = nodes[0];
             for(auto &next : nodes)
             {
                 merge_nodes(par, node, next);
             }
         }
         for(auto &r : col)
         {
             auto nodes = r.second;
             int node = nodes[0];
             for(auto &next : nodes)
             {
                 merge_nodes(par, node, next);
             }
         }
         map<int, int>freq;
         for(int i = 0; i < v; i++)par[i] = find_par(par, i);
        //  for(auto &it : par)
        //  {
        //      freq[it]++;
        //  }
         int ans = 0;
        //  for(auto &m : freq)
        //  {
        //      int cnt = m.second;
        //      ans += (cnt - 1);
        //  }
        set<int>st;
        for(auto &it : par)
        {
            st.insert(it);
        }
        ans = v - st.size();
        
         return ans;
         
    }
};