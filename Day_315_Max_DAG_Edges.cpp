class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> v(V , vector<int>(V,-1));
        
        for(int i = 0 ; i < V ; i++){
            v[i][i] = 1;
        }
        for(auto ch : edges){
            int a = ch[0];
            int b = ch[1];
            
            v[a][b] = 1;
            v[b][a] = 1;
        }
        
        int c = 0;
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(v[i][j]==-1){
                    v[i][j]=1;
                    c++;
                    v[j][i] = 1;
                }
            }
        }
        
        return c;
    }
};