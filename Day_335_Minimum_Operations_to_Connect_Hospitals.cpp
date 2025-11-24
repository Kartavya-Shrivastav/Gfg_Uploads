#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Operations to Connect Hospitals
// Approach: Disjoint Set Union (DSU)

// Steps:
// 1. Initialize a Disjoint Set Union (DSU) structure to manage connected components
// 2. Iterate through each edge and perform union operations to connect hospitals
// 3. Count the number of connected components
// 4. Calculate the minimum operations required to connect all hospitals which is (number of components - 1)
// 5. If the number of edges is less than V-1, return -1 as it's impossible to connect all hospitals with the given edges
// 6. Return the result

// Time Complexity: O(E * α(V)) where E is the number of edges, V is the number of vertices, and α is the inverse Ackermann function
// Space Complexity: O(V) for the DSU structure

class DisjointSet{
    vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++) {
                parent[i]=i;
                size[i]=1;
            }
        }
        int find(int node){
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }
        bool unionBySize(int u, int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv) return false;
            if(size[pu]>size[pv]){
                size[pu]+=size[pv];
                parent[pv]=pu;
            } else {
                size[pv]+=size[pu];
                parent[pu]=pv;
            }
            return true;
        }
        int countComp(){
            int c=0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]==i) c++;
            }
            return c;
        }
};
class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int e=edges.size();
        if(e<V-1) return -1;
        DisjointSet dsu(V);
        for(auto ed:edges){
            dsu.unionBySize(ed[0],ed[1]);
        }
        int ct=dsu.countComp();
        return ct-1;
    }
};