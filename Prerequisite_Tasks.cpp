class Solution {
    private:
    bool getAns(int node, vector<bool> &path, vector<int> adj[], vector<bool> &vis){
        path[node]= true;
        vis[node]= true;
        for (auto i: adj[node]){
            if(path[i]){
                return true;
            }
            if(vis[i]){
                continue;
            }
            bool next= getAns(i, path, adj, vis);
            if(next){
                return true;
            }
        }
        path[node]= false;
        return false;
    }
    
    public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        for(auto i: prerequisites){
            auto u= i.first;
            auto v= i.second;
            adj[v].push_back(u);
        }
        vector<bool> vis(N, false);
        vector<bool> path(N, false);
        for (int i=0; i<N; i++){
            if(!vis[i]){
                if(getAns(i, path, adj, vis)){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};