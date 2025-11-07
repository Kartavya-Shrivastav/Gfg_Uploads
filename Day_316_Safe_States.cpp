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