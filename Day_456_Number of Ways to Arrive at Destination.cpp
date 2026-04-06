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