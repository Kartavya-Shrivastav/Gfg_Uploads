#include <bits/stdc++.h>
using namespace std;

// Problem: Second Best Minimum Spanning Tree
// Approach: Modified Kruskal's Algorithm with DSU

// Steps:
// 1. Sort all edges based on their weights.
// 2. Use DSU to find the Minimum Spanning Tree (MST) and keep track of the edges used.
// 3. For each edge in the MST, try to find an alternative MST by excluding that edge and including other edges.
// 4. Keep track of the second minimum weight found during this process.
// 5. Return the second minimum weight if found, otherwise return -1.

// Time Complexity: O(E log E + E * (E + V)) where E is the number of edges and V is the number of vertices
// Space Complexity: O(V) for the DSU structure

class Solution {
  public:
    struct DSU{
        vector<int>parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)parent[i]=i;
        }
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
        }
        void unite(int a,int b){
            a=find(a);b=find(b);
            if(a!=b){
                if(size[a]<size[b])swap(a,b);
                parent[b]=a;
                size[a]+=size[b];
            }
        }
        bool sameSet(int a,int b){
            return find(a)==find(b);
        }
        int getsize(int a){
            int pa=find(a);
            return size[pa];
            
        }
    };
    int secondMST(int n, vector<vector<int>> &edges) {
        DSU obj(n);
        int num_edges=edges.size();
        sort(edges.begin(),edges.end(),[](vector<int>&e1,vector<int>&e2){
            if(e1[2]!=e2[2])return e1[2]<e2[2];
            return e1<e2;
        });
        int best=0,cnt=0;
        vector<int>picked_edges;
        for(int i=0;i<num_edges;i++){
            if(cnt==n-1)break;
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if(obj.sameSet(u,v))continue;
            picked_edges.push_back(i);
            obj.unite(u,v);
            cnt++;best+=w;
        }
        int second_best=INT_MAX;
        for(auto j:picked_edges){
            DSU obj2(n);
            int ans=0;cnt=0;
            for(int i=0;i<num_edges;i++){
                if(cnt==n-1)break;
                int u=edges[i][0],v=edges[i][1],w=edges[i][2];
                if(obj2.sameSet(u,v) or i==j)continue; //imp
                obj2.unite(u,v);
                ans+=w;cnt++;
            }
            if(cnt==n-1 and ans>best)second_best=min(second_best,ans);
        }
        return second_best==INT_MAX?-1:second_best;
    }
};